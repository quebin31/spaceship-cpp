//
// Created by kevin on 5/06/17.
//

#include "inc/PowerUp.h"

double PowerUp::generateRandomCoord(const int min, const int max) {
	return Random.generateRandomInt(min, max);
}

PowerUp::PowerUp(const PowerUpType &type) : Bitmap(type.resourceName){
	width = type.width;
	height = type.height;
}

void PowerUp::convertTo(const PowerUpType &newType) {
	changeBitmap(newType.resourceName);
	if (width != newType.width) width = newType.width;
	if (height != newType.height) height = newType.height;
}

bool PowerUp::checkColisionWith(Bitmap *some) {
	if ((positionX + width >= some->positionX) && (positionX <= some->positionX + some->width)) {
		if ((positionY + height >= some->positionY) && (positionY <= some->positionY + some->height)) {
			destroyed = true;
			return true;
		}
	}
	return false;
}

void PowerUp::drawBitmap(const int flags)
{ if (!destroyed) al_draw_bitmap(bitmap, positionX, positionY, flags); }

void PowerUp::resetBitmap() {
	positionX = generateRandomCoord(70, 410);
	positionY = generateRandomCoord(0, 100);
	destroyed = true;
}
