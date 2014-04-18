/*
 * GammaCorrectionFilter.cpp
 *
 *  Created on: 2014-4-13
 *      Author: ragnarok
 */

#include <math.h>

#include "GammaCorrectionFilter.h"
#include "ColorGetter.h"

GammaCorrectionFilter::GammaCorrectionFilter(int *pixels, int width, int height):
	ImageFilter(pixels, width, height),
	gamma(1) {
	initGammaTable();
}

GammaCorrectionFilter::GammaCorrectionFilter(int *pixels, int width, int height, GammaCorrectionOptions options):
	ImageFilter(pixels, width, height),
	gamma(options.gamma) {
	initGammaTable();
}

GammaCorrectionFilter::GammaCorrectionFilter(int *pixels, int width, int height, double _gamma):
	ImageFilter(pixels, width, height),
	gamma(_gamma) { // normally gamma is 1/2.2=0.45
	initGammaTable();
}

void GammaCorrectionFilter::initGammaTable() {
	double inverseGamma = 1.0 / gamma;
	for (int i = 0; i < GAMMA_TABLE_SIZE; i++) {
		gammaTable[i] = pow((double)(i / COLOR_UPPER_BOUND), inverseGamma) * COLOR_UPPER_BOUND;
	}
}

int* GammaCorrectionFilter::procImage() {
	for (int i = 0; i < width * height; i++) {
		Color color(pixels[i]);
		int r = gammaTable[color.R()];
		int g = gammaTable[color.G()];
		int b = gammaTable[color.B()];
		pixels[i] = RGB2Color(r, g, b);
	}
	return pixels;
}



