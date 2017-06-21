//
// Created by kevin on 5/06/17.
//

#ifndef SPACESHIP_POWERUP_H
#define SPACESHIP_POWERUP_H

#include "SpaceShipIncludes.h"
#include "Bitmap.h"

typedef struct PowerUpDataType {
	int width, height;
	std::string resourceName;
} PowerUpType;

class PowerUp : public Bitmap {
private:
		double generateRandomCoord(const int min, const int max);
		
public:
		PowerUp(const PowerUpType& type);
		
		void convertTo(const PowerUpType& newType);
		
		bool checkColisionWith(Bitmap *some) override;
		void drawBitmap(const int flags) override;
		void resetBitmap() override;
};


#endif //SPACESHIP_POWERUP_H
