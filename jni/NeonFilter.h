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

int truncate(int a) {
	if (a < 0)
		return 0;
	else if (a > 255)
		return 255;
	else
		return a;
}

void neonFilter(int* pixels, int width, int height) {
	int grayValue[256];
	memset(grayValue, 0, 256 * sizeof(int));
	int outlineCase = 1;

	srand(time(NULL));
	//float val = rand() % 10 + 1;
	/*
	if (val > 0.3 && val < 0.7) {
		outlineCase = 2;
	}
	else if (val > 0.7) {
		outlineCase = 3;
	}
	for (int i = 255; i >= 0; i--) {
		int red = i, green = i, blue = i;
		if (i > 127) {
			switch (outlineCase) {
			case 1:
				red = 255 - i;
				break;
			case 2:
				green = 255 - i;
				break;
			case 3:
				blue = 255 - i;
				break;
			}
		}
		grayValue[255 - i] = RGB2Color(red, green, blue);
	}*/

	// change to gray scale image
	for (int i = 0; i < width * height; i++) {
		Color color(pixels[i]);
		int grayScale = color.grayScale();
		pixels[i] = RGB2Color(grayScale, grayScale, grayScale);
		//LOGD("pixels[i] = %u", pixels[i]);

	}

	int* tempPixel = new int[width * height];
	memcpy(tempPixel, pixels, width * height * sizeof(int));

	int laplacian[] = {  -1, -1, -1, -1, 8, -1, -1, -1, -1 };
	// use laplacian to extract the edges
	int index = 0;
	int originGray = 0;
	int afterGray = 0;
	LOGD("width = %d", width);

	for (int i = 1; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			index = 0;
			afterGray = 0;
			for (int m = -1; m <= 1; m++) {
				for (int n = -1; n <= 1; n++) {
					Color pixColor = Color(tempPixel[(i + m) * width + j + n]);
					originGray = pixColor.R();
					afterGray += originGray * laplacian[index];
					index++;
				}
			}
			truncate(afterGray);
			if (afterGray > 30) {
				pixels[i * width + j] = RGB2Color(200, 50, 50);
			}
			else
				pixels[i * width + j] = RGB2Color(1, 1, 1);
		}
	}
	delete [] tempPixel;
	LOGD("after processing, pixels[1] = %u", pixels[1]);
}

#endif /* NEONFILTER_H_ */
