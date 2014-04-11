/*
 * LomoAddBlackRound.h
 *
 *  Created on: 2013-2-10
 *      Author: ragnarok
 */

#ifndef LOMOADDBLACKROUND_H_
#define LOMOADDBLACKROUND_H_

#include "Util.h"
#include "ImageFilter.h"
#include "ColorGetter.h"

class LomoAddBlackRound : public ImageFilter {
public:
	LomoAddBlackRound(int *_pixels, int _width, int _height, double _roundRadius);
	int* procImage();
private:
	double roundRadius;
	double pixelsFalloff;
	double scaleFunc(double distance);
};


#endif /* LOMOADDBLACKROUND_H_ */
