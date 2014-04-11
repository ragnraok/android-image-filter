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

class NeonFilter : public ImageFilter {
public:
	NeonFilter(int *_pixels, int _width, int _height, int r, int g, int b);
	int* procImage();
private:
	int neonR;
	int neonG;
	int neonB;
};

#endif /* NEONFILTER_H_ */
