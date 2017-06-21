//
// Created by kevin on 1/06/17.
//

#include "inc/Image.h"

Image::Image(const std::string &file) : Bitmap(file) {}

Image::Image(const std::string &file, const int width, const int height) : Bitmap(file), width(width), height(height) {}


bool Image::checkColisionWith(Bitmap *some)
{ return false; }

void Image::drawBitmap(const int flags)
{ al_draw_bitmap(bitmap, positionX, positionY, flags); }

void Image::resetBitmap() {
	if (bitmap) al_destroy_bitmap(bitmap);
	width = 0;
	height = 0;
}
