/*
 * ColorTranslator.cpp
 *
 *  Created on: 2014-4-17
 *      Author: ragnarok
 */

#include <math.h>

#include "ColorTranslator.h"
#include "Util.h"

HSI ColorTranslator::RGB2HSI(double r, double g, double b) {
	r = r / COLOR_UPPER_BOUND;
	g = g / COLOR_UPPER_BOUND;
	b = b / COLOR_UPPER_BOUND;

	double theta = acos(
			((r - g) + (r - b)) * 0.5
					/ pow((pow((r - g), 2) + (r - b) * (g - b)), 0.5));
	double h;
	if (b <= g) {
		h = theta;
	} else {
		h = 360 - theta;
	}

	double minColor = 0;
	minColor = r < g ? r : g;
	minColor = minColor < b ? minColor : b;
	double s = 1 - (3.0 * minColor) / (r + g + b);

	double i = (r + g + b) / 3.0;

	return HSI(h, s, i);
}

RGB ColorTranslator::HSI2RGB(double h, double s, double i) {
	double r, g, b;
	if (h >= 0 && h < 120) {
		b = i * (1 - s);
		r = i * (1 + (s * cos(h * PI / 180.0)) / (cos((60 - h) * PI / 180.0)));
		g = 3 * i - (r + b);
		return RGB(int(r * COLOR_UPPER_BOUND), int(g * COLOR_UPPER_BOUND), int(b * COLOR_UPPER_BOUND));
	} else if (h >= 120 && h < 240) {
		h = h - 120;
		r = i * (1 - s);
		g = i * (1 + (s * cos(h * PI / 180.0)) / (cos((60 - h) * PI / 180.0)));
		b = 3 * i - (r + g);
		return RGB(int(r * COLOR_UPPER_BOUND), int(g * COLOR_UPPER_BOUND), int(b * COLOR_UPPER_BOUND));
	} else if (h >= 240 && h <= 360) {
		h = h - 240;
		g = i * (1 - s);
		b = i * (1 + (s * cos(h * PI / 180.0)) / (cos((60 - h) * PI / 180.0)));
		r = 3 * i - (g + b);
		return RGB(int(r * COLOR_UPPER_BOUND), int(g * COLOR_UPPER_BOUND), int(b * COLOR_UPPER_BOUND));
	}
	return RGB(-1, -1, -1);
}
