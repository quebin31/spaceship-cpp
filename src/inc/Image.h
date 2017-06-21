//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_IMAGE_H
#define SPACESHIP_IMAGE_H

#include "SpaceShipIncludes.h"
#include "Bitmap.h"

class Image : public Bitmap {
public:
		Image(const std::string &file);
		Image(const std::string &file, const int width, const int height);
		
		bool checkColisionWith(Bitmap *some) override;
		void drawBitmap(const int flags) override;
		void resetBitmap() override;
	
};

#endif //SPACESHIP_IMAGE_H
