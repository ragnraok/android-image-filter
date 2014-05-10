/*
 * SharpenFilter.cpp
 *
 *  Created on: 2014-4-12
 *      Author: ragnarok
 */


#include <stdlib.h>
#include <string.h>

#include "SharpenFilter.h"
#include "AverageSmoothFilter.h"

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
					int pixel_index = (i + n) * width + k + m;
					if (pixel_index < width * height) {
						Color pixColor(pixels[pixel_index]);
						pixR = pixColor.R();
						pixG = pixColor.G();
						pixB = pixColor.B();

						newR += pixR * laplacian[index];
						newG += pixG * laplacian[index];
						newB += pixB * laplacian[index];
						index++;
					}
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

int* SharpenFilter::highBoostSharpen() {
	int boostFactor = 1;
	int *blurPixels = new int[width * height];
	memcpy(blurPixels, pixels, width * height * sizeof(int));

	AverageSmoothFilter *smoothFilter = new AverageSmoothFilter(blurPixels, width, height);
	blurPixels = smoothFilter->procImage();

	int *edgePixels = new int[width * height];
	for (int i = 0; i < width * height; i++) {
		Color pixColor(pixels[i]);
		Color blurColor(blurPixels[i]);
		int edgeR = min(255, max(0, pixColor.R() - blurColor.R()));
		int edgeG = min(255, max(0, pixColor.G() - blurColor.G()));
		int edgeB = min(255, max(0, pixColor.B() - blurColor.B()));
		edgePixels[i] = RGB2Color(edgeR, edgeG, edgeB);
	}

	for (int i = 0; i < width * height; i++) {
		Color pixColor(pixels[i]);
		Color edgeColor(edgePixels[i]);
		int r = min(255, max(0, pixColor.R() + boostFactor * edgeColor.R()));
		int g = min(255, max(0, pixColor.G() + boostFactor * edgeColor.G()));
		int b = min(255, max(0, pixColor.B() + boostFactor * edgeColor.B()));
		pixels[i] = RGB2Color(r, g, b);
	}

	delete smoothFilter;
	delete [] edgePixels;

	return pixels;
}
