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
#include "SharpenFilter.h"
#include "ReliefFilter.h"
#include "PixelateFilter.h"
#include "BlockFilter.h"
#include "MotionBlurFilter.h"
#include "GothamFilter.h"

jintArray Java_cn_Ragnarok_NativeFilterFunc_lightFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jint centerX, jint centerY, jint radius) {

	LightFilterOptions options(centerX, centerY, radius);
	jintArray result = PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, LightFilter, options);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_lomoAddBlckRound(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jdouble roundRadius) {

	BlackRoundOptions options(roundRadius);
	jintArray result = PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, LomoAddBlackRound, options);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_neonFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jint r, jint g, jint b) {

	NeonFilterOptions options(r, g, b);
	jintArray result = PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, NeonFilter, options);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_oilFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jint oilRange) {

	OilFilterOptions options(oilRange);

	jintArray result = PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, OilFilter, options);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_tvFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
	jintArray result = PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, TvFilter);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_averageSmooth(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jint maskSize) {

	AverageSmoothOptions options(maskSize);
	jintArray result = PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, AverageSmoothFilter, options);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_hdrFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {

	jintArray result = PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, HDRFilter);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_discreteGaussianBlur(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jdouble sigma) {

	GaussianBlurOptions options(sigma);
	jintArray result = PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, GaussianBlurFilter, options);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_softGlow(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height, jdouble blurSigma) {

	SoftGlowOptions options(blurSigma);
	jintArray result = PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, SoftGlowFilter, options);

	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_sketchFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
	jintArray result = PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, SketchFilter);

	return result;
}

jintArray JNICALL Java_cn_Ragnarok_NativeFilterFunc_sharpenFilter(JNIEnv *env, jclass object,
		jintArray pixels, jint width, jint height) {
	jintArray result = PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, SharpenFilter);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_reliefFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
	jintArray result = PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, ReliefFilter);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_pxelateFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height, jint pixelSize) {
	PixelateOptions options(pixelSize);
	jintArray result = PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, PixelateFilter, options);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_blockFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
	jintArray result = PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, BlockFilter);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_motionBlurFilter(JNIEnv* env, jclass,
		jintArray pixels, jint width, jint height, jint xSpeed, jint ySpeed) {
	MotionBlurFilterOpitons options(xSpeed, ySpeed);
	jintArray result = PROC_IMAGE_WITH_OPTIONS(env, pixels, width, height, MotionBlurFilter, options);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_gothamFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
	jintArray result = PROC_IMAGE_WITHOUT_OPTIONS(env, pixels, width, height, GothamFilter);
	return result;
}
