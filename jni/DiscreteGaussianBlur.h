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

	// 3 x 3 gaussian mask
	int mask[] = {1, 2, 1, 2, 4, 2, 1, 2, 1};
	int index = 0;
	double sumR = 0;
	double sumG = 0;
	double sumB = 0;
	for (int row = 1; row < height - 1; row++) {
		for (int col = 1; col < width - 1; col++) {
			index = 0;
			sumR = sumG = sumB = 0;
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					Color color(tempPixels[(row + i) * width + col + j]);
					sumR += color.R() * mask[index];
					sumG += color.G() * mask[index];
					sumB += color.B() * mask[index];
					index++;
				}
			}
			sumR = min(255, max(0, sumR / 16.0));
			sumG = min(255, max(0, sumG / 16.0));
			sumB = min(255, max(0, sumB / 16.0));

			pixels[row * width + col] = RGB2Color(sumR, sumG, sumB);
		}
	}

	delete [] tempPixels;
}


#endif /* DISCRETEGAUSSIANBLUR_H_ */
