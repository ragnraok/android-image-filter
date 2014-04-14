/*
 * OilFilter.cpp
 *
 *  Created on: 2014-4-11
 *      Author: ragnarok
 */

#include <time.h>
#include "OilFilter.h"

OilFilter::OilFilter(int* pixels, int width, int height):
	ImageFilter(pixels, width, height) {
	model = 8;
}

int* OilFilter::procImage() {
	int *originPixels = new int[width * height];
	memcpy(originPixels, pixels, width * height * sizeof(int));

	srand(time(NULL));

	int i, j, originI, originJ;
	if (width > height) {
		i = width - model - 1;
		j = height - model - 1;
	} else {
		i = height - model - 1;
		j = width - model - 1;
	}
	originI = i;
	originJ = j;

	while (i > model) {
		j = originJ;
		while (j > model) {
			int pos = rand() % model;
			int otherPos = (i + pos) * width + j + pos;
			if (otherPos < width * height) {
				unsigned color = originPixels[otherPos];
				pixels[i * width + j] = color;
			}
			j--;

		}
		i--;
	}

	delete [] originPixels;

	return pixels;
}
