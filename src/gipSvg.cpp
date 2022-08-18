/*
 * gipSvg.cpp
 *
 *  Created on: 2 Aug 2022
 *      Author: Mahmud Talha Unlu
 */

#include "gipSvg.h"
#define NANOSVG_ALL_COLOR_KEYWORDS	// Include full list of color keywords.
#define NANOSVG_IMPLEMENTATION
#define NANOSVGRAST_IMPLEMENTATION
#include "nanosvg.h"
#include "nanosvgrast.h"


gipSvg::gipSvg() {
	fullpath = "";
	data = nullptr;
	w = 0;
	h = 0;
}

gipSvg::~gipSvg() {

}

void gipSvg::loadImage(std::string imageName, int width, int height) {
	fullpath = gGetImagesDir() + imageName;
	int W = width;
	int H = height;
	data = new unsigned char[W * H * 4];
	NSVGimage* image = nsvgParseFromFile(fullpath.c_str(), "px", 96);
	w = static_cast<int>(image->width);
	h = static_cast<int>(image->height);
	NSVGrasterizer* rast = nsvgCreateRasterizer();
	float scale = float(W)/w;
	float tx = 0.0f;
	float ty = 0.0f;
	nsvgRasterize(rast, image, tx, ty, scale, data, W, H, W*4);
	img.setImageData(data, width, height, 4);
	nsvgDeleteRasterizer(rast);
	nsvgDelete(image);
}

void gipSvg::draw(int x, int y) {
	img.draw(x, y);
}

int gipSvg::getWidth() {
	return img.getWidth();
}

int gipSvg::getHeight() {
	return img.getHeight();
}




