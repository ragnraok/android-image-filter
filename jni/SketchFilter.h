/*
 * SketchFilter.h
 *
 *  Created on: 2013-3-18
 *      Author: ragnarok
 */

#ifndef SKETCHFILTER_H_
#define SKETCHFILTER_H_

#include "ColorGetter.h"
#include "Util.h"

void sketchFilter(int *pixels, int width, int height) {
	changeImageToGray(pixels, width, height);

	int *tempPixels = new int[width * height];
	memcpy(tempPixels, pixels, width * height * sizeof(int));

	int threshold = 7;
	float num = 8;
	for (int i = 1; i < height - 1; i++) {
		for (int j = 1; j < width - 1; j++) {
			Color centerColor(tempPixels[i * width + j]);
			int centerGray = centerColor.R();

			Color rightBottomColor(tempPixels[(i + 1) * width + j + 1]);
			int rightBottomGray = rightBottomColor.R();
			if (abs(centerGray - rightBottomGray) >= threshold) {
				pixels[i * width + j] = RGB2Color(0, 0, 0); // black
			}
			else {
				pixels[i * width + j] = RGB2Color(255, 255, 255); // white
			}
		}
	}

	delete [] tempPixels;
}


#endif /* SKETCHFILTER_H_ */
