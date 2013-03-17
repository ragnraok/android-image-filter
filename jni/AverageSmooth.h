/*
 * AverageSmooth.h
 *
 *  Created on: 2013-2-10
 *      Author: ragnarok
 */

#ifndef AVERAGESMOOTH_H_
#define AVERAGESMOOTH_H_

#include "Util.h"

// average 5x5 mask
void averageSmooth(int* pixels, int width, int height) {
	int* tempPixels = new int[width * height];
	memcpy(tempPixels, pixels, width * height * sizeof(int));

	int sumR = 0;
	int sumG = 0;
	int sumB = 0;
	int div = 25;
	for (int row = 2; row < height - 2; row++) {
		for (int col = 2; col < width - 2; col++) {
			sumR = sumG = sumB = 0;
			for (int m = -2; m <= 2; m++) {
				for (int n = -2; n <= 2; n++) {
					Color color(pixels[(row + m) * width + col + n]);
					sumR += color.R();
					sumG += color.G();
					sumB += color.B();
				}
			}
			pixels[row * width + col] = RGB2Color(sumR / div, sumG / div, sumB / div);
		}
	}

	delete [] tempPixels;
}



#endif /* AVERAGESMOOTH_H_ */
