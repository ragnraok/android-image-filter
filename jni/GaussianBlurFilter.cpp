/*
 * GaussianBlurFilter.cpp
 *
 *  Created on: 2014-4-11
 *      Author: ragnarok
 */

#include <math.h>
#include <stdio.h>

#include "GaussianBlurFilter.h"


GaussianBlurFilter::GaussianBlurFilter(int *_pixels, int _width, int _height, GaussianBlurOptions options):
	ImageFilter(_pixels, _width, _height),
	sigma(options.sigma),
	kernelSum(0) {

	// pre-calculate kernel
	int ksize = ceil(sigma * 3 + 1);
	if (ksize == 1) {
		return;
	}
	this->kernel = new double[ksize * ksize];
	double scale = -0.5 / (sigma * sigma);
	double PI = 3.141592653;
	double cons = -scale / PI;
	double sum = 0;

	for (int i = 0; i < ksize; i++) {
		for (int j = 0; j < ksize; j++) {
			int x = i - (ksize - 1) / 2;
			int y = j - (ksize - 1) / 2;
			kernel[i * ksize + j] = cons * exp(scale * (x * x + y * y));

			sum += kernel[i * ksize + j];
		}
	}

	// normalize
	for (int i = 0; i < ksize; i++) {
		for (int j = 0; j < ksize; j++) {
			kernel[i * ksize + j] /= sum;
		}
	}
	kernelSum = sum;
}

//#define CAL_MASK_STEP(pixRow, pixCol, kernel, kernelIndex, sumR, sumG, sumB, ksize, bound) \
//	maskY = -bound + (kernelIndex / ksize); \
//	maskX = -bound + (kernelIndex % ksize); \
//	color = Color(tempPixels[(pixRow + maskY) * width + pixCol + maskX]); \
//	sumR += color.R() * kernel[index]; \
//	sumG += color.G() * kernel[index]; \
//	sumB += color.B() * kernel[index]; \

int* GaussianBlurFilter::procImage() {
	int ksize = sigma * 3 + 1;
	if (ksize == 1) {
		return NULL;
	}
	int* tempPixels = new int[width * height];
	memcpy(tempPixels, pixels, width * height * sizeof(int));

	double sumR, sumG, sumB;
	int index = 0;
	int bound = ksize / 2;
//	int kernelSize = ksize * ksize;
//	int div = kernelSize * kernelSum;

	long startTime = getCurrentTime();

	for (int row = bound; row < height - bound; row++) {
		for (int col = bound; col < width - bound; col++) {
			index = 0;
			sumR = sumG = sumB = 0;
			for (int i = -bound; i <= bound; i++) {
				for (int j = -bound; j <= bound; j++) {
					Color color(tempPixels[(row + i) * width + col + j]);
					sumR += color.R() * kernel[index];
					sumG += color.G() * kernel[index];
					sumB += color.B() * kernel[index];
					index++;
				}
			}

			pixels[row * width + col] = RGB2Color(int(sumR), int(sumG), int(sumB));
		}
	}

	long endTime = getCurrentTime();

	LOGI("guassian blur use %ld ms", endTime - startTime);

	delete [] tempPixels;

	return this->pixels;
}

