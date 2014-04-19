/*
 * GothamFilter.cpp
 *
 *  Created on: 2014-4-18
 *      Author: ragnarok
 */

#include "GothamFilter.h"
#include "ColorTranslator.h"
#include "HueSaturationFilter.h"
#include "GammaCorrectionFilter.h"
#include "BrightContrastFilter.h"
#include "Util.h"

GothamFilter::GothamFilter(int* pixels, int width, int height):
	ImageFilter(pixels, width, height) {

	HSI gothamHSI = ColorTranslator::RGB2HSI(GOTHAM_R, GOTHAM_G, GOTHAM_B);
	gothamHue = 233.69;

	LOGI("gothamHue = %f", gothamHue);

	saturationFactor = 0.2;
	gammaValue = 0.7;
	contrastValue = 1.2;
}

int* GothamFilter::procImage() {

	BrightContrastFilter *brightContrastFilter = new BrightContrastFilter(pixels, width, height);
	this->pixels = brightContrastFilter->setBrightness(-60);

	GammaCorrectionFilter *gammaCorrectionFilter = new GammaCorrectionFilter(pixels, width, height, gammaValue);
	this->pixels = gammaCorrectionFilter->procImage();

	HueSaturationFilter *hueSaturationFilter = new HueSaturationFilter(pixels, width, height);
	this->pixels = hueSaturationFilter->setSaturation(saturationFactor);
	this->pixels = hueSaturationFilter->setHue(gothamHue);

	this->pixels = brightContrastFilter->setContrast(contrastValue);

	delete gammaCorrectionFilter;
	delete brightContrastFilter;
	delete hueSaturationFilter;

	return pixels;
}
