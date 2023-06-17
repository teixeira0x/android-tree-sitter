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

package com.itsaky.androidide.treesitter;

import java.nio.charset.StandardCharsets;
import java.util.regex.Pattern;

/**
 * A tree-sitter language.
 *
 * @author Akash Yadav
 */
public class TSLanguage extends TSNativeObject {

  private static final Pattern LANG_NAME = Pattern.compile("^[a-zA-Z_]\\w*$");

  /**
   * The pointer to the library handle if this language was loaded using
   * {@link TSLanguage#loadLanguage(String, String)}.
   */
  private long libHandle;

  /**
   * Create a new {@link TSLanguage} instance with the given pointer.
   *
   * @param pointer The pointer to the language implementation in C.
   */
  public TSLanguage(long pointer) {
    this(new long[]{pointer, 0});
  }

  private TSLanguage(long[] pointers) {
    super(0);

    if (pointers == null) {
      throw new IllegalArgumentException("Cannot create TSLanguage from null pointers");
    }

    if (pointers.length != 2) {
      throw new IllegalArgumentException("There must be exactly 2 elements the pointers array");
    }

    this.pointer = pointers[0];
    this.libHandle = pointers[1];
  }

  /**
   * Get the number of distinct node types in the language.
   */
  public int getSymbolCount() {
    checkAccess();
    return Native.symCount(this.pointer);
  }

  public int getFieldCount() {
    checkAccess();
    return Native.fldCount(this.pointer);
  }

  public String getSymbolName(int symbol) {
    checkAccess();
    return Native.symName(this.pointer, symbol);
  }

  public int getSymbolForTypeString(String name, boolean isNamed) {
    checkAccess();
    final var bytes = name.getBytes(StandardCharsets.UTF_8);
    return Native.symForName(this.pointer, bytes, bytes.length, isNamed);
  }

  public String getFieldNameForId(int id) {
    checkAccess();
    return Native.fldNameForId(this.pointer, id);
  }

  public int getFieldIdForName(String name) {
    checkAccess();
    final var bytes = name.getBytes(StandardCharsets.UTF_8);
    return Native.fldIdForName(this.pointer, bytes, bytes.length);
  }

  public TSSymbolType getSymbolType(int symbol) {
    checkAccess();
    return TSSymbolType.forId(Native.symType(this.pointer, symbol));
  }

  public int getLanguageVersion() {
    checkAccess();
    return Native.langVer(this.pointer);
  }

  @Override
  public void close() {
    if (this.libHandle != 0) {
      Native.dlclose(this.libHandle);
      this.libHandle = 0;
    }

    super.close();
  }

  @Override
  protected void closeNativeObj() {
    // no-op
  }

  /**
   * Loads the tree-sitter language and returns an instance of {@link TSLanguage}. This method will
   * load the library using <code>dlopen</code> and keep a reference to the library handle as long
   * the {@link TSLanguage#close()} is not called.
   *
   * @param libraryPath The absolute path to the shared library.
   * @param lang        The name of the language, without {@code tree-sitter-} prefix (e.g. 'java',
   *                    'kotlin', etc).
   * @return The {@link TSLanguage} instance for the given language name, or <code>null</code> if
   * the language cannot be loaded.
   * @throws IllegalArgumentException If the given language name is invalid.
   */
  public static TSLanguage loadLanguage(String libraryPath, String lang) {
    validateLangName(lang);

    final long[] pointers = Native.loadLanguage(libraryPath, "tree_sitter_" + lang);
    if (pointers == null) {
      return null;
    }

    return new TSLanguage(pointers);
  }

  private static void validateLangName(String lang) {
    final var matcher = LANG_NAME.matcher(lang);
    if (!matcher.matches()) {
      throw new IllegalArgumentException("Invalid language name: " + lang);
    }
  }

  private static class Native {

    private static native int symCount(long ptr);

    private static native int fldCount(long ptr);

    private static native int symForName(long ptr, byte[] name, int length, boolean named);

    private static native String symName(long lngPtr, int sym);

    private static native String fldNameForId(long ptr, int id);

    private static native int fldIdForName(long ptr, byte[] name, int length);

    private static native int symType(long ptr, int sym);

    private static native int langVer(long ptr);

    private static native long[] loadLanguage(String sharedLib, String func);

    private static native void dlclose(long libhandle);
  }
}