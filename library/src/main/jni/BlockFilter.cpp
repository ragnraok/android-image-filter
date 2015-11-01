/*
 * BlockFilter.cpp
 *
 *  Created on: 2014-4-13
 *      Author: ragnarok
 */

#include "BlockFilter.h"

BlockFilter::BlockFilter(int *pixels, int width, int height):
	ImageFilter(pixels, width, height),
	threshold(100) {

}

int* BlockFilter::procImage() {
	for (int i = 0; i < width * height; i++) {
		Color color(pixels[i]);
		int gray = color.grayScale();
		if (gray >= threshold) {
			pixels[i] = RGB2Color(255, 255, 255);
		} else {
			pixels[i] = RGB2Color(0, 0, 0);
		}
	}
	return pixels;
}

