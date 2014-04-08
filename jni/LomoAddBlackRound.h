/*
 * LomoAddBlackRound.h
 *
 *  Created on: 2013-2-10
 *      Author: ragnarok
 */

#ifndef LOMOADDBLACKROUND_H_
#define LOMOADDBLACKROUND_H_

#include "Util.h"

double scaleFunc(double radius, double dis, double pixelsFalloff) {
	return 1 - pow(((dis - radius) / pixelsFalloff), 2);
}


void lomoAddBlackRound(int* pixels, int width, int height) {
	double radius = (width / 2) * 95 / 100;
	double centerX = width / 2;
	double centerY = height / 2;

	int currentPos;
	double pixelsFalloff = 10;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			double dis = sqrt(pow((centerX - x), 2) + pow(centerY - y, 2));
			currentPos = y * width + x;

			if (dis > radius) {
				Color color(pixels[currentPos]);
				int pixR = color.R();
				int pixG = color.G();
				int pixB = color.B();

				double scaler = scaleFunc(radius, dis, pixelsFalloff);

				scaler = abs(scaler);

				int newR = pixR - scaler;
				int newG = pixG - scaler;
				int newB = pixB - scaler;

				newR = min(255, max(0, newR));
				newG = min(255, max(0, newG));
				newB = min(255, max(0, newB));


				pixels[currentPos] = RGB2Color(newR, newG, newB);

			}
		}
	}
}



#endif /* LOMOADDBLACKROUND_H_ */
