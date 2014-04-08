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
#include <cstddef>

#include "ColorGetter.h"

#define		LOG_TAG    "AndroidImageFilter"
#define		LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define		LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define	 	LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)

typedef void (*IMG_PROC_FUNC)(int*, int, int);

static inline int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

static inline int max(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

static inline jint* getPixleArray(JNIEnv* env, jintArray buff) {
	jint* pixelsBuff;
	pixelsBuff = env->GetIntArrayElements(buff, false);
	return pixelsBuff;
}

static inline jintArray jintToJintArray(JNIEnv* env, jint size, jint* arr) {
	jintArray result = env->NewIntArray(size);
	env->SetIntArrayRegion(result, 0, size, arr);

	return result;
}

static inline void releaseArray(JNIEnv* env, jintArray array1, jint* array2) {
	env->ReleaseIntArrayElements(array1, array2, 0);
}

static inline jintArray procImage(JNIEnv* env, jintArray pixels, jint width, jint height, IMG_PROC_FUNC procFunc) {
	jint* pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("cannot get the pixels");
	}
	procFunc(pixelsBuff, width, height);

	jintArray result = jintToJintArray(env, width * height, pixelsBuff);
	releaseArray(env, pixels, pixelsBuff);

	return result;
}

static inline void changeImageToGray(int* pixels, int width, int height) {
	for (int i = 0; i < width * height; i++) {
		Color color(pixels[i]);
		float gray = color.R() * 0.3 + color.G() * 0.59 + color.B() * 0.11;
		pixels[i] = RGB2Color(gray, gray, gray);
	}
}

#endif /* UTIL_H_ */
