//
// Created by kevin on 1/06/17.
//

#include "inc/Proyectile.h"

Proyectile::Proyectile(const ProyectileType& type) : Bitmap(type.resourceName) {
	width = type.width;
	height = type.heigth;
}

void Proyectile::convertTo(const ProyectileType &newType) {
	changeBitmap(newType.resourceName);
	if (width != newType.width) width = newType.width;
	if (height != newType.heigth) height = newType.heigth;
}

bool Proyectile::checkColisionWith(Bitmap *some) {
	if ((positionX + width >= some->positionX) && (positionX <= some->positionX + some->width)) {
		if ((positionY + height >= some->positionY) && (positionY <= some->positionY + some->height)) {
			destroyed = true;
			some->destroyed = true;
			return true;
		}
	}
  return false;
}

void Proyectile::drawBitmap(const int flags)
{ al_draw_bitmap(bitmap, positionX, positionY, flags); }

void Proyectile::resetBitmap() {
	positionX = 0;
	positionY = 0;
	destroyed = false;
}
