/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class JNIExample */

#ifndef _Included_JNIExample
#define _Included_JNIExample
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     JNIExample
 * Method:    intMethod
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_JNIExample_intMethod
  (JNIEnv *, jobject, jint);

/*
 * Class:     JNIExample
 * Method:    booleanMethod
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL Java_JNIExample_booleanMethod
  (JNIEnv *, jobject, jboolean);

/*
 * Class:     JNIExample
 * Method:    stringMethod
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_JNIExample_stringMethod
  (JNIEnv *, jobject, jstring);

/*
 * Class:     JNIExample
 * Method:    intArrayMethod
 * Signature: ([I)V
 */
JNIEXPORT void JNICALL Java_JNIExample_intArrayMethod
  (JNIEnv *, jobject, jintArray);

/*
 * Class:     JNIExample
 * Method:    byteArrayMethod
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_JNIExample_byteArrayMethod
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     JNIExample
 * Method:    classMethod
 * Signature: (LJNIExample;)V
 */
JNIEXPORT void JNICALL Java_JNIExample_classMethod
  (JNIEnv *, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
