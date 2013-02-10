/*
 * cn_Ragnarok_NativeFilterFunc.cpp
 *
 *  Created on: 2013-2-9
 *      Author: ragnarok
 */

#include "cn_Ragnarok_NativeFilterFunc.h"
#include "LightFilter.h"
#include "NeonFilter.h"
#include "OilFilter.h"
#include "TvFilter.h"
#include "AverageSmooth.h"
#include "Util.h"

jintArray Java_cn_Ragnarok_NativeFilterFunc_lightFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
	jintArray result = procImage(env, pixels, width, height, lightFilter);

	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_lomoFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
	return pixels;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_neonFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
	jintArray result = procImage(env, pixels, width, height, neonFilter);

	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_oilFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
	jintArray result = procImage(env, pixels, width, height, oilFilter);

	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_tvFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
	jintArray result = procImage(env, pixels, width, height, tvFilter);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_averageSmooth(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
	jintArray result = procImage(env, pixels, width, height, averageSmooth);
	return result;
}
