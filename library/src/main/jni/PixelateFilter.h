/*
 * PixelateFilter.h
 *
 *  Created on: 2014-4-12
 *      Author: ragnarok
 */

#ifndef PIXELATEFILTER_H_
#define PIXELATEFILTER_H_

#include "Util.h"
#include "ColorGetter.h"
#include "ImageFilter.h"

typedef struct _pixelateOptions {
	_pixelateOptions(int p):
		pixelateSize(p) {}
	int pixelateSize;
} PixelateOptions;

class PixelateFilter : public ImageFilter {
public:
	PixelateFilter(int *pixels, int width, int height);
	PixelateFilter(int *pixels, int width, int height, PixelateOptions options);
	int* procImage();
private:
	int pixelSize;
	Color getRectColor(int col, int row);
	void fillRectColor(Color &color, int col, int row);
};


#endif /* PIXELATEFILTER_H_ */
