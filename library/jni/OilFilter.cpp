/*
 * OilFilter.cpp
 *
 *  Created on: 2014-4-11
 *      Author: ragnarok
 */

#include <time.h>
#include <string.h>

#include "OilFilter.h"

OilFilter::OilFilter(int* pixels, int width, int height):
	ImageFilter(pixels, width, height) {
	this->oilRange = 10;
}

OilFilter::OilFilter(int *pixels, int width, int height, OilFilterOptions options):
	ImageFilter(pixels, width, height) {
	this->oilRange = options.oilRange;
}

int* OilFilter::procImage() {
	int *originPixels = new int[width * height];
	memcpy(originPixels, pixels, width * height * sizeof(int));

//	srand(time(NULL));
//
//	int i, j, originI, originJ;
//	i = height - model - 1;
//	j = width - model - 1;
//	originI = i;
//	originJ = j;
//
//	while (i > model) {
//		j = originJ;
//		while (j > model) {
//			int pos = rand() % model;
//			int otherPos = (i + pos) * width + j + pos;
//			if (otherPos < width * height) {
//				unsigned color = originPixels[otherPos];
//				if (i * width + j < width * height)  {
//					pixels[i * width + j] = color;
//				}
//
//			}
//			j--;
//
//		}
//		i--;
//	}

	int rHis[OIL_FILTER_LEVEL], gHis[OIL_FILTER_LEVEL], bHis[OIL_FILTER_LEVEL];
	int rTotal[OIL_FILTER_LEVEL], gTotal[OIL_FILTER_LEVEL], bTotal[OIL_FILTER_LEVEL];

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			memset(rHis, 0, OIL_FILTER_LEVEL * sizeof(int));
			memset(gHis, 0, OIL_FILTER_LEVEL * sizeof(int));
			memset(bHis, 0, OIL_FILTER_LEVEL * sizeof(int));
			memset(rTotal, 0, OIL_FILTER_LEVEL * sizeof(int));
			memset(gTotal, 0, OIL_FILTER_LEVEL * sizeof(int));
			memset(bTotal, 0, OIL_FILTER_LEVEL * sizeof(int));

			int rowOffset, colOffset;
			for (int row = -this->oilRange; row < this->oilRange; row++) {
				rowOffset = y + row;
				if (rowOffset >= 0 && rowOffset < height) {
					for (int col = -this->oilRange; col < this->oilRange; col++) {
						colOffset = x + col;
						if (colOffset >= 0 && colOffset < width) {
							Color color = originPixels[rowOffset * width + colOffset];
							int r = color.R();
							int g = color.G();
							int b = color.B();

							rTotal[r] += r;
							gTotal[g] += g;
							bTotal[b] += b;

							rHis[r]++;
							gHis[g]++;
							bHis[b]++;
						}
					}
				}
			}

			int maxR = 0, maxG = 0, maxB = 0;
			for (int i = 1; i < OIL_FILTER_LEVEL; i++) {
				if (rHis[i] > rHis[maxR]) {
					maxR = i;
				}
				if (gHis[i] > gHis[maxG]) {
					maxG = i;
				}
				if (bHis[i] > bHis[maxB]) {
					maxB = i;
				}
			}
			if (rHis[maxR] != 0 && gHis[maxG] != 0 && bHis[maxB] != 0) {
				int finalR = rTotal[maxR] / rHis[maxR];
				int finalG = gTotal[maxG] / gHis[maxG];
				int finalB = bTotal[maxB] / bHis[maxB];

				finalR = min(255, max(0, finalR));
				finalG = min(255, max(0, finalG));
				finalB = min(255, max(0, finalB));

				pixels[y * width + x] = RGB2Color(finalR, finalG, finalB);
			}
		}
	}

	delete [] originPixels;

	return pixels;
}
