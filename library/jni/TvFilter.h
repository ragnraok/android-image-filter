/*
 * TvFilter.h
 *
 *  Created on: 2013-2-10
 *      Author: ragnarok
 */

#ifndef TVFILTER_H_
#define TVFILTER_H_

#include "Util.h"
#include "ColorGetter.h"
#include "ImageFilter.h"

class TvFilter : public ImageFilter {
public:
	TvFilter(int *pixels, int width, int height);
	int* procImage();
private:
	int gap;
};



#endif /* TVFILTER_H_ */
