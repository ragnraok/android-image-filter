/*
 * LightFilter.h
 *
 *  Created on: 2013-2-9
 *      Author: ragnarok
 */

#ifndef LIGHTFILTER_H_
#define LIGHTFILTER_H_

#include <math.h>

#include "Util.h"
#include "ColorGetter.h"
#include "ImageFilter.h"

typedef struct _lightFilterOptions {
	_lightFilterOptions(int centerX, int centerY, int radius) {
		this->centerX = centerX;
		this->centerY = centerY;
		this->radius = radius;
	}
	int centerX;
	int centerY;
	int radius;
} LightFilterOptions;

class LightFilter : public ImageFilter {
public:
	LightFilter(int *_pixels, int _width, int _height);
	LightFilter(int *_pixels, int _width, int _height, LightFilterOptions options);
	int* procImage();
private:
	int centerX;
	int centerY;
	int radius;
};


#endif /* LIGHTFILTER_H_ */
