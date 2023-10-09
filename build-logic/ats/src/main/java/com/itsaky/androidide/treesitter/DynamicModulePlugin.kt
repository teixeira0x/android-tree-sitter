/*
 *  This file is part of android-tree-sitter.
 *
 *  android-tree-sitter library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  android-tree-sitter library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *  along with android-tree-sitter.  If not, see <https://www.gnu.org/licenses/>.
 */

package com.itsaky.androidide.treesitter

import com.google.gson.Gson
import com.google.gson.reflect.TypeToken
import org.gradle.api.Plugin
import org.gradle.api.initialization.Settings
import java.io.File
import java.io.FileNotFoundException

/**
 * Dynamically creates and adds the grammar project modules to the build.
 *
 * @author Akash Yadav
 */
@Suppress("unused")
class DynamicModulePlugin : Plugin<Settings> {

  override fun apply(target: Settings) {
    target.run {
      val rootDir = target.rootDir
      val grammarsFile = rootDir.resolve("grammars/grammars.json")
      if (!grammarsFile.exists()) {
        throw FileNotFoundException("grammars.json file does not exist")
      }

      val type =
        TypeToken.getParameterized(List::class.java, TsGrammar::class.java)
      val grammars: List<TsGrammar> =
        Gson().fromJson(grammarsFile.bufferedReader(), type.type)

      for (grammar in grammars) {
        val moduleDir = rootDir.resolve("grammar-modules/${grammar.name}")
          .also { it.mkdirs() }
        generateGrammarModule(grammar, moduleDir, rootDir)

        val moduleName = "tree-sitter-${grammar.name}"
        include(moduleName)
        project(":${moduleName}").projectDir = moduleDir
      }
    }
  }

  private fun generateGrammarModule(grammar: TsGrammar, moduleDir: File,
                                    rootDir: File
  ) {
    println("Generating module for grammar '${grammar.name}'")
    writeBuildGradle(moduleDir)
    writeLangBinding(grammar, moduleDir)
    writeNative(grammar, moduleDir, rootDir)
  }

  private fun writeNative(grammar: TsGrammar, moduleDir: File, rootDir: File
  ) {
    val cppDir = File(moduleDir, "src/main/cpp/").also { it.mkdirs() }
    writeCmakeLists(grammar, cppDir, rootDir)
    writeJniImpl(grammar, cppDir)

    File(cppDir, ".gitignore").writeText("/host-build")
  }

  private fun writeJniImpl(grammar: TsGrammar, cppDir: File) {
    val file = File(cppDir, "tree-sitter-${grammar.name}.cpp")
    file.writeText(grammar.jniImplSrc().autoGenerated())
  }

  private fun writeCmakeLists(grammar: TsGrammar, cppDir: File, rootDir: File
  ) {
    val file = File(cppDir, "CMakeLists.txt")
    file.writeText(grammar.cmakeListsSrc(rootDir).autoGenerated(comment = "##"))
  }

  private fun writeLangBinding(grammar: TsGrammar, moduleDir: File) {
    val file = File(moduleDir,
      "src/main/java/com/itsaky/androidide/treesitter/${grammar.name}/TSLanguage${grammar.capitalizedName()}.java")
    file.parentFile.mkdirs()
    file.writeText(grammar.langBindingSrc().autoGenerated())
  }

  private fun writeBuildGradle(moduleDir: File) {
    val file = File(moduleDir, "build.gradle")
    file.writeText(buildGradleSrc().autoGenerated())
  }
}

private fun TsGrammar.jniImplSrc(): String = """
$license

#include <jni.h>
#include <tree_sitter/api.h>

extern "C" TSLanguage *tree_sitter_${name}();

extern "C"
JNIEXPORT jlong JNICALL
Java_com_itsaky_androidide_treesitter_${name}_TSLanguage${capitalizedName()}_00024Native_getInstance(JNIEnv *env,
                                                                                  jclass clazz) {
    return (jlong) tree_sitter_${name}();
}
""".trimIndent()

private fun TsGrammar.cmakeListsSrc(rootDir: File,
                                    grammarDir: File = File(rootDir,
                                      "grammars/$name")
): String {
  if (!grammarDir.exists()) {
    throw FileNotFoundException(
      "Source directory for grammar '$name' not found")
  }

  val sources = srcExtra.joinToString(
    separator = "\n        ") { "${grammarDir.absolutePath}/${it}" }
  return """
$cmakeLicense

cmake_minimum_required(VERSION 3.22.1)

project("tree-sitter-$name")

# Set the root project directory
set(PROJECT_DIR ${rootDir.absolutePath})

# Include common configuration
include(${rootDir.absolutePath}/cmake/common-config.cmake)

# This includes the header file for the parser
include_directories(${grammarDir.absolutePath}/src)

# add tree-sitter-java library
add_library(${'$'}{CMAKE_PROJECT_NAME} SHARED
        ${grammarDir.absolutePath}/src/parser.c
        $sources
        tree-sitter-${name}.cpp)
""".trimIndent()
}

private fun TsGrammar.langBindingSrc(): String = """
$license

package com.itsaky.androidide.treesitter.$name;

import com.itsaky.androidide.treesitter.TSLanguage;
import com.itsaky.androidide.treesitter.TSLanguageCache;

/**
 * Tree Sitter for ${capitalizedName()}.
 *
 * @author Akash Yadav
 */
public final class TSLanguage${capitalizedName()} {

  static {
    System.loadLibrary("tree-sitter-$name");
  }

  private TSLanguage${capitalizedName()}() {
    throw new UnsupportedOperationException();
  }

  /**
   * @deprecated Tree Sitter language instances are <code>static const</code> and hence, they do not change. The
   * name of this method is misleading, use {@link TSLanguage${capitalizedName()}#getInstance()} instead.
   */
  @Deprecated
  public static TSLanguage newInstance() {
    return getInstance();
  }
  
  /**
   * Get the instance of the ${capitalizedName()} language.
   *
   * @return The instance of the ${capitalizedName()} language.
   */
  public static TSLanguage getInstance() {
    var language = TSLanguageCache.get("$name");
    if (language != null) {
      return language;
    }

    language = TSLanguage.create("$name", Native.getInstance());
    TSLanguageCache.cache("$name", language);
    return language;
  }

  public static class Native {
    public static native long getInstance();
  }
}
""".trimIndent()

private fun buildGradleSrc(): String = """
$license

plugins {
  id("com.android.library")
  id("com.vanniktech.maven.publish.base")
  id("android-tree-sitter.ts")
  id("android-tree-sitter.ts-grammar")
}
""".trimIndent()

private fun String.autoGenerated(comment: String = "//"): String {
  return "$comment This file is automatically generated. DO NOT EDIT!\n\n$this"
}

private const val license = """
/*
 *  This file is part of android-tree-sitter.
 *
 *  android-tree-sitter library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  android-tree-sitter library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *  along with android-tree-sitter.  If not, see <https://www.gnu.org/licenses/>.
 */
"""

private const val cmakeLicense = """#
#  This file is part of android-tree-sitter.
#
#  android-tree-sitter library is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Lesser General Public
#  License as published by the Free Software Foundation; either
#  version 2.1 of the License, or (at your option) any later version.
#
#  android-tree-sitter library is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  Lesser General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#  along with android-tree-sitter.  If not, see <https://www.gnu.org/licenses/>.
#"""