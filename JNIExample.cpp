#include "JNIExample.h"
#include <ctype.h>
#include <string.h>

// Mutate array to uppercase
void uppercase(char* str) {
    size_t n = strlen(str);
    for (size_t i = 0; i < n; i++) {
        str[i] = toupper(str[i]); 
    }
}

JNIEXPORT jint JNICALL Java_JNIExample_intMethod
(JNIEnv* env, jobject obj, jint num) {
    return num * num;
}


JNIEXPORT jboolean JNICALL Java_JNIExample_booleanMethod
(JNIEnv* env, jobject obj, jboolean boolean) {
    return !boolean;
}

JNIEXPORT jstring JNICALL Java_JNIExample_stringMethod
(JNIEnv* env, jobject obj, jstring string) {
    const char* str = env->GetStringUTFChars(string, 0);
    char cap[128];
    strcpy(cap, str);
    env->ReleaseStringUTFChars(string, str);
    uppercase(cap);
    return env->NewStringUTF(cap);
}

JNIEXPORT void JNICALL Java_JNIExample_intArrayMethod
(JNIEnv* env, jobject obj, jintArray array) {
    jsize len = env->GetArrayLength(array);
    jint* body = env->GetIntArrayElements(array, 0);
    for (int i = 0; i < len; i++) {
        body[i] ++;
    }
    env->ReleaseIntArrayElements(array, body, 0);
    return;
}


JNIEXPORT void JNICALL Java_JNIExample_byteArrayMethod
(JNIEnv* env, jobject obj, jbyteArray array) 
{
    jsize len = env->GetArrayLength(array);
    jbyte* body = env->GetByteArrayElements(array, 0);
    for (int i = 0; i < len; i++) {
        body[i] --;
    }
    env->ReleaseByteArrayElements(array, body, 0);
    return;
}

JNIEXPORT void JNICALL Java_JNIExample_classMethod
(JNIEnv* env, jobject obj, jobject classref) 
{
   jclass jc = env->GetObjectClass(classref);
   jmethodID mid = env->GetMethodID(jc, "callMe","(Ljava/lang/String;)Ljava/lang/String;");
   jstring result = (jstring)env->CallObjectMethod(classref, mid, env->NewStringUTF("Hello from cpp."));
   
   const char * nativeresult = env->GetStringUTFChars(result, 0); 
   printf("%s\n", nativeresult);
   env->ReleaseStringUTFChars(result, nativeresult);
}