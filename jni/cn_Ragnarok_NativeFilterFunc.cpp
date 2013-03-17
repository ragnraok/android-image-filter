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
#include "LomoAddBlackRound.h"
#include "HDRFilter.h"
#include "DiscreteGaussianBlur.h"
#include "SoftGlowFilter.h"
#include "SketchFilter.h"
#include "Util.h"

jintArray Java_cn_Ragnarok_NativeFilterFunc_lightFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
	jintArray result = procImage(env, pixels, width, height, lightFilter);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_lomoAddBlckRound(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
	jintArray result = procImage(env, pixels, width, height, lomoAddBlackRound);
	return result;
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

jintArray Java_cn_Ragnarok_NativeFilterFunc_hdrFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
	jintArray result = procImage(env, pixels, width, height, hdrFilter);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_discreteGaussianBlur(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {
	jintArray result = procImage(env, pixels, width, height, discreteGaussianBlur);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_softGlow(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
	jintArray result = procImage(env, pixels, width, height, softGlowFilter);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_sketchFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
	jintArray result = procImage(env, pixels, width, height, sketchFilter);
	return result;
}
