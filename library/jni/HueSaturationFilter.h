/*
 * HueSaturationFilter.h
 *
 *  Created on: 2014-4-17
 *      Author: ragnarok
 */

#ifndef HUESATURATIONFILTER_H_
#define HUESATURATIONFILTER_H_

#include "ImageFilter.h"

class HueSaturationFilter : public ImageFilter {
public:
	HueSaturationFilter(int *pixels, int width, int height);
	int* procImage();
	int* setHue(double hue);
	int* setSaturation(double ratio);
};




#endif /* HUESATURATIONFILTER_H_ */
