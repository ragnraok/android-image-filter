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

class OilFilter : public ImageFilter {
public:
	OilFilter(int *_pixels, int _width, int _height);
	int* procImage();
private:
	int model;
};


#endif /* OLDFILTER_H_ */
