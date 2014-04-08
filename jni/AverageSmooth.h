/*
 * AverageSmooth.h
 *
 *  Created on: 2013-2-10
 *      Author: ragnarok
 */

#ifndef AVERAGESMOOTH_H_
#define AVERAGESMOOTH_H_

#include "Util.h"

void averageSmoothMaskSize(int* pixels, int width, int height, int maskSize = 5) {
	int* tempPixels = new int[width * height];
		memcpy(tempPixels, pixels, width * height * sizeof(int));


		int sumR = 0;
		int sumG = 0;
		int sumB = 0;
		int div = maskSize * maskSize;
		int halfMaskSize = maskSize / 2;

		for (int row = halfMaskSize; row < height - halfMaskSize; row++) {
			for (int col = halfMaskSize; col < width - halfMaskSize; col++) {
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

// default mask size is 5x5
void averageSmooth(int* pixels, int width, int height) {
	averageSmoothMaskSize(pixels, width, height, 5);
}



#endif /* AVERAGESMOOTH_H_ */
