/*
 * GothamFilter.h
 *
 *  Created on: 2014-4-18
 *      Author: ragnarok
 */

#ifndef GOTHAMFILTER_H_
#define GOTHAMFILTER_H_

#include "ColorGetter.h"
#include "ImageFilter.h"

#define GOTHAM_R 34
#define GOTHAM_G 43
#define GOTHAM_B 109

class GothamFilter : public ImageFilter {
public:
	GothamFilter(int *pixels, int width, int height);
	int* procImage();

private:
	double gothamHue;
	double saturationFactor;
	double gammaValue;
	double contrastValue;
};


#endif /* GOTHAMFILTER_H_ */
