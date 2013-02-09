/*
 * cn_Ragnarok_NativeFilterFunc.cpp
 *
 *  Created on: 2013-2-9
 *      Author: ragnarok
 */

#include "cn_Ragnarok_NativeFilterFunc.h"
#include "LightFilter.h"
#include "NeonFilter.h"
#include "Util.h"

jintArray Java_cn_Ragnarok_NativeFilterFunc_lightFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
	jint* pixelsBuff;
	pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("in lightFilter, cannot get the pixels");
	}

	lightFilter(pixelsBuff, width, height);
	jintArray result = jintToJintArray(env, width * height, pixelsBuff);

	//env->ReleaseIntArrayElements(pixels, pixelsBuff, 0);
	releaseArray(env, pixels, pixelsBuff);

	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_lomoFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
	return pixels;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_neonFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
	jint* pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("in neon filter, cannot get the pixels");
	}

	LOGD("pixelsBuff[1] = %u", pixelsBuff[1]);
	neonFilter(pixelsBuff, width, height);
	jintArray result = jintToJintArray(env, width * height, pixelsBuff);
	LOGD("result[1] = %u", result[1]);
	releaseArray(env, pixels, pixelsBuff);

	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_oldFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_tvFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_averageSmooth(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
}
