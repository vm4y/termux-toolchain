#include <jni.h>

#ifndef ABI
#define ABI "unknown"
#endif

JNIEXPORT jstring JNICALL
Java_com_example_test_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    (void)thiz;

    return (*env)->NewStringUTF(env, "Hello From JNI (C) - " ABI);
}
