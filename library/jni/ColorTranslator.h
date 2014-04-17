/*
 * ColorTranslator.h
 *
 *  Created on: 2014-4-17
 *      Author: ragnarok
 */

#ifndef COLORTRANSLATOR_H_
#define COLORTRANSLATOR_H_

#include "ColorGetter.h"

typedef struct _rgb { // 0 ~ 225
	_rgb(int r, int g, int b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	int r;
	int g;
	int b;
} RGB;

typedef struct _hsi {
	_hsi(double h, double s, double i) {
		this->h = h;
		this->s = s;
		this->i = i;
	}
	double h; // 0 ~ 360
	double s; // 0 ~ 1
	double i; // 0 ~ 1
} HSI;

class ColorTranslator {
	static HSI RGB2HSI(double r, double g, double b);
	static RGB HSI2RGB(double h, double s, double i);

};



#endif /* COLORTRANSLATOR_H_ */
