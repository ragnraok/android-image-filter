/*
 * NeonFilter.h
 *
 *  Created on: 2013-2-9
 *      Author: ragnarok
 */

#ifndef NEONFILTER_H_
#define NEONFILTER_H_

#include "Util.h"
#include "ColorGetter.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>

static inline void neonFilter(int* pixels, int width, int height) {
	int grayValue[256];
	memset(grayValue, 0, 256 * sizeof(int));
	int outlineCase = 1;

	int finalR;
	int finalG;
	int finalB;

	srand(time(NULL));
	int val = rand() % 10 + 1;
	if (val <= 3) {
		finalR = 200;
		finalG = 50;
		finalB = 100;
	}
	else if (val > 3 && val < 7) {
		finalR = 100;
		finalG = 200;
		finalB = 50;
	}
	else {
		finalR = 100;
		finalG = 100;
		finalB = 230;
	}

	int* tempPixel = new int[width * height];
	memcpy(tempPixel, pixels, width * height * sizeof(int));

	int xSobel[] = {1, 2, 1, 0, 0, 0, -1, -2, -1};
	int ySobel[] = {1, 0, -1, 2, 0, -2, 1, 0, -1};

	int index = 0;
	int originGray = 0;
	int afterGray = 0;

	int xVal = 0;
	int yVal = 0;
	float threshold = 110;

	for (int i = 1; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			index = 0;
			afterGray = 0;
			xVal = yVal = 0;
			for (int m = -1; m <= 1; m++) {
				for (int n = -1; n <= 1; n++) {
					Color pixColor = Color(tempPixel[(i + m) * width + j + n]);
					originGray = pixColor.grayScale();

					xVal += originGray * xSobel[index];
					yVal += originGray * ySobel[index];
					index++;
				}
			}
			afterGray = abs(xVal) + abs(yVal);
			afterGray = min(255, max(0, afterGray));
			if (afterGray > threshold) {
				pixels[i * width + j] = RGB2Color(finalR, finalG, finalB);
			}
			else
				pixels[i * width + j] = RGB2Color(1, 1, 1);
		}
	}
	delete [] tempPixel;
}

#endif /* NEONFILTER_H_ */
