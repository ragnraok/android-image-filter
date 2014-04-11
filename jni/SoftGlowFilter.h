/*
 * SoftGlowFilter.h
 *
 *  Created on: 2013-2-13
 *      Author: ragnarok
 */

#ifndef SOFTGLOWFILTER_H_
#define SOFTGLOWFILTER_H_

#include "Util.h"
#include "ColorGetter.h"
#include "ImageFilter.h"
#include "GaussianBlurFilter.h"

class SoftGlowFilter : public ImageFilter {
public:
	SoftGlowFilter(int *_pixels, int _width, int _height, double _blurSigma = 2.0);
	int* procImage();
private:
	double blurSigma;
};


#endif /* SOFTGLOWFILTER_H_ */
