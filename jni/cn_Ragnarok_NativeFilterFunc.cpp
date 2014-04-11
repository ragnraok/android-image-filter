/*

 * cn_Ragnarok_NativeFilterFunc.cpp
 *
 *  Created on: 2013-2-9
 *      Author: ragnarok
 */

#include "cn_Ragnarok_NativeFilterFunc.h"

#include "NeonFilter.h"
#include "OilFilter.h"
#include "TvFilter.h"
#include "LomoAddBlackRound.h"
#include "SoftGlowFilter.h"
#include "SketchFilter.h"

#include "Util.h"
#include "AverageSmoothFilter.h"
#include "GaussianBlurFilter.h"
#include "HDRFilter.h"
#include "LightFilter.h"

jintArray Java_cn_Ragnarok_NativeFilterFunc_lightFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jint centerX, jint centerY, jint radius) {
	jint* pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("cannot get the pixels");
	}
	LightFilter filter = LightFilter(pixelsBuff, width, height, centerX, centerY, radius);
	jint *_result = filter.procImage();
	jintArray result = jintToJintArray(env, width * height, _result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_lomoAddBlckRound(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jdouble roundRadius) {
	jint* pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("cannot get the pixels");
	}
	LomoAddBlackRound filter = LomoAddBlackRound(pixelsBuff, width, height, roundRadius);
	jint *_result = filter.procImage();
	jintArray result = jintToJintArray(env, width * height, _result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_neonFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jint r, jint g, jint b) {
	int* pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("cannot get the pixels");
	}
	NeonFilter filter = NeonFilter(pixelsBuff, width, height, r, g, b);
	jint *_result = filter.procImage();
	jintArray result = jintToJintArray(env, width * height, _result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_oilFilter(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height) {

	int* pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("cannot get the pixels");
	}
	OilFilter filter = OilFilter(pixelsBuff, width, height);
	jint *_result = filter.procImage();
	jintArray result = jintToJintArray(env, width * height, _result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_tvFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
	jint* pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("cannot get the pixels");
	}
	TvFilter filter = TvFilter(pixelsBuff, width, height);
	jint *_result = filter.procImage();
	jintArray result = jintToJintArray(env, width * height, _result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_averageSmooth(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jint maskSize) {
	jint* pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("cannot get the pixels");
	}
	AverageSmoothFilter filter = AverageSmoothFilter(pixelsBuff, width, height, maskSize);
	jint *_result = filter.procImage();
	jintArray result = jintToJintArray(env, width * height, _result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_hdrFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
	jint* pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("cannot get the pixels");
	}
	HDRFilter filter = HDRFilter(pixelsBuff, width, height);
	jint *_result = filter.procImage();
	jintArray result = jintToJintArray(env, width * height, _result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_discreteGaussianBlur(JNIEnv* env,
		jclass object, jintArray pixels, jint width, jint height, jdouble sigma) {
	jint* pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("cannot get the pixels");
	}
	GaussianBlurFilter filter = GaussianBlurFilter(pixelsBuff, width, height,
			sigma);
	jint *_result = filter.procImage();
	jintArray result = jintToJintArray(env, width * height, _result);
	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_softGlow(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height, jdouble blurSigma) {
	jint* pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("cannot get the pixels");
	}
	SoftGlowFilter filter = SoftGlowFilter(pixelsBuff, width, height, blurSigma);
	jint *_result = filter.procImage();
	jintArray result = jintToJintArray(env, width * height, _result);

	return result;
}

jintArray Java_cn_Ragnarok_NativeFilterFunc_sketchFilter(JNIEnv* env, jclass object,
		jintArray pixels, jint width, jint height) {
	jint* pixelsBuff = getPixleArray(env, pixels);

	if (pixelsBuff == NULL) {
		LOGE("cannot get the pixels");
	}
	SketchFilter filter = SketchFilter(pixelsBuff, width, height);
	jint *_result = filter.procImage();
	jintArray result = jintToJintArray(env, width * height, _result);

	return result;
}
