/*
 * HueSaturationFilter.h
 *
 *  Created on: 2014-4-17
 *      Author: ragnarok
 */

#ifndef HUESATURATIONFILTER_H_
#define HUESATURATIONFILTER_H_

class HueSaturationFilter : public ImageFilter {
public:
	HueSaturationFilter(int *pixels, int width, int height);
	int* procImage();
};




#endif /* HUESATURATIONFILTER_H_ */
