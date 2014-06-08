/*
 * sound_main_Sound.cpp
 *
 *  Created on: 2014/06/08
 *      Author: iwabuchik
 */
#include  <iostream>

#include <stdio.h>
#include <stdlib.h>

#include "sound_main_Sound.h"

using namespace std;

//JNIEXPORT void JNICALL Java_sound_main_Sound_hello
JNIEXPORT jstring JNICALL Java_sound_main_Sound_hello
    (JNIEnv *env, jobject jthis, jstring data) {

//	const char *add = " => received";
//
//	int len = strlen(data) + strlen()
//
//	char *message = (char *) malloc(sizeof(char) * strlen(data))

//	string message = string(data) + " => received";

//	string message;

    jboolean iscopy;
    const char *charData = env->GetStringUTFChars(data, &iscopy);

    const char *add = " => received";

    int len = strlen(charData) + strlen(add);

    char *message = (char *) malloc(sizeof(char) * (len + 1));

    sprintf(message, "%s%s", charData, add);
//    message = string(charData) + " => received";

    cout << "Hello " << charData << endl;
    env->ReleaseStringUTFChars(data, charData);

    jstring jstrBuf = env->NewStringUTF(message);
//    jstring jstrBuf = (*env)->NewStringUTF(env, message);



    return jstrBuf;

//    return message;

}
