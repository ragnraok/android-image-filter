/*
 * LightFilter.cpp
 *
 *  Created on: 2014-4-11
 *      Author: ragnarok
 */

#include "LightFilter.h"

LightFilter::LightFilter(int *_pixels, int _width, int _height):
	ImageFilter(_pixels, _width, _height) {
	centerX = width / 2;
	centerY = height / 2;
	radius = min(centerX, centerY);
}

LightFilter::LightFilter(int *_pixels, int _width, int _height, LightFilterOptions options):
	ImageFilter(_pixels, _width, _height),
	centerX(options.centerX),
	centerY(options.centerY),
	radius(options.radius) {

}

int* LightFilter::procImage() {
	int pixR, pixG, pixB;
	int newR, newG, newB;

	float strength = 150;
	int pos = 0;

	for (int i = 1; i < height - 1; i++) {
		for (int k = 1; k < width - 1; k++) {
			pos = i * width + k;
			if (pos < width * height) {
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
	return pixels;
}
