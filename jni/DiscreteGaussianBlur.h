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
	int ksize = sigma * 3 * 2 + 1;
	if (ksize == 1) {
		return;
	}
	int* tempPixels = new int[width * height];
	memcpy(tempPixels, pixels, width * height * sizeof(int));

	double* kernel = new double[ksize * ksize];
	double scale = -0.5 / (sigma * sigma);
	double PI = 3.141592653;
	double cons = -scale / PI;
	double val = 0;

	for (int i = 0; i < ksize; i++) {
		for (int j = 0; j < ksize; j++) {
			int x = i - (ksize - 1) / 2;
			int y = j - (ksize - 1) / 2;
			kernel[i * ksize + j] = cons * exp(scale * (x * x + y * y));

			val += kernel[i * ksize + j];
		}
	}

	double sumR, sumG, sumB;
	int index = 0;
	int bound = ksize / 2;

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
			//sumA = min(255, max(0, sumA / val));
			sumR = min(255, max(0, sumR / val));
			sumG = min(255, max(0, sumG / val));
			sumB = min(255, max(0, sumB / val));

			pixels[row * width + col] = RGB2Color(sumR, sumG, sumB);
		}
	}

	delete [] tempPixels;
	delete [] kernel;
}

void discreteGaussianBlur(int* pixels, int width, int height) {
	discreteGaussianBlurSigma(pixels, width, height, 2);
	/*
	int* tempPixels = new int[width * height];
	memcpy(tempPixels, pixels, width * height * sizeof(int));

	// 5 x 5 gaussian mask
	int mask[] = {1, 4, 7, 4, 1, 4, 16, 26, 16, 4, 7, 26, 41, 26, 7, 4, 16, 26, 16, 4, 1, 4, 7, 4, 1};
	int val = 273.0;
	// 7 x 7 gaussian mask
	int index = 0;
	double sumA = 0;
	double sumR = 0;
	double sumG = 0;
	double sumB = 0;
	for (int row = 2; row < height - 2; row++) {
		for (int col = 2; col < width - 2; col++) {
			index = 0;
			sumR = sumG = sumB = 0;
			for (int i = -2; i <= 2; i++) {
				for (int j = -2; j <= 2; j++) {
					Color color(tempPixels[(row + i) * width + col + j]);
					//sumA += color.alpha() * mask[index];
					sumR += color.R() * mask[index];
					sumG += color.G() * mask[index];
					sumB += color.B() * mask[index];
					index++;
				}
			}
			//sumA = min(255, max(0, sumA / val));
			sumR = min(255, max(0, sumR / val));
			sumG = min(255, max(0, sumG / val));
			sumB = min(255, max(0, sumB / val));

			//sumA = min(255, max(0, sumA));
			//sumR = min(255, max(0, sumR));
			//sumG = min(255, max(0, sumG));
			//sumB = min(255, max(0, sumB));

			pixels[row * width + col] = RGB2Color(sumR, sumG, sumB);
		}
	}

	delete [] tempPixels;*/
}


#endif /* DISCRETEGAUSSIANBLUR_H_ */
