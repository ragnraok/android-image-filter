/*
 * SketchFilter.h
 *
 *  Created on: 2013-3-18
 *      Author: ragnarok
 */

#ifndef SKETCHFILTER_H_
#define SKETCHFILTER_H_

#include <stdlib.h>

#include "ColorGetter.h"
#include "Util.h"
#include "ImageFilter.h"

class SketchFilter : public ImageFilter {
public:
	SketchFilter(int *_pixels, int _width, int _height);
	int* procImage();
private:
	int threshold;
};


#endif /* SKETCHFILTER_H_ */
