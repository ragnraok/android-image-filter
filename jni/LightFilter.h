/*
 * LightFilter.h
 *
 *  Created on: 2013-2-9
 *      Author: ragnarok
 */

#ifndef LIGHTFILTER_H_
#define LIGHTFILTER_H_

#include "Util.h"
#include "ColorGetter.h"

#include <math.h>


// light filter function
void lightFilter(int* pixels, int width, int height) {
	int pixR, pixG, pixB;
	int newR, newG, newB;

	int centerX = width / 3;
	int centerY = height / 3;
	int radius = min(centerX, centerY);

	float strength = 150;
	int pos = 0;

	for (int i = 1; i < height - 1; i++) {
		for (int k = 1; k < width - 1; k++) {
			pos = i * width + k;
			Color pixelColor = Color(pixels[pos]);

			pixR = pixelColor.R();
			pixG = pixelColor.G();
			pixB = pixelColor.B();

			newR = pixR;
			newG = pixG;
			newB = pixB;

			int distance = (int) (pow((centerY - i), 2) + pow(centerX - k, 2));
			if (distance < radius * radius) {
				int result = (int) (strength * (1.0 - sqrt(distance) / radius));
				newR = pixR + result;
				newG = pixG + result;
				newB = pixB + result;
			}
			newR = min(255, max(0, newR));
			newG = min(255, max(0, newG));
			newB = min(255, max(0, newB));

			pixels[pos] = ARGB2Color(255, newR, newG, newB);
		}
	}
}


#endif /* LIGHTFILTER_H_ */
