//
// Created by kevin on 1/06/17.
//

#include "inc/AsteroidObjectPool.h"

AsteroidObjectPool::Iterator::Iterator(AsteroidObjectPool &ap): ap(&ap), index(0) {}
AsteroidObjectPool::Iterator::Iterator(AsteroidObjectPool *ap): ap(ap), index(0) {}
AsteroidObjectPool::Iterator::Iterator(const AsteroidObjectPool::Iterator &copy): ap(copy.ap), index(copy.index) {}

AsteroidObjectPool::Iterator &AsteroidObjectPool::Iterator::operator++() {
	++index;
	return (*this);
}

AsteroidObjectPool::Iterator AsteroidObjectPool::Iterator::operator++(int) {
	Iterator tempIterator = *this;
	++(*this);
	return tempIterator;
}

AsteroidObjectPool::Iterator AsteroidObjectPool::Iterator::operator+(const int sum) {
	Iterator tempIterator = *this;
	tempIterator.index += sum;
	return tempIterator;
}

AsteroidObjectPool::Iterator &AsteroidObjectPool::Iterator::operator--() {
	--index;
	return (*this);
}

AsteroidObjectPool::Iterator AsteroidObjectPool::Iterator::operator--(int) {
	Iterator tempIterator = *this;
	--(*this);
	return tempIterator;
}

AsteroidObjectPool::Iterator AsteroidObjectPool::Iterator::operator-(const int dif) {
	Iterator tempIterator = *this;
	tempIterator.index -= dif;
	return tempIterator;
}

bool AsteroidObjectPool::Iterator::operator==(const AsteroidObjectPool::Iterator &itr)
{ return (index == itr.index); }

bool AsteroidObjectPool::Iterator::operator!=(const AsteroidObjectPool::Iterator &itr)
{ return (index != itr.index); }

Asteroid *AsteroidObjectPool::Iterator::operator*()
{ return (ap->asteroidsOnUse[index]); }

AsteroidObjectPool::Iterator AsteroidObjectPool::Iterator::operator=(const AsteroidObjectPool::Iterator &copy) {
	ap = copy.ap;
	index = copy.index;
	return (*this);
}

int AsteroidObjectPool::Iterator::getIndex()
{ return index; }

AsteroidObjectPool::AsteroidObjectPool() {}

AsteroidObjectPool::~AsteroidObjectPool() {
	for (unsigned long i = 0; i < asteroidsOnUse.size(); ++i)
		delete asteroidsOnUse[i];
	for (unsigned long i = 0; i < unusedAsteroids.size(); ++i)
		delete unusedAsteroids[i];
}

Asteroid &AsteroidObjectPool::at(const int index)
{ return *(asteroidsOnUse.at(index)); }

Asteroid &AsteroidObjectPool::operator[](const int index)
{ return *(asteroidsOnUse[index]);}

std::size_t AsteroidObjectPool::size()
{ return asteroidsOnUse.size(); }

void AsteroidObjectPool::erase(AsteroidObjectPool::Iterator &itr) {
	Asteroid* asteroid = (*itr);
	asteroid->resetBitmap();
	unusedAsteroids.push_back(asteroid);
	asteroidsOnUse.erase(asteroidsOnUse.begin() + itr.index);
	--itr;
}

AsteroidObjectPool::Iterator AsteroidObjectPool::begin() {
	Iterator temp(this);
	temp.index = 0;
	return temp;
}

AsteroidObjectPool::Iterator AsteroidObjectPool::end() {
	Iterator temp(this);
	temp.index = static_cast<int>(asteroidsOnUse.size());
	return temp;
}


