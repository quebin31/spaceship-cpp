//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_ASTEROIDFACTORY_H
#define SPACESHIP_ASTEROIDFACTORY_H

#include "SpaceShipIncludes.h"
#include "AsteroidObjectPool.h"

class AsteroidFactory {
private:
		int fpsFrequency;
		
		int generateRandomNumOfAsters();
		int generateRandomFPSCount();
		Asteroid* checkObjectPool(AsteroidObjectPool& asteroidObjectPool);
		
public:
		int getFPSFrequency();
		void generateRowFor(AsteroidObjectPool& asteroidObjectPool);
};

#endif //SPACESHIP_ASTEROIDFACTORY_H
