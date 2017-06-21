//
// Created by kevin on 1/06/17.
//

#include "inc/AsteroidInterface.h"

AsteroidInterface::AsteroidInterface(): asteroidFactory(), asteroidObjectPool() {
	asteroidFactory.generateRowFor(asteroidObjectPool);
}

void AsteroidInterface::updateAsteroids(TimerType actualFrameCount) {
	if (!((actualFrameCount % asteroidFactory.getFPSFrequency()) & 1))
		asteroidFactory.generateRowFor(asteroidObjectPool);
	
	for (AsteroidObjectPool::Iterator it = asteroidObjectPool.begin(); it != asteroidObjectPool.end(); ++it) {
		if (!(*it)->isDestroyed()) {
			(*it)->moveY(2.5);
			(*it)->drawBitmap(0);
		}
	}
}

void AsteroidInterface::eraseAsteroid(AsteroidObjectPool::Iterator &itr)
{	asteroidObjectPool.erase(itr); }

AsteroidObjectPool::Iterator AsteroidInterface::begin()
{ return asteroidObjectPool.begin(); }

AsteroidObjectPool::Iterator AsteroidInterface::end()
{ return asteroidObjectPool.end(); }

AsteroidObjectPool *AsteroidInterface::getObjectPool()
{ return &asteroidObjectPool; }

void AsteroidInterface::resetAsteroids() {
	for (AsteroidObjectPool::Iterator it = begin(), end = end(); it != end; ++it) {
		asteroidObjectPool.erase(it);
		end = end();
	}
}
