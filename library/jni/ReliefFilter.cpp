/*
 * ReliefFilter.cpp
 *
 *  Created on: 2014-4-12
 *      Author: ragnarok
 */

#include "ReliefFilter.h"
#include "SharpenFilter.h"

ReliefFilter::ReliefFilter(int *pixels, int width, int height):
	ImageFilter(pixels, width, height),
	colorCompensation(100) {

}

int* ReliefFilter::procImage() {
	SharpenFilter *sharpenFilter = new SharpenFilter(pixels, width, height);
	pixels = sharpenFilter->highBoostSharpen();

	Color preColor(pixels[0]);

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			Color currentColor(pixels[j * width + i]);
			int r = currentColor.R() - preColor.R() + colorCompensation;
			int g = currentColor.G() - preColor.G() + colorCompensation;
			int b = currentColor.B() - preColor.B() + colorCompensation;
			r = min(255, max(r, 0));
			g = min(255, max(g, 0));
			b = min(255, max(b, 0));

			int index = j * width + i;
			if (index < width * height) {
				pixels[index] = ARGB2Color(currentColor.alpha(), r, g, b);
			}
			preColor = currentColor;
		}
	}

	delete sharpenFilter;
	return pixels;
}


