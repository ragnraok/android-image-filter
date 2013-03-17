/*
 * OldFilter.h
 *
 *  Created on: 2013-2-10
 *      Author: ragnarok
 */

#ifndef OLDFILTER_H_
#define OLDFILTER_H_

#include "Util.h"
#include <stdlib.h>

void oilFilter(int* pixels, int width, int height) {
	int color = 0;
	int model = 10;

	int* tempPixels = new int[width * height];
	memcpy(tempPixels, pixels, sizeof(int) * width * height);


	srand(time(NULL));

	int i = width - model - 1;
	while (i > model) {
		//LOGD("i = %d", i);
		int j = height - model - 1;
		while (j > model) {
			//LOGD("j = %d", j);
			int pos = rand() % model;
			//LOGD("pos = %d", pos);
			int otherPos = (i + pos) * width + j + pos;
			if (otherPos < width * height) {
				unsigned color = tempPixels[otherPos];
				pixels[i * width + j] = color;
			}
			j--;

		}
		i--;
	}

	delete [] tempPixels;
}


#endif /* OLDFILTER_H_ */
