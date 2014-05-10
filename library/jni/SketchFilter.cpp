/*
 * SketchFilter.cpp
 *
 *  Created on: 2014-4-11
 *      Author: ragnarok
 */


#include "SketchFilter.h"

SketchFilter::SketchFilter(int *pixels, int width, int height):
	ImageFilter(pixels, width, height) {
	this->threshold = 7;
}

int* SketchFilter::procImage() {
	changeImageToGray(pixels, width, height);

	int *originPixels = new int[width * height];
	memcpy(originPixels, pixels, width * height * sizeof(int));

	int threshold = 7;
	for (int i = 1; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			Color centerColor(originPixels[i * width + j]);
			int centerGray = centerColor.R();

			int rightBottomIndex = (i + 1) * width + j + 1;
			if (rightBottomIndex < width * height) {
				Color rightBottomColor(originPixels[rightBottomIndex]);
				int rightBottomGray = rightBottomColor.R();
				if (abs(centerGray - rightBottomGray) >= threshold) {
					pixels[i * width + j] = RGB2Color(0, 0, 0); // black
				} else {
					pixels[i * width + j] = RGB2Color(255, 255, 255); // white
				}
			}

		}
	}

	delete[] originPixels;

	return pixels;
}

