/*
 * NeonFilter.h
 *
 *  Created on: 2013-2-9
 *      Author: ragnarok
 */

#ifndef NEONFILTER_H_
#define NEONFILTER_H_

#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "Util.h"
#include "ColorGetter.h"
#include "ImageFilter.h"

typedef struct _neonFilterOptions {
	_neonFilterOptions(int r, int g, int b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	int r;
	int g;
	int b;
} NeonFilterOptions;

class NeonFilter : public ImageFilter {
public:
	NeonFilter(int *_pixels, int _width, int _height, NeonFilterOptions options);
	int* procImage();
private:
	int neonR;
	int neonG;
	int neonB;
};

#endif /* NEONFILTER_H_ */
