//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_ASTEROID_H
#define SPACESHIP_ASTEROID_H

#include "SpaceShipIncludes.h"
#include "Bitmap.h"

const int typeOfAsters[] = {0, 45, 90, 135, 180};
const int numOfTypes = { sizeof(typeOfAsters)/sizeof(int) };

class Asteroid : public Bitmap {
private:
		int generateRandomType();
		double generateRandomCoord(const int min, const int max);
		
public:
		Asteroid();
		
		bool checkColisionWith(Bitmap *some) override;
		void drawBitmap(const int flags) override;
		void resetBitmap() override;
};

#endif //SPACESHIP_ASTEROID_H
