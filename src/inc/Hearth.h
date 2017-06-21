//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_HEARTH_H
#define SPACESHIP_HEARTH_H

#include "SpaceShipIncludes.h"
#include "Bitmap.h"

const int ALIVE_HEARTH = 0;
const int DEAD_HEARTH  = 30;

class Hearth : public Bitmap {
public:
		Hearth();
		
		void lostHeart();
		bool checkColisionWith(Bitmap *some) override;
		void drawBitmap(const int flags) override;
		void resetBitmap() override;
};

#endif //SPACESHIP_HEARTH_H
