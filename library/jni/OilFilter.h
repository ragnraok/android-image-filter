/*
 * OldFilter.h
 *
 *  Created on: 2013-2-10
 *      Author: ragnarok
 */

#ifndef OLDFILTER_H_
#define OLDFILTER_H_

#include <stdlib.h>

#include "Util.h"
#include "ImageFilter.h"

#define OIL_FILTER_LEVEL 256
#define OIL_RANGE 10

typedef struct _oilFilterOptions {
	int oilRange;
	_oilFilterOptions(int range) {
		oilRange = range;
	}
} OilFilterOptions;

class OilFilter : public ImageFilter {
public:
	OilFilter(int *_pixels, int _width, int _height);
	OilFilter(int *pixels, int width, int height, OilFilterOptions options);
	int* procImage();
private:
	int oilRange;
};


#endif /* OLDFILTER_H_ */
