/*
 * MotionBlurFilter.cpp
 *
 *  Created on: 2014-4-14
 *      Author: ragnarok
 */

#include <stdlib.h>

#include "MotionBlurFilter.h"

MotionBlurFilter::MotionBlurFilter(int* pixels, int width, int height):
	ImageFilter(pixels, width, height) {
	xSpeed = 0;
	ySpeed = 0;
	procSpeed();
}

MotionBlurFilter::MotionBlurFilter(int* pixels, int width, int height, int x, int y):
	ImageFilter(pixels, width, height),
	xSpeed(x),
	ySpeed(y) {
	procSpeed();
}

MotionBlurFilter::MotionBlurFilter(int* pixels, int width, int height,
		MotionBlurFilterOpitons options):
			ImageFilter(pixels, width, height),
			xSpeed(options.xSpeed),
			ySpeed(options.ySpeed) {
	procSpeed();
}

void MotionBlurFilter::procSpeed() {
	if (xSpeed == 0) {
		xSpeed = 1;
	}
	if (ySpeed == 0) {
		ySpeed = 1;
	}
}

int* MotionBlurFilter::procImage() {
	if (xSpeed == 0 && ySpeed == 0) {
		return pixels;
	}
	int absXSpeed = abs(xSpeed);
	int absYSpeed = abs(ySpeed);
	int *originPixels = new int[width * height];
	memcpy(originPixels, pixels, width * height * sizeof(int));

	for (int y = 0; y < height - DELAY; y++) {
		for (int x = 0; x < width - DELAY; x++) {
			for (int t = 0; t < DELAY; t++) {
				Color color(originPixels[(y + t) * width + x + t]);
				float sumR = color.R();
				float sumG = color.G();
				float sumB = color.B();
				for (int xOffset = 1; xOffset <= absXSpeed; xOffset++) {
					for (int yOffset = 1; yOffset <= absYSpeed; yOffset++) {
						int xOff, yOff;
						if (xOffset <= x) {
							xOff = xOffset;
						} else {
							xOff = xOffset + x;
						}
						if (yOffset <= y) {
							yOff = yOffset;
						} else {
							yOff = yOffset + y;
						}
						int finalXCoord = xSpeed > 0 ? x - xOff * DELAY + t : x + xOff * DELAY + t;
						int finalYCoord = ySpeed > 0 ? y - yOff * DELAY + t : y + yOff * DELAY + t;
						finalXCoord = min(width - 1, max(finalXCoord, 0));
						finalYCoord = min(height - 1, max(finalYCoord, 0));
						Color color(originPixels[finalYCoord * width + finalXCoord]);
						sumR += color.R();
						sumG += color.G();
						sumB += color.B();
					}
				}
				sumR /= float(absXSpeed * absYSpeed);
				sumG /= float(absXSpeed * absYSpeed);
				sumB /= float(absXSpeed * absYSpeed);
				sumR = min(255, max(int(sumR), 0));
				sumG = min(255, max(int(sumG), 0));
				sumB = min(255, max(int(sumB), 0));
				pixels[(y + t) * width + x + t] = RGB2Color((int)sumR, (int)sumG, (int)sumB);
			}
		}
	}
	delete [] originPixels;
	return pixels;
}
