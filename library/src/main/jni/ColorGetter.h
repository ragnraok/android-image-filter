/*
 * ColorGetter.h
 *
 *  Created on: 2013-2-9
 *      Author: ragnarok
 */

#ifndef COLORGETTER_H_
#define COLORGETTER_H_

#include <math.h>

#define COLOR_UPPER_BOUND 255.0
#define COLOR_LOWER_BOUND 0.0

static inline int ARGB2Color(int alpha, int r, int g, int b) {
	return alpha << 24 | r << 16 | g << 8 | b;
}

static inline int RGB2Color(int r, int g, int b) {
	return 255 << 24 | r << 16 | g << 8 | b;
}

class Color {
public:
	Color():color(-1), h(-1), s(-1), i(-1) {}
	Color(int color):
		color(color),
		h(-1), s(-1), i(-1){}
	Color(int r, int g, int b): h(-1), s(-1), i(-1) { color = RGB2Color(r, g, b); }
	int alpha() { return (color & 0xFF000000) >> 24; }
	int R() { return (color & 0x00FF0000) >> 16; }
	int G() { return (color & 0X0000FF00) >> 8; }
	int B() { return (color & 0x000000FF); }
	int grayScale() {
		return (R() + G() + B()) / 3;
	}
	int getColor() { return color; }
	bool isInvalid() { return color == -1; }
	double H() {
		if (h == -1) {
			double r = R() / COLOR_UPPER_BOUND;
			double g = G() / COLOR_UPPER_BOUND;
			double b = B() / COLOR_UPPER_BOUND;

			double theta = acos(
					((r - g) + (r - b)) * 0.5 /
					pow((pow((r - g), 2) + (r - b) * (g - b)), 0.5)
					);
			if (b <= g) {
				h = theta;
			} else {
				h = 360 - theta;
			}
		}
		return h;
	}
	double S() {
		if (s == -1) {
			int minColor = 0;
			minColor = R() < G() ? R() : G();
			minColor = minColor < B() ? minColor : B();

			double r = R() / COLOR_UPPER_BOUND;
			double g = G() / COLOR_UPPER_BOUND;
			double b = B() / COLOR_UPPER_BOUND;
			minColor = minColor / COLOR_UPPER_BOUND;

			s = 1 - (3.0 * minColor) / (r + g + b);
		}
		return s;
	}
	double I() {
		if (i == -1) {
			double r = R() / COLOR_UPPER_BOUND;
			double g = G() / COLOR_UPPER_BOUND;
			double b = B() / COLOR_UPPER_BOUND;

			i = (r + g + b) / 3.0;
		}
		return i;
	}
private:
	int color;
	double h;
	double s;
	double i;
};



#endif /* COLORGETTER_H_ */
