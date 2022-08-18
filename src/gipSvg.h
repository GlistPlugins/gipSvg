/*
 * gipSvg.h
 *
 *  Created on: 2 Aug 2022
 *      Author: Mahmud Talha Unlu
 */

#ifndef SRC_GIPSVG_H_
#define SRC_GIPSVG_H_

#include "gBasePlugin.h"
#include "gImage.h"


class gipSvg : public gBasePlugin{
public:
	gipSvg();
	virtual ~gipSvg();

	void loadImage(std::string imageName, int width, int height);
	void draw(int x, int y);

	int getWidth();
	int getHeight();

private:
	std::string fullpath;
	unsigned char* data;
	int w, h;
	gImage img;
};

#endif /* SRC_GIPSVG_H_ */
