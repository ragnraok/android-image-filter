/*
 * AverageSmoothFilter.h
 *
 *  Created on: 2014-4-10
 *      Author: ragnarok
 */

#ifndef AVERAGESMOOTHFILTER_H_
#define AVERAGESMOOTHFILTER_H_

#include "ImageFilter.h"
#include "Util.h"

class AverageSmoothFilter : public ImageFilter {
public:
	AverageSmoothFilter(int *_pixels, int _height, int _width, int _maskSize = 5);
	virtual ~AverageSmoothFilter() {};
	int* procImage();
private:
	int maskSize;
};

#endif /* AVERAGESMOOTHFILTER_H_ */
