//
// Created by kevin on 1/06/17.
//

#include "inc/Bitmap.h"

Bitmap::Bitmap(const std::string &file) {
	bitmap = al_load_bitmap((Tool.getResourcesDirectory() + file).c_str());
	resourceName = file;
	positionX = 0;
	positionY = 0;
	sourceX = 0;
	sourceY = 0;
	destroyed = false;
}

Bitmap::~Bitmap() {
	if (bitmap) al_destroy_bitmap(bitmap);
}

double Bitmap::getX() const { return positionX; }
double Bitmap::getY() const { return positionY; }

void Bitmap::setX(const double x) { positionX = x; }
void Bitmap::setY(const double y) { positionY = y; }

void Bitmap::moveX(const double shift) { positionX += shift; }
void Bitmap::moveY(const double shift) { positionY += shift; }

int Bitmap::getWidth() const { return width; }
int Bitmap::getHeight() const { return height; }

void Bitmap::setSourceX(const int x) { sourceX = x; }
void Bitmap::setSourceY(const int y) { sourceY = y; }

void Bitmap::destroyIt(const bool newState) { destroyed = newState; }
bool Bitmap::isDestroyed() const { return destroyed; }

void Bitmap::changeBitmap(const std::string& newFile) {
	if (resourceName == newFile) return;
	if (bitmap) al_destroy_bitmap(bitmap);
	bitmap = al_load_bitmap((Tool.getResourcesDirectory() + newFile).c_str());
}

