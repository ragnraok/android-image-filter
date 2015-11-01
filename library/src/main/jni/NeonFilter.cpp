/*
 * NeonFilter.cpp
 *
 *  Created on: 2014-4-11
 *      Author: ragnarok
 */


#include "NeonFilter.h"

NeonFilter::NeonFilter(int* pixels, int width, int height, NeonFilterOptions options):
	ImageFilter(pixels, width, height),
	neonR(options.r),
	neonG(options.g),
	neonB(options.b) {

}

int* NeonFilter::procImage() {
	int xSobel[] = { 1, 2, 1, 0, 0, 0, -1, -2, -1 };
	int ySobel[] = { 1, 0, -1, 2, 0, -2, 1, 0, -1 };

	int index = 0;
	int originGray = 0;
	int afterGray = 0;
	int maskSize = 3;
	int halfMaskSize = maskSize / 2;

	int xVal = 0;
	int yVal = 0;
	float threshold = 110;

	int *originPixels = new int[width * height];
	memcpy(originPixels, pixels, width * height * sizeof(int));

	for (int i = halfMaskSize; i < height - halfMaskSize; i++) {
		for (int j = halfMaskSize; j < width - halfMaskSize; j++) {
			index = 0;
			afterGray = 0;
			xVal = yVal = 0;
			for (int m = -halfMaskSize; m <= halfMaskSize; m++) {
				for (int n = -halfMaskSize; n <= halfMaskSize; n++) {
					Color pixColor = Color(originPixels[(i + m) * width + j + n]);
					originGray = pixColor.grayScale();

					xVal += originGray * xSobel[index];
					yVal += originGray * ySobel[index];
					index++;
				}
			}
			afterGray = abs(xVal) + abs(yVal);
			afterGray = min(255, max(0, afterGray));
			int pixel_index = i * width + j;
			if (pixel_index < width * height) {
				if (afterGray > threshold) {
					pixels[i * width + j] = RGB2Color(neonR, neonG, neonB);
				} else
					pixels[i * width + j] = RGB2Color(1, 1, 1);
			}

		}
	}

	delete [] originPixels;

	return pixels;
}
