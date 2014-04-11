/*

 * cn_Ragnarok_NativeFilterFunc.cpp
 *
 *  Created on: 2013-2-9
 *      Author: ragnarok
 */

#include "cn_Ragnarok_NativeFilterFunc.h"

#include "Util.h"
#include "NeonFilter.h"
#include "OilFilter.h"
#include "TvFilter.h"
#include "LomoAddBlackRound.h"
#include "SoftGlowFilter.h"
#include "SketchFilter.h"
#include "AverageSmoothFilter.h"
#include "GaussianBlurFilter.h"
#include "HDRFilter.h"
#include "LightFilter.h"

jintArray Java_cn_Ragnarok_NativeFilterFunc_lightFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jint centerX, jint centerY, jint radius) {

	LightFilterOptions options(centerX, centerY, radius);
	jintArray result;
	PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, LightFilter, options, result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_lomoAddBlckRound(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jdouble roundRadius) {

	BlackRoundOptions options(roundRadius);
	jintArray result;
	PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, LomoAddBlackRound, options, result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_neonFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jint r, jint g, jint b) {

	NeonFilterOptions options(r, g, b);
	jintArray result;
	PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, NeonFilter, options, result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_oilFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {

	jintArray result;
	PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, OilFilter, result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_tvFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {

	jintArray result;
	PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, TvFilter, result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_averageSmooth(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jint maskSize) {

	jintArray result;
	AverageSmoothOptions options(maskSize);
	PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, AverageSmoothFilter, options, result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_hdrFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {

	jintArray result;
	PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, HDRFilter, result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_discreteGaussianBlur(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jdouble sigma) {

	GaussianBlurOptions options(sigma);
	jintArray result;
	PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, GaussianBlurFilter, options, result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_softGlow(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height, jdouble blurSigma) {

	jintArray result;
	SoftGlowOptions options(blurSigma);
	PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, SoftGlowFilter, options, result);

	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_sketchFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {

	jintArray result;
	PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, SketchFilter ,result);

	return result;
}
