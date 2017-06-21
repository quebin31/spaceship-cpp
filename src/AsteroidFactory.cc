//
// Created by kevin on 1/06/17.
//

#include "inc/AsteroidFactory.h"

int AsteroidFactory::generateRandomNumOfAsters()
{ Random.generateRandomInt(3,7); }

int AsteroidFactory::generateRandomFPSCount()
{ Random.generateRandomInt(90,110); }

Asteroid *AsteroidFactory::checkObjectPool(AsteroidObjectPool &asteroidObjectPool) {
	if (!(asteroidObjectPool.unusedAsteroids.empty())) {
		Asteroid* asteroid = asteroidObjectPool.unusedAsteroids.back();
		asteroidObjectPool.unusedAsteroids.pop_back();
		return asteroid;
	}
	return new Asteroid;
}

int AsteroidFactory::getFPSFrequency()
{ return fpsFrequency; }

void AsteroidFactory::generateRowFor(AsteroidObjectPool &asteroidObjectPool) {
	int numberOfAsteroids = generateRandomNumOfAsters();
	for (int i = 0; i < numberOfAsteroids; ++i) {
		Asteroid* asteroid = checkObjectPool(asteroidObjectPool);
		asteroidObjectPool.asteroidsOnUse.push_back(asteroid);
	}
	fpsFrequency = generateRandomFPSCount();
}

