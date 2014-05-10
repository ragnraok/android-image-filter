/*
 * AverageSmoothFilter.cpp
 *
 *  Created on: 2014-4-10
 *      Author: ragnarok
 */

#include "AverageSmoothFilter.h"

AverageSmoothFilter::AverageSmoothFilter(int *_pixels, int _width, int _height, AverageSmoothOptions options) :
	ImageFilter(_pixels, _width, _height),
	maskSize(options.maskSize) {
	// TODO Auto-generated constructor stub

}

AverageSmoothFilter::AverageSmoothFilter(int* pixels, int width, int height):
	ImageFilter(pixels, width, height) {
	maskSize = 5;
}

int* AverageSmoothFilter::procImage() {
	int sumR = 0;
	int sumG = 0;
	int sumB = 0;
	int div = maskSize * maskSize;
	int halfMaskSize = maskSize / 2;

	for (int row = halfMaskSize; row < height - halfMaskSize; row++) {
		for (int col = halfMaskSize; col < width - halfMaskSize; col++) {
			sumR = sumG = sumB = 0;
			for (int m = -halfMaskSize; m <= halfMaskSize; m++) {
				for (int n = -halfMaskSize; n <= halfMaskSize; n++) {
					int index = (row + m) * width + col + n;
					if (index < width * height) {
						Color color(pixels[(row + m) * width + col + n]);
						sumR += color.R();
						sumG += color.G();
						sumB += color.B();
					}
				}
			}
			pixels[row * width + col] = RGB2Color(sumR / div, sumG / div, sumB / div);
		}
	}

	return this->pixels;
}

