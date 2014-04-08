/*
 * DiscreteGaussianBlur.h
 *
 *  Created on: 2013-2-13
 *      Author: ragnarok
 */

#ifndef DISCRETEGAUSSIANBLUR_H_
#define DISCRETEGAUSSIANBLUR_H_

#include "Util.h"
#include "ColorGetter.h"

void discreteGaussianBlurSigma(int *pixels, int width, int height, double sigma) {
	LOGI("start calculate kernel");
	int ksize = sigma * 3 + 1;
	if (ksize == 1) {
		return;
	}
	int* tempPixels = new int[width * height];
	memcpy(tempPixels, pixels, width * height * sizeof(int));

	double* kernel = new double[ksize * ksize];
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
	LOGI("finish calculate kernel");

	double sumR, sumG, sumB;
	int index = 0;
	int bound = ksize / 2;

	LOGI("start calculate filter");
	for (int row = bound; row < height - bound; row++) {
		for (int col = bound; col < width - bound; col++) {
			index = 0;
			sumR = sumG = sumB = 0;
			for (int i = -bound; i <= bound; i++) {
				for (int j = -bound; j <= bound; j++) {
					Color color(tempPixels[(row + i) * width + col + j]);
					//sumA += color.alpha() * mask[index];
					sumR += color.R() * kernel[index];
					sumG += color.G() * kernel[index];
					sumB += color.B() * kernel[index];
					index++;
				}
			}

			pixels[row * width + col] = RGB2Color(int(sumR), int(sumG), int(sumB));
		}
	}
	LOGI("finish calculate filter");

	delete [] tempPixels;
	delete [] kernel;
}

void discreteGaussianBlur(int* pixels, int width, int height) {
	discreteGaussianBlurSigma(pixels, width, height, 2.0);
}


#endif /* DISCRETEGAUSSIANBLUR_H_ */
