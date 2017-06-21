//
// Created by kevin on 1/06/17.
//

#include "inc/Nave.h"

Nave* Nave::instance = nullptr;

Nave::Nave() : Bitmap("nave.png") {
	width = 32;
	height = 32;
	sourceX = NAVE_UP;
}

Nave *Nave::get() {
	if (!instance)
		instance = new Nave;
	return instance;
}

void Nave::del() {
	delete instance;
}

void Nave::shootGun() {
	// To be implemented
}

void Nave::makeInvulnerable(TimerType fpsAtMoment) {
	destroyedAt = fpsAtMoment;
	destroyed = true;
	Score::get()->decScore(50);
}

void Nave::makeVulnerable(TimerType fpsAtMoment) {
	if (fpsAtMoment + 5 >= destroyedAt)
		destroyed = false;
}

bool Nave::checkColisionWith(Bitmap *some)
{	return false; }

void Nave::drawBitmap(const int flags)
{ al_draw_bitmap_region(bitmap, sourceX, sourceY, width, height, positionX, positionY, flags); }

void Nave::resetBitmap() {
	positionX  = 0;
	positionY  = 0;
	sourceX = NAVE_UP;
	sourceY = 0;
	destroyed = false;
}
