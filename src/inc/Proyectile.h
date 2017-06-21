//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_PROYECTILE_H
#define SPACESHIP_PROYECTILE_H

#include "SpaceShipIncludes.h"
#include "Bitmap.h"


/**
 * Basic type to be used as template for building or modifying Proyectile type.
 * @implements width and height of the actual type.
 * @implements resourceName that is the image name used to represent Proyectile.
 */
typedef struct ProyectileDataType {
	int width, heigth;
	std::string resourceName;
} ProyectileType;

/**
 * Declare some constant ProyectileType templates to be used when constructing
 * or modifying an existant Proyectile.
 */
const ProyectileType BulletType = {10, 10, "bullet.png"};
const ProyectileType LaserType = {10, 40, "laser.png"};

/**
 * @class Proyectile
 * Unique type to be used for proyectiles, it has only one constructor and it
 * only accepts ProyectileType (template for building), it also has a convertTo
 * method, basically it receives an ProyectileType for converting the actual
 * object using templates above.
 */
class Proyectile : public Bitmap {
public:
		Proyectile(const ProyectileType& type);
		
		void convertTo(const ProyectileType& newType);
		
		bool checkColisionWith(Bitmap *some) override;
		void drawBitmap(const int flags) override;
		void resetBitmap() override;
	
};

#endif //SPACESHIP_PROYECTILE_H
