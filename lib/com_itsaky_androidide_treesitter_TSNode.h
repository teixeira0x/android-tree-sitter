/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_itsaky_androidide_treesitter_TSNode */

#ifndef _Included_com_itsaky_androidide_treesitter_TSNode
#define _Included_com_itsaky_androidide_treesitter_TSNode
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getParent
 * Signature: ()Lcom/itsaky/androidide/treesitter/TSNode;
 */
JNIEXPORT jobject JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getParent
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getChildAt
 * Signature: (I)Lcom/itsaky/androidide/treesitter/TSNode;
 */
JNIEXPORT jobject JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getChildAt
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getNamedChildAt
 * Signature: (I)Lcom/itsaky/androidide/treesitter/TSNode;
 */
JNIEXPORT jobject JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getNamedChildAt
  (JNIEnv *, jobject, jint);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getChildByFieldName
 * Signature: ([BI)Lcom/itsaky/androidide/treesitter/TSNode;
 */
JNIEXPORT jobject JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getChildByFieldName
  (JNIEnv *, jobject, jbyteArray, jint);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getChildCount
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getChildCount
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getNamedChildCount
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getNamedChildCount
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getEndByte
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getEndByte
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getNodeString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getNodeString
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getStartByte
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getStartByte
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getStartPoint
 * Signature: ()Lcom/itsaky/androidide/treesitter/TSPoint;
 */
JNIEXPORT jobject JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getStartPoint
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getEndPoint
 * Signature: ()Lcom/itsaky/androidide/treesitter/TSPoint;
 */
JNIEXPORT jobject JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getEndPoint
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getType
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getType
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    getSymbol
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_itsaky_androidide_treesitter_TSNode_getSymbol
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    isNull
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TSNode_isNull
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    isNamed
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TSNode_isNamed
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    isExtra
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TSNode_isExtra
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    isMissing
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TSNode_isMissing
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    hasChanges
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TSNode_hasChanges
  (JNIEnv *, jobject);

/*
 * Class:     com_itsaky_androidide_treesitter_TSNode
 * Method:    hasErrors
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_itsaky_androidide_treesitter_TSNode_hasErrors
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
