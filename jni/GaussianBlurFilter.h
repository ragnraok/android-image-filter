/*
 * GaussianBlurFilter.h
 *
 *  Created on: 2014-4-11
 *      Author: ragnarok
 */

#ifndef GAUSSIANBLURFILTER_H_
#define GAUSSIANBLURFILTER_H_

#include "ImageFilter.h"
#include "Util.h"

typedef struct _gaussianBlurOptions {
	_gaussianBlurOptions(double s) {
		this->sigma = s;
	}
	double sigma;
} GaussianBlurOptions;

class GaussianBlurFilter : public ImageFilter {
public:
	GaussianBlurFilter(int *_pixels, int _width, int _height, GaussianBlurOptions opions);
	~GaussianBlurFilter() {
		this->sigma = 0;
		delete [] kernel;
		kernel = NULL;
	}
	int* procImage();
private:
	double sigma;
	double *kernel;
	int kernelSum;
	int maskSize;
};



#endif /* GAUSSIANBLURFILTER_H_ */
