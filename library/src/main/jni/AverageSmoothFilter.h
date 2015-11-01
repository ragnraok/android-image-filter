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

typedef struct _averageSmoothOptions {
	_averageSmoothOptions(int maskSize) {
		this->maskSize = maskSize;
	}
	int maskSize;
} AverageSmoothOptions;

class AverageSmoothFilter : public ImageFilter {
public:
	AverageSmoothFilter(int *pixels, int width, int height);
	AverageSmoothFilter(int *_pixels, int _width, int _height, AverageSmoothOptions options);
	virtual ~AverageSmoothFilter() {};
	int* procImage();
private:
	int maskSize;
};

#endif /* AVERAGESMOOTHFILTER_H_ */
