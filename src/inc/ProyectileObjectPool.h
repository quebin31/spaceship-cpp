//
// Created by kevin on 6/06/17.
//

#ifndef SPACESHIP_PROYECTILEOBJECTPOOL_H
#define SPACESHIP_PROYECTILEOBJECTPOOL_H

#include "SpaceShipIncludes.h"
#include "Proyectile.h"

class ProyectileFactory;
class ProyectileInterface;


class ProyectileObjectPool {
private:
		std::vector<Proyectile*> proyectilesOnUse;
		std::vector<Proyectile*> unusedProyectiles;
		
		friend class ProyectileFactory;
		friend class ProyectileInterface;

public:
		
		class Iterator {
		private:
				ProyectileObjectPool *pp;
				int index;
				
				friend class ProyectileObjectPool;
		
		public:
				Iterator(ProyectileObjectPool& pp);
				Iterator(ProyectileObjectPool* pp);
				Iterator(const Iterator& copy);
				
				Iterator& operator++();
				Iterator  operator++(int);
				Iterator  operator+(const int sum);
				Iterator& operator--();
				Iterator  operator--(int);
				Iterator  operator-(const int dif);
				
				bool operator==(const Iterator& itr);
				bool operator!=(const Iterator& itr);
			
				Proyectile* operator*();
				Iterator    operator=(const Iterator& copy);
				
				int getIndex();
		};
		
		ProyectileObjectPool();
		~ProyectileObjectPool();
		
		Proyectile& at(const int index);
		Proyectile& operator[](const int index);
		
		std::size_t size();
		void erase(Iterator& itr);
		
		Iterator begin();
		Iterator end();
};


#endif //SPACESHIP_PROYECTILEOBJECTPOOL_H
