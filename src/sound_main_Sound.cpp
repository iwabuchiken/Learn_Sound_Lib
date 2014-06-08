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

JNIEXPORT jdoubleArray JNICALL Java_sound_main_Sound_get_1Wave
  (JNIEnv *env, jobject jthis, jstring input)
{

	double data[3];

	data[0] = 0.3;
	data[1] = 0.66;
	data[2] = 0.554;

	jdoubleArray res = env->NewDoubleArray(3);

//	res[0] = data[0];
//	res[1] = data[1];
//	res[2] = data[2];

	//REF http://stackoverflow.com/questions/7318143/converting-between-jdoublearray-and-vectordouble-in-a-java-native-jni-method answered Sep 6 '11 at 10:25
	//REF API http://jikesrvm.sourceforge.net/apidocs/latest/org/jikesrvm/jni/JNIFunctions.html#SetDoubleArrayRegion(org.jikesrvm.jni.JNIEnvironment, int, int, int, org.vmmagic.unboxed.Address)
	env->SetDoubleArrayRegion(res, 0, 3, data);

	return res;

}
