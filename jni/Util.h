/*
 * Util.h
 *
 *  Created on: 2013-2-9
 *      Author: ragnarok
 */

#ifndef UTIL_H_
#define UTIL_H_

#include <android/log.h>
#include <jni.h>

#define		LOG_TAG    "AndroidImageFilter"
#define		LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define		LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define	 	LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)


int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

jint* getPixleArray(JNIEnv* env, jintArray buff) {
	jint* pixelsBuff;
	pixelsBuff = env->GetIntArrayElements(buff, false);
	return pixelsBuff;
}

jintArray jintToJintArray(JNIEnv* env, jint size, jint* arr) {
	jintArray result = env->NewIntArray(size);
	env->SetIntArrayRegion(result, 0, size, arr);

	return result;
}

void releaseArray(JNIEnv* env, jintArray array1, jint* array2) {
	env->ReleaseIntArrayElements(array1, array2, 0);
}

#endif /* UTIL_H_ */
