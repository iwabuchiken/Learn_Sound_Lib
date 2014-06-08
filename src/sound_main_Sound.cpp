/*
 * sound_main_Sound.cpp
 *
 *  Created on: 2014/06/08
 *      Author: iwabuchik
 */
#include  <iostream>

#include "sound_main_Sound.h"

using namespace std;

JNIEXPORT void JNICALL Java_sound_main_Sound_hello
    (JNIEnv *env, jobject jthis, jstring data) {

    jboolean iscopy;
    const char *charData = env->GetStringUTFChars(data, &iscopy);
    cout << "Hello " << charData << endl;
    env->ReleaseStringUTFChars(data, charData);
}
