//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_ASTEROIDINTERFACE_H
#define SPACESHIP_ASTEROIDINTERFACE_H

#include "SpaceShipIncludes.h"
#include "AsteroidFactory.h"

class AsteroidInterface {
private:
		AsteroidFactory    asteroidFactory;
		AsteroidObjectPool asteroidObjectPool;
		
public:
		AsteroidInterface();
		
		void updateAsteroids(TimerType actualFrameCount);
		void eraseAsteroid(AsteroidObjectPool::Iterator& itr);
		
		AsteroidObjectPool::Iterator begin();
		AsteroidObjectPool::Iterator end();
		AsteroidObjectPool*          getObjectPool();
		
		void resetAsteroids();
};

#endif //SPACESHIP_ASTEROIDINTERFACE_H
