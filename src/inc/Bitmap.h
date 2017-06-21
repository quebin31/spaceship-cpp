//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_BITMAP_H
#define SPACESHIP_BITMAP_H

#include "SpaceShipIncludes.h"

class Bitmap {
protected:
		AllegroBitmap  *bitmap;
		std::string     resourceName;
		int             width;
		int             height;
		double          positionX;
		double          positionY;
		int             sourceX;
		int             sourceY;
		bool            destroyed;

		friend class Asteroid;
		friend class Hearth;
		friend class Nave;
		friend class PowerUp;
		friend class Image;
		friend class Proyectile;
		
public:
		Bitmap(const std::string& file);
		virtual ~Bitmap();
		
		double getX() const;
		double getY() const;
		void setX(const double x);
		void setY(const double y);
		
		void moveX(const double shift);
		void moveY(const double shift);
		
		int getWidth() const;
		int getHeight() const;
		
		void setSourceX(const int x);
		void setSourceY(const int y);
		
		void destroyIt(const bool newState);
		bool isDestroyed() const;
		
		void changeBitmap(const std::string& newFile);
		
		virtual bool checkColisionWith(Bitmap* some) = 0;
		virtual void drawBitmap(const int flags) = 0;
		virtual void resetBitmap() = 0;
};

#endif //SPACESHIP_BITMAP_H
