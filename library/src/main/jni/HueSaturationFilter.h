/*
 * HueSaturationFilter.h
 *
 *  Created on: 2014-4-17
 *      Author: ragnarok
 */

#ifndef HUESATURATIONFILTER_H_
#define HUESATURATIONFILTER_H_

#include "ImageFilter.h"
#include "ColorTranslator.h"

class HueSaturationFilter : public ImageFilter {
public:
	HueSaturationFilter(int *pixels, int width, int height);
	~HueSaturationFilter();
	int* procImage();
	int* setHue(double hue);
	int* setSaturation(double saturation);
	int* setHueSaturation(double hue, double saturation);
	int* setHueSaturationIntesity(double hue, double saturation, double intesity);
private:
	HSI* pixelsHSI;
	void initPixelsHSI();
};




#endif /* HUESATURATIONFILTER_H_ */
