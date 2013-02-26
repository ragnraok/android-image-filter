/*
 * BrightContrastFilter.h
 *
 *  Created on: 2013-2-13
 *      Author: ragnarok
 */

#ifndef BRIGHTCONTRASTFILTER_H_
#define BRIGHTCONTRASTFILTER_H_

#include "Util.h"
#include "ColorGetter.h"

void brightContrast(int* pixels, int width, int height) {
	int pixR = 0, pixG = 0, pixB = 0;
	int newR = 0, newG = 0, newB = 0;
	int factor = 255 / 4;
	int contrastFactor = 16384 + 1;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			Color color(pixels[row * width + col]);
			pixR = color.R();
			pixG = color.G();
			pixB = color.B();

			//newR = pixR + factor;
			//newG = pixG + factor;
			//newB = pixB + factor;

			newR = min(255, max(0, newR));
			newG = min(255, max(0, newG));
			newB = min(255, max(0, newB));

			newR = newR - 128;
			newG = newG - 128;
			newB = newB - 128;

			newR = (newR * contrastFactor) >> 15;
			newG = (newG * contrastFactor) >> 15;
			newB = (newB * contrastFactor) >> 15;

			newR = newR + 128;
			newG = newG + 128;
			newB = newB + 128;

			newR = min(255, max(0, newR));
			newG = min(255, max(0, newG));
			newB = min(255, max(0, newB));

			pixels[row * width + col] = RGB2Color(newR, newG, newB);
		}
	}
}



#endif /* BRIGHTCONTRASTFILTER_H_ */
