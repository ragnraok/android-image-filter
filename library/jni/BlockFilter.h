/*
 * BlockFilter.h
 *
 *  Created on: 2014-4-13
 *      Author: ragnarok
 */

#ifndef BLOCKFILTER_H_
#define BLOCKFILTER_H_

#include "Util.h"
#include "ImageFilter.h"

class BlockFilter : public ImageFilter {
public:
	BlockFilter(int* pixels, int width, int height);
	int* procImage();
private:
	int threshold;
};



#endif /* BLOCKFILTER_H_ */
