#include "inc/Asteroid.h"

Asteroid::Asteroid() : Bitmap("asteroides.png") {
	positionX = generateRandomCoord(30,490);
	positionY = generateRandomCoord(0,30);
	sourceX = typeOfAsters[generateRandomType()];
	destroyed = false;
}

int Asteroid::generateRandomType()
{ return Random::generateRandomInt(0, numOfTypes); }

double Asteroid::generateRandomCoord(const int min, const int max)
{ return Random::generateRandomInt(min, max); }

bool Asteroid::checkColisionWith(Bitmap *some) {
	if ((positionX + width >= some->positionX) && (positionX <= some->positionX + some->width)) {
		if ((positionY + height >= some->positionY) && (positionY <= some->positionY + some->height)) {
			destroyed = true;
			some->destroyed = true;
			return true;
		}
	}
	return false;
}

void Asteroid::drawBitmap(const int flags)
{ al_draw_bitmap_region(bitmap, sourceX, sourceY, width, height, positionX, positionY, flags); }

void Asteroid::resetBitmap() {
	positionX = generateRandomCoord(30, 490);
	positionY = generateRandomCoord(0,30);
	sourceX   = typeOfAsters[generateRandomType()];
	destroyed = false;
}
