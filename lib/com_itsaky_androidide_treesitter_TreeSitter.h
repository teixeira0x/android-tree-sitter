/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_itsaky_androidide_treesitter_TreeSitter */

#ifndef _Included_com_itsaky_androidide_treesitter_TreeSitter
#define _Included_com_itsaky_androidide_treesitter_TreeSitter
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    nodeChildCount
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;)I
 */
JNIEXPORT jint JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_nodeChildCount
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    nodeChild
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;I)Lcom/itsaky/androidide/treesitter/TSNode;
 */
JNIEXPORT jobject JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_nodeChild
  (JNIEnv *, jclass, jobject, jint);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    nodeEndByte
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;)I
 */
JNIEXPORT jint JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_nodeEndByte
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    nodeStartByte
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;)I
 */
JNIEXPORT jint JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_nodeStartByte
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    nodeStartPoint
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;)Lcom/itsaky/androidide/treesitter/TSPoint;
 */
JNIEXPORT jobject JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_nodeStartPoint
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    nodeEndPoint
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;)Lcom/itsaky/androidide/treesitter/TSPoint;
 */
JNIEXPORT jobject JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_nodeEndPoint
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    nodeString
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_nodeString
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    nodeType
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_nodeType
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    nodeIsNamed
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_nodeIsNamed
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    nodeIsMissing
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_nodeIsMissing
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    nodeIsExtra
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_nodeIsExtra
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    nodeHasError
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_nodeHasError
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    parserNew
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_parserNew
  (JNIEnv *, jclass);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    parserDelete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_parserDelete
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    parserSetLanguage
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_parserSetLanguage
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    parserParseBytes
 * Signature: (J[BII)J
 */
JNIEXPORT jlong JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_parserParseBytes
  (JNIEnv *, jclass, jlong, jbyteArray, jint, jint);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    parserIncrementalParseBytes
 * Signature: (JJ[BII)J
 */
JNIEXPORT jlong JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_parserIncrementalParseBytes
  (JNIEnv *, jclass, jlong, jlong, jbyteArray, jint, jint);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    treeCursorNew
 * Signature: (Lcom/itsaky/androidide/treesitter/TSNode;)J
 */
JNIEXPORT jlong JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_treeCursorNew
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    treeCursorCurrentTreeCursorNode
 * Signature: (J)Lcom/itsaky/androidide/treesitter/TSTreeCursorNode;
 */
JNIEXPORT jobject JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_treeCursorCurrentTreeCursorNode
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    treeCursorCurrentFieldName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_treeCursorCurrentFieldName
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    treeCursorCurrentNode
 * Signature: (J)Lcom/itsaky/androidide/treesitter/TSNode;
 */
JNIEXPORT jobject JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_treeCursorCurrentNode
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    treeCursorDelete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_treeCursorDelete
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    treeCursorGotoFirstChild
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_treeCursorGotoFirstChild
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    treeCursorGotoNextSibling
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_treeCursorGotoNextSibling
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    treeCursorGotoParent
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_treeCursorGotoParent
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    treeEdit
 * Signature: (JLcom/itsaky/androidide/treesitter/TSInputEdit;)V
 */
JNIEXPORT void JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_treeEdit
  (JNIEnv *, jclass, jlong, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    treeDelete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_treeDelete
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    treeCopy
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_treeCopy
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    treeRootNode
 * Signature: (J)Lcom/itsaky/androidide/treesitter/TSNode;
 */
JNIEXPORT jobject JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_treeRootNode
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_itsaky_androidide_treesitter_TreeSitter
 * Method:    tsQueryNew
 * Signature: (JLjava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_com_itsaky_androidide_treesitter_TreeSitter_tsQueryNew
  (JNIEnv *, jclass, jlong, jstring);

#ifdef __cplusplus
}
#endif
#endif
