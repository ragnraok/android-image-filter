/*
 * SharpenFilter.cpp
 *
 *  Created on: 2014-4-12
 *      Author: ragnarok
 */


#include "SharpenFilter.h"

SharpenFilter::SharpenFilter(int *pixels, int width, int height):
	ImageFilter(pixels, width, height) {

}

SharpenFilter::~SharpenFilter() {
}

int* SharpenFilter::procImage() {
	int pixR, pixG, pixB, newR, newG, newB, index;
	int laplacian[] = {0, -1, 0, -1, 4, -1, 0, -1, 0}; // 3 * 3 laplacian
	int maskSize = 3;
	int halfMaskSize = maskSize / 2;

	int *edgePixels = new int[width * height];
	memset(edgePixels, 0, width * height * sizeof(int));

	for (int i = halfMaskSize; i < height - halfMaskSize; i++)  {
		for (int k = halfMaskSize; k < width - halfMaskSize; k++)  {
			index = 0;
			newR = newG = newB = 0;
			for (int m = -halfMaskSize; m <= halfMaskSize; m++) {
				for (int n = -halfMaskSize; n <= halfMaskSize; n++) {

					Color pixColor(pixels[(i + n) * width + k + m]);
					pixR = pixColor.R();
					pixG = pixColor.G();
					pixB = pixColor.B();

					newR += pixR * laplacian[index];
					newG += pixG * laplacian[index];
					newB += pixB * laplacian[index];
					index++;
				}
			}

			newR = min(255, max(0, newR));
			newG = min(255, max(0, newG));
			newB = min(255, max(0, newB));

			edgePixels[i * width + k] = RGB2Color(newR, newG, newB);
		}
	}

	for (int i = 0; i < width * height; i++) {
		Color edgeColor(edgePixels[i]);
		Color originColor(pixels[i]);

		int r = min(255, max(0, edgeColor.R() + originColor.R()));
		int g = min(255, max(0, edgeColor.G() + originColor.G()));
		int b = min(255, max(0, edgeColor.B() + originColor.B()));

		pixels[i] = RGB2Color(r, g, b);
	}

	delete [] edgePixels;
	return pixels;
}

