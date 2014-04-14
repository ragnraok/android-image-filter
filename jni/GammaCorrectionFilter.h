/*
 * GammaCorrectionFilter.h
 *
 *  Created on: 2014-4-13
 *      Author: ragnarok
 */

#ifndef GAMMACORRECTIONFILTER_H_
#define GAMMACORRECTIONFILTER_H_

#include "Util.h"
#include "ImageFilter.h"

#define GAMMA_TABLE_SIZE 256

typedef struct _gammaCorrectionOptions {
	_gammaCorrectionOptions(double g) {
		gamma = g;
	}
	double gamma;
} GammaCorrectionOptions;

class GammaCorrectionFilter : public ImageFilter {
public:
	GammaCorrectionFilter(int *pixels, int width, int height, GammaCorrectionOptions options);
	GammaCorrectionFilter(int *pixels, int width, int height, double gamma);
	GammaCorrectionFilter(int *pixels, int width, int height);
	int* procImage();
private:
	double gamma;
	double gammaTable[GAMMA_TABLE_SIZE]; // the gamma lookup table
	void initGammaTable();
};



#endif /* GAMMACORRECTIONFILTER_H_ */
