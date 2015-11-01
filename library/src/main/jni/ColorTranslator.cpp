/*
 * ColorTranslator.cpp
 *
 *  Created on: 2014-4-17
 *      Author: ragnarok
 */

#include <math.h>

#include "ColorTranslator.h"
#include "Util.h"

HSI ColorTranslator::RGB2HSI(double R, double G, double B) { // 0 ~ 255
	double r = R / COLOR_UPPER_BOUND;
	double g = G / COLOR_UPPER_BOUND;
	double b = B / COLOR_UPPER_BOUND;

	double theta = acos(
			((r - g) + (r - b)) * 0.5
					/ pow((pow((r - g), 2) + (r - b) * (g - b)), 0.5));
	theta = theta * 180 / PI;
	double h;
	if (b <= g) {
		h = theta;
	} else {
		h = 360 - theta;
	}

	double i = (r + g + b) / 3.0;

	double minColor = 0;
	minColor = r < g ? r : g;
	minColor = minColor < b ? minColor : b;
	double s = 1 - i / (r + g + b);

	return HSI(h, s, i);
}

RGB ColorTranslator::HSI2RGB(double h, double s, double i) {
	double r, g, b;
	if (h >= 0 && h < 120.0) {
		b = i * (1 - s);
		r = i * (1 + (s * cos(h * PI / 180.0)) / (cos((60 - h) * PI / 180.0)));
		g = 3 * i - (r + b);
		return RGB(int(r * COLOR_UPPER_BOUND), int(g * COLOR_UPPER_BOUND), int(b * COLOR_UPPER_BOUND));
	} else if (h >= 120.0 && h < 240.0) {
		h = h - 120;
		r = i * (1 - s);
		g = i * (1 + (s * cos(h * PI / 180.0)) / (cos((60 - h) * PI / 180.0)));
		b = 3 * i - (r + g);
		return RGB(int(r * COLOR_UPPER_BOUND), int(g * COLOR_UPPER_BOUND), int(b * COLOR_UPPER_BOUND));
	} else if (h >= 240.0 && h <= 360.0) {
		h = h - 240;
		g = i * (1 - s);
		b = i * (1 + (s * cos(h * PI / 180.0)) / (cos((60 - h) * PI / 180.0)));
		r = 3 * i - (g + b);
		return RGB(int(r * COLOR_UPPER_BOUND), int(g * COLOR_UPPER_BOUND), int(b * COLOR_UPPER_BOUND));
	}
	//LOGE("HSI2RGB, rgb is -1");
	return RGB(-1, -1, -1);
}

bool ColorTranslator::checkRGB(double r, double g, double b) {
	if (r > 255 || r < 0) {
		return false;
	}
	if (g > 255 || g < 0) {
		return false;
	}
	if (b > 255 || b < 0) {
		return false;
	}
	return true;
}

bool ColorTranslator::checkRGB(RGB rgb) {
	if (rgb.r > 255 || rgb.r < 0) {
		return false;
	}
	if (rgb.g > 255 || rgb.g < 0) {
		return false;
	}
	if (rgb.b > 255 || rgb.b < 0) {
		return false;
	}
	return true;
}
