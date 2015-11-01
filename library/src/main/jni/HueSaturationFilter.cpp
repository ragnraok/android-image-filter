/*
 * HueSaturationFilter.cpp
 *
 *  Created on: 2014-4-17
 *      Author: ragnarok
 */

#include "HueSaturationFilter.h"
#include "ColorGetter.h"
#include "ColorTranslator.h"

HueSaturationFilter::HueSaturationFilter(int* pixels, int width, int height):
	ImageFilter(pixels, width, height) {
	pixelsHSI = new HSI[width * height];

	initPixelsHSI();
}

HueSaturationFilter::~HueSaturationFilter() {
	delete [] pixelsHSI;
	pixelsHSI = NULL;
}

void HueSaturationFilter::initPixelsHSI() {
	for (int i = 0; i < width * height; i++) {
		Color color(pixels[i]);
		HSI hsi = ColorTranslator::RGB2HSI(color.R(), color.G(), color.B());
		pixelsHSI[i] = hsi;
	}
}

int* HueSaturationFilter::procImage() {
	return NULL;
}

int* HueSaturationFilter::setHue(double hue) {
	for (int i = 0; i < width * height; i++) {
		HSI hsi = pixelsHSI[i];
		double h = hsi.h;
		h = hue;
		//h = min(360.0, max(0.0, h));
		if (h > 360) {
			h = h - 360;
		} else if (h < 0) {
			h = h + 360;
		}
		pixelsHSI[i] = HSI(h, hsi.s, hsi.i);
		RGB rgb = ColorTranslator::HSI2RGB(h, hsi.s, hsi.i);
		if (ColorTranslator::checkRGB(rgb)) {
			pixels[i] = RGB2Color(rgb.r, rgb.g, rgb.b);
		}
	}
	return pixels;
}

int* HueSaturationFilter::setSaturation(double saturation) {
	for (int i = 0; i < width * height; i++) {
		HSI hsi = pixelsHSI[i];
		double s = hsi.s;
		s = saturation;
		s = min(1.0, max(0.0, s));
		pixelsHSI[i] = HSI(hsi.h, s, hsi.i);
		RGB rgb = ColorTranslator::HSI2RGB(hsi.h, s, hsi.i);
		if (ColorTranslator::checkRGB(rgb)) {
			pixels[i] = RGB2Color(rgb.r, rgb.g, rgb.b);
		}
	}
	return pixels;
}

int* HueSaturationFilter::setHueSaturation(double hue, double saturation) {
	for (int i = 0; i < width * height; i++) {
		HSI hsi = pixelsHSI[i];
		double h = hsi.h;
		h = hue;
		if (h > 360) {
			h = h - 360;
		} else if (h < 0) {
			h = h + 360;
		}
		double s = hsi.s;
		s = saturation;
		s = min(1.0, max(0.0, s));
		pixelsHSI[i] = HSI(h, s, hsi.i);
		RGB rgb = ColorTranslator::HSI2RGB(h, s, hsi.i);
		if (ColorTranslator::checkRGB(rgb)) {
			pixels[i] = RGB2Color(rgb.r, rgb.g, rgb.b);
		}
	}
	return pixels;
}

int* HueSaturationFilter::setHueSaturationIntesity(double hue, double saturation, double intensity) {
	for (int i = 0; i < width * height; i++) {
		HSI hsi = pixelsHSI[i];
		double h = hsi.h;
		h = hue;
		if (h > 360) {
			h = h - 360;
		} else if (h < 0) {
			h = h + 360;
		}

		double s = hsi.s;
		s = saturation;
		s = min(1.0, max(0.0, s));

		double newI = hsi.i;
		newI = intensity;
		newI = min(1.0, max(0.0, newI));

		pixelsHSI[i] = HSI(h, s, newI);
		RGB rgb = ColorTranslator::HSI2RGB(h, s, hsi.i);
		if (ColorTranslator::checkRGB(rgb)) {
			pixels[i] = RGB2Color(rgb.r, rgb.g, rgb.b);
		}
	}
	return pixels;
}
