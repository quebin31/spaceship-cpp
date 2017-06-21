//
// Created by kevin on 1/06/17.
//

#include "inc/Hearth.h"

Hearth::Hearth(): Bitmap("lifes.png") {
	width = 30;
	height = 30;
	sourceX = ALIVE_HEARTH;
	sourceY = 0;
}

void Hearth::lostHeart() {
	sourceX = DEAD_HEARTH;
	destroyed = true;
}

bool Hearth::checkColisionWith(Bitmap *some) { return false; }

void Hearth::drawBitmap(const int flags)
{ al_draw_bitmap_region(bitmap, sourceX, sourceY, width, height, positionX, positionY, flags); }

void Hearth::resetBitmap() {
	sourceX = ALIVE_HEARTH;
	destroyed = false;
}
