#include "JNIExample.h"

JNIEXPORT void JNICALL Java_JNIExample_SetCallback (JNIEnv * jnienv, jobject jobj, jobject      classref)
{
   jclass jc = jnienv->GetObjectClass(classref);
   jmethodID mid = jnienv->GetMethodID(jc, "Callback","(Ljava/lang/String;)Ljava/lang/String;");
   jstring result = (jstring)jnienv->CallObjectMethod(classref, mid, jnienv->NewStringUTF("hello jni"));
   const char * nativeresult = jnienv->GetStringUTFChars(result, 0); 

   printf("Echo from Setcallback: %s", nativeresult);

   jnienv->ReleaseStringUTFChars(result, nativeresult); 
}
