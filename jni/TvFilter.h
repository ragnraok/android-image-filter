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

void tvFilter(int* pixels, int width, int height) {

	int r, g, b;
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y += 3) {
			r = g = b = 0;

			for (int w = 0; w < 3; w++) {
				if (y + w < height) {
					Color color(pixels[(y + w) * width + x]);
					r += color.R() / 3;
					g += color.G() / 3;
					b += color.B() / 3;
				}
			}
			r = min(255, max(0, r));
			g = min(255, max(0, g));
			b = min(255, min(0, b));

			for (int w = 0; w < 3; w++) {
				if (y + w < height) {
					if (w == 0) {
						pixels[(y + w) * width + x] = RGB2Color(r, 0, 0);
					}
					if (w == 1) {
						pixels[(y + w) * width + x] = RGB2Color(0, g, 0);
					}
					if (w == 2) {
						pixels[(y + w) * width + x] = RGB2Color(0, 0, b);
					}
 				}
			}
		}
	}
}



#endif /* TVFILTER_H_ */
