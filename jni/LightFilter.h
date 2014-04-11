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

class LightFilter : public ImageFilter {
public:
	LightFilter(int *_pixels, int _width, int _height);
	LightFilter(int *_pixels, int _width, int _height, int centerX, int centerY, int radius);
	int* procImage();
private:
	int centerX;
	int centerY;
	int radius;
};


#endif /* LIGHTFILTER_H_ */
