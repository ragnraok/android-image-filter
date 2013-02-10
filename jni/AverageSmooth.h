/*
 * AverageSmooth.h
 *
 *  Created on: 2013-2-10
 *      Author: ragnarok
 */

#ifndef AVERAGESMOOTH_H_
#define AVERAGESMOOTH_H_

#include "Util.h"

// average 3x3 mask
void averageSmooth(int* pixels, int width, int height) {
	int* tempPixels = new int[width * height];
	memcpy(tempPixels, pixels, width * height * sizeof(int));

	int sumR = 0;
	int sumG = 0;
	int sumB = 0;
	for (int row = 1; row < height - 1; row++) {
		for (int col = 1; col < width - 1; col++) {
			sumR = sumG = sumB = 0;
			for (int m = -1; m <= 1; m++) {
				for (int n = -1; n <= 1; n++) {
					Color color(pixels[(row + m) * width + col + n]);
					sumR += color.R();
					sumG += color.G();
					sumB += color.B();
				}
			}
			pixels[row * width + col] = RGB2Color(sumR / 9, sumG / 9, sumB / 9);
		}
	}

	delete [] tempPixels;
}



#endif /* AVERAGESMOOTH_H_ */
