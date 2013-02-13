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

void discreteGaussianBlur(int* pixels, int width, int height) {
	int* tempPixels = new int[width * height];
	memcpy(tempPixels, pixels, width * height * sizeof(int));

	// 5 x 5 gaussian mask
	int mask[] = {1, 4, 7, 4, 1, 4, 16, 26, 16, 4, 7, 26, 41, 26, 7, 4, 16, 26, 16, 4, 1, 4, 7, 4, 1};
	int val = 273.0;
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
					sumA += color.alpha() * mask[index];
					sumR += color.R() * mask[index];
					sumG += color.G() * mask[index];
					sumB += color.B() * mask[index];
					index++;
				}
			}
			sumA = min(255, max(0, sumA / val));
			sumR = min(255, max(0, sumR / val));
			sumG = min(255, max(0, sumG / val));
			sumB = min(255, max(0, sumB / val));

			pixels[row * width + col] = ARGB2Color(sumA, sumR, sumG, sumB);
		}
	}

	delete [] tempPixels;
}


#endif /* DISCRETEGAUSSIANBLUR_H_ */
