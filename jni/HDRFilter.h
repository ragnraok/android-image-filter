/*
 * HDRFilter.h
 *
 *  Created on: 2013-2-10
 *      Author: ragnarok
 */

#ifndef HDRFILTER_H_
#define HDRFILTER_H_

#include "Util.h"
#include "DiscreteGaussianBlur.h"

void hdrFilter(int* pixels, int width, int height) {
	int* smoothPixels = new int[width * height];
	memcpy(smoothPixels, pixels, width * height * sizeof(int));

	//discreteGaussianBlur(smoothPixels, width, height);
	discreteGaussianBlurSigma(pixels, width, height, 1);

	double newR = 0, newG = 0, newB = 0;
	double blurA = 0;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			Color originColor(pixels[row * width + col]);
			Color smoothColor(smoothPixels[row * width + col]);
			newR = newG = newB = blurA = 0;
			if (smoothColor.R() / 255.0 <= 0.5)
				newR = 2 * (smoothColor.R() / 255.0) * (originColor.R() / 255.0);
			else
				newR = 1 - 2 * (1 - originColor.R() / 255.0) * (1 - smoothColor.R() / 255.0);

			if (smoothColor.G() / 255.0 <= 0.5)
				newG = 2 * (smoothColor.G() / 255.0) * (originColor.G() / 255.0);
			else
				newG = 1 - 2 * (1 - originColor.G() / 255.0) * (1 - smoothColor.G() / 255.0);

			if (smoothColor.B() / 255.0 <= 0.5)
				newB = 2 * (smoothColor.B() / 255.0) * (originColor.B() / 255.0);
			else
				newB = 1 - 2 * (1 - originColor.B() / 255.0) * (1 - smoothColor.B() / 255.0);

			blurA = smoothColor.alpha();

			pixels[row * width + col] = ARGB2Color(blurA, newR * 255, newG * 255, newB * 255);
		}
	}
}

#endif /* HDRFILTER_H_ */
