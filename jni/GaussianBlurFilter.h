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

class GaussianBlurFilter : public ImageFilter {
public:
	GaussianBlurFilter(int *_pixels, int _width, int _height, double _sigma = 2.0);
	~GaussianBlurFilter() {
		this->sigma = 0;
		delete [] kernel;
		kernel = NULL;
	}
	int* procImage();
private:
	double sigma;
	double *kernel;
};



#endif /* GAUSSIANBLURFILTER_H_ */
