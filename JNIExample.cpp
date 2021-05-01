#include "JNIExample.h"
#include <iostream>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <thread>

JavaVM* jvm;

void callback_method(unsigned char* buf, int buflen)
{
    printf("Cpp callback method\n");
    JNIEnv * env;
    int getEnvStat = jvm->GetEnv((void **)&env, JNI_VERSION_1_8);
    if (getEnvStat == JNI_EDETACHED) 
    {
        if (jvm->AttachCurrentThread((void **) &env, NULL) != 0) {
            std::cout << "Failed to attach" << std::endl;
            return;
        }
    }
    else if (getEnvStat == JNI_EVERSION) {
        std::cout << "GetEnv: version not supported" << std::endl;
        return;
    }
    // First get the class that contains the method you need to call
    jclass clazz = env->FindClass("JNIExample");

    jmethodID mid = env->GetStaticMethodID(clazz, "callback_method", "([B)V");
    if(mid == 0){
        printf("Method not found!");
        return;
    }

    jbyteArray jbyteArr = env->NewByteArray (buflen);
    env->SetByteArrayRegion (jbyteArr, 0, buflen, reinterpret_cast<jbyte*>(buf));
    env->CallStaticVoidMethod(clazz, mid, jbyteArr);
    jvm->DetachCurrentThread();
}


JNIEXPORT void JNICALL Java_JNIExample_initMethod
(JNIEnv* env, jobject obj) 
{
  env->GetJavaVM(&jvm);
  unsigned char buf[] = {12, 14, 43, 63, 53};
  int buflen = 5;

  while(true)
  {
      for(int i=0; i < buflen; i++){
          buf[i]++;
      }
      callback_method(buf, buflen);
      usleep(1000000);
  }
}