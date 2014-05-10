/*
 * HDRFilter.cpp
 *
 *  Created on: 2014-4-11
 *      Author: ragnarok
 */

#include "HDRFilter.h"
#include "GaussianBlurFilter.h"
//#include "AverageSmoothFilter.h"
#include "SharpenFilter.h"

int* HDRFilter::procImage() {
	int *smoothPixels = new int[this->height * this->width];
	memcpy(smoothPixels, this->pixels, width * height * sizeof(int));

	GaussianBlurFilter *blurFilter = new GaussianBlurFilter(smoothPixels, width,
			height, 0.6);
	smoothPixels = blurFilter->procImage();

//	AverageSmoothFilter *blurFilter = new AverageSmoothFilter(smoothPixels, width, height);
//	smoothPixels = blurFilter->procImage();

	double newR = 0, newG = 0, newB = 0;
	double blurA = 0;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			int index = row * width + col;
			if (index < width * height) {
				Color originColor(pixels[row * width + col]);
				Color smoothColor(smoothPixels[row * width + col]);
				newR = newG = newB = blurA = 0;
				if (smoothColor.R() / 255.0 <= 0.5) {
					newR = 2 * (smoothColor.R() / 255.0)
							* (originColor.R() / 255.0);
				}

				else {
					newR = 1 - 2 * (1 - originColor.R() / 255.0) * (1 - smoothColor.R() / 255.0);
				}

				if (smoothColor.G() / 255.0 <= 0.5) {
					newG = 2 * (smoothColor.G() / 255.0) * (originColor.G() / 255.0);
				}

				else {
					newG = 1 - 2 * (1 - originColor.G() / 255.0) * (1 - smoothColor.G() / 255.0);
				}

				if (smoothColor.B() / 255.0 <= 0.5) {
					newB = 2 * (smoothColor.B() / 255.0) * (originColor.B() / 255.0);
				}

				else {
					newB = 1 - 2 * (1 - originColor.B() / 255.0) * (1 - smoothColor.B() / 255.0);
				}

				blurA = smoothColor.alpha();

				pixels[index] = ARGB2Color(blurA, newR * 255, newG * 255, newB * 255);
			}

		}
	}

	delete blurFilter;

	SharpenFilter *sharpenFilter = new SharpenFilter(pixels, width, height);
	pixels = sharpenFilter->procImage();

	delete sharpenFilter;

	return pixels;
}

