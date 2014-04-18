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
}

HueSaturationFilter::~HueSaturationFilter() {

}

int* HueSaturationFilter::procImage() {
	return NULL;
}

int* HueSaturationFilter::setHue(double hue) {
	for (int i = 0; i < width * height; i++) {
		Color color(pixels[i]);
		HSI hsi = ColorTranslator::RGB2HSI(color.R(), color.G(), color.B());
		double h = hsi.h;
		h = hue;
		//h = min(360.0, max(0.0, h));
		if (h > 360) {
			h = h - 360;
		} else if (h < 0) {
			h = h + 360;
		}
		RGB rgb = ColorTranslator::HSI2RGB(h, hsi.s, hsi.i);
		if (ColorTranslator::checkRGB(rgb)) {
			pixels[i] = RGB2Color(rgb.r, rgb.g, rgb.b);
		}
	}
	return pixels;
}

int* HueSaturationFilter::setSaturation(double saturation) {
	for (int i = 0; i < width * height; i++) {
		Color color(pixels[i]);
		HSI hsi = ColorTranslator::RGB2HSI(color.R(), color.G(), color.B());
		double s = hsi.s;
		s = saturation;
		s = min(1.0, max(0.0, s));
		RGB rgb = ColorTranslator::HSI2RGB(hsi.h, s, hsi.i);
		if (ColorTranslator::checkRGB(rgb)) {
			pixels[i] = RGB2Color(rgb.r, rgb.g, rgb.b);
		}
	}
	return pixels;
}
