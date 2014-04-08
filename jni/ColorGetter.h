/*
 * ColorGetter.h
 *
 *  Created on: 2013-2-9
 *      Author: ragnarok
 */

#ifndef COLORGETTER_H_
#define COLORGETTER_H_

class Color {
public:
	Color(int color):
		color(color)
		{};
	int alpha() { return (color & 0xFF000000) >> 24; }
	int R() { return (color & 0x00FF0000) >> 16; };
	int G() { return (color & 0X0000FF00) >> 8; }
	int B() { return (color & 0x000000FF); }
	int grayScale() {
		return (R() + G() + B()) / 3;
	}
private:
	int color;
};

static inline int ARGB2Color(int alpha, int r, int g, int b) {
	return alpha << 24 | r << 16 | g << 8 | b;
}

static inline int RGB2Color(int r, int g, int b) {
	return 255 << 24 | r << 16 | g << 8 | b;
}

#endif /* COLORGETTER_H_ */
