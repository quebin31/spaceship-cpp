//
// Created by kevin on 6/06/17.
//

#include "inc/ProyectileObjectPool.h"

ProyectileObjectPool::Iterator::Iterator(ProyectileObjectPool &pp): pp(&pp), index(0) {}
ProyectileObjectPool::Iterator::Iterator(ProyectileObjectPool *pp): pp(pp), index(0) {}
ProyectileObjectPool::Iterator::Iterator(const ProyectileObjectPool::Iterator &copy): pp(copy.pp), index(copy.index) {}

ProyectileObjectPool::Iterator &ProyectileObjectPool::Iterator::operator++() {
	++index;
	return (*this);
}

ProyectileObjectPool::Iterator ProyectileObjectPool::Iterator::operator++(int) {
	Iterator tempIterator = *this;
	++(*this);
	return tempIterator;
}

ProyectileObjectPool::Iterator ProyectileObjectPool::Iterator::operator+(const int sum) {
	Iterator tempIterator = *this;
	tempIterator.index += sum;
	return tempIterator;
}

ProyectileObjectPool::Iterator &ProyectileObjectPool::Iterator::operator--() {
	--index;
	return (*this);
}

ProyectileObjectPool::Iterator ProyectileObjectPool::Iterator::operator--(int) {
	Iterator tempIterator = *this;
	--(*this);
	return tempIterator;
}

ProyectileObjectPool::Iterator ProyectileObjectPool::Iterator::operator-(const int dif) {
	Iterator tempIterator = *this;
	tempIterator.index -= dif;
	return tempIterator;
}

bool ProyectileObjectPool::Iterator::operator==(const ProyectileObjectPool::Iterator &itr)
{ return (index == itr.index); }

bool ProyectileObjectPool::Iterator::operator!=(const ProyectileObjectPool::Iterator &itr)
{ return (index != itr.index); }

Proyectile *ProyectileObjectPool::Iterator::operator*()
{ return (pp->proyectilesOnUse[index]); }

ProyectileObjectPool::Iterator ProyectileObjectPool::Iterator::operator=(const ProyectileObjectPool::Iterator &copy) {
	pp = copy.pp;
	index = copy.index;
	return (*this);
}

int ProyectileObjectPool::Iterator::getIndex()
{ return index; }

ProyectileObjectPool::ProyectileObjectPool() {}

ProyectileObjectPool::~ProyectileObjectPool() {
	for (unsigned long i = 0; i < proyectilesOnUse.size(); ++i)
		delete proyectilesOnUse[i];
	for (unsigned long i = 0; i < unusedProyectiles.size(); ++i)
		delete unusedProyectiles[i];
}

Proyectile &ProyectileObjectPool::at(const int index)
{ return *(proyectilesOnUse.at(index)); }

Proyectile &ProyectileObjectPool::operator[](const int index)
{ return *(proyectilesOnUse[index]); }

std::size_t ProyectileObjectPool::size()
{ return proyectilesOnUse.size(); }

void ProyectileObjectPool::erase(ProyectileObjectPool::Iterator &itr) {
	Proyectile* proyectile = (*itr);
	proyectile->resetBitmap();
	unusedProyectiles.push_back(proyectile);
	proyectilesOnUse.erase(proyectilesOnUse.begin() + itr.index);
}

ProyectileObjectPool::Iterator ProyectileObjectPool::begin() {
	Iterator temp(this);
	temp.index = 0;
	return temp;
}

ProyectileObjectPool::Iterator ProyectileObjectPool::end() {
	Iterator temp(this);
	temp.index = static_cast<int>(proyectilesOnUse.size());
	return temp;
}
