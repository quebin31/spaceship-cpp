//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_ASTEROIDOBJECTPOOL_H
#define SPACESHIP_ASTEROIDOBJECTPOOL_H

#include "SpaceShipIncludes.h"
#include "Asteroid.h"

class AsteroidFactory;
class AsteroidInterface;

class AsteroidObjectPool {
private:
		std::vector<Asteroid*>  asteroidsOnUse;
		std::vector<Asteroid*>  unusedAsteroids;
		
		friend class AsteroidFactory;
		friend class AsteroidInterface;
public:
		
		class Iterator {
		private:
				AsteroidObjectPool *ap;
				int index;
				
				friend class AsteroidObjectPool;
		
		public:
				Iterator(AsteroidObjectPool& ap);
				Iterator(AsteroidObjectPool* ap);
				Iterator(const Iterator& copy);
				
				Iterator& operator++();
				Iterator  operator++(int);
				Iterator  operator+(const int sum);
				Iterator& operator--();
				Iterator  operator--(int);
				Iterator  operator-(const int dif);
				
				bool operator==(const Iterator& itr);
				bool operator!=(const Iterator& itr);
				
				Asteroid* operator*();
				Iterator  operator=(const Iterator& copy);
				
				int getIndex();
		};
		
		AsteroidObjectPool();
		~AsteroidObjectPool();
		
		Asteroid& at(const int index);
		Asteroid& operator[](const int index);
		
		std::size_t size();
		void erase(Iterator& itr);
		
		Iterator begin();
		Iterator end();
};

#endif //SPACESHIP_ASTEROIDOBJECTPOOL_H
