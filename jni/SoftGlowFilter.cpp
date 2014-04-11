/*
 * SoftGlowFilter.cpp
 *
 *  Created on: 2014-4-11
 *      Author: ragnarok
 */

#include "SoftGlowFilter.h"

SoftGlowFilter::SoftGlowFilter(int *_pixels, int _width, int _height, SoftGlowOptions options):
	ImageFilter(_pixels, _width, _height),
	blurSigma(options.blurSigma) {

}

int* SoftGlowFilter::procImage() {
	int *blurPixels = new int[this->width * this->height];
	memcpy(blurPixels, pixels, width * height * sizeof(int));

	GaussianBlurFilter *gaussianFilter = new GaussianBlurFilter(blurPixels, width, height, blurSigma);
	blurPixels = gaussianFilter->procImage();

	int originR = 0, originG = 0, originB = 0, originA = 0;
	int pixR = 0, pixG = 0, pixB = 0, pixA = 0;

	double factorA = 1;
	double factorB = 0.3;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			Color originColor(blurPixels[row * width + col]);
			originR = originColor.R();
			originG = originColor.G();
			originB = originColor.B();

			Color pixColor(pixels[row * width + col]);
			pixA = pixColor.alpha();
			pixR = pixColor.R();
			pixG = pixColor.G();
			pixB = pixColor.B();

			pixR = originR * factorA + pixR * factorB;
			pixG = originG * factorA + pixG * factorB;
			pixB = originB * factorA + pixB * factorB;
//			pixR = ((pixR < 128) ?
//					(2 * ((originR >> 1) + 64)) * ((float) pixR / 255) :
//					(255 - (2 * (255 - ((originR >> 1) + 64)) * (float) (255 - pixR) / 255)));
//
//			pixG = ((pixG < 128) ?
//					(2 * ((originG >> 1) + 64)) * ((float) pixG / 255) :
//					(255 - (2 * (255 - ((originG >> 1) + 64)) * (float) (255 - pixG) / 255)));
//			pixB = ((pixB < 128) ?
//					(2 * ((originB >> 1) + 64)) * ((float) pixB / 255) :
//					(255 - (2 * (255 - ((originB >> 1) + 64)) * (float) (255 - pixB) / 255)));

			pixR = min(255, max(pixR, 0));
			pixG = min(255, max(pixG, 0));
			pixB = min(255, max(pixB, 0));

			pixels[row * width + col] = ARGB2Color(pixA, pixR, pixG, pixB);
		}
	}

	delete gaussianFilter;
	return pixels;
}



