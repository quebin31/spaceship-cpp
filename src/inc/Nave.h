//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_NAVE_H
#define SPACESHIP_NAVE_H

#include "SpaceShipIncludes.h"
#include "Bitmap.h"

const int NAVE_UP = 0;
const int NAVE_RIGHT = 32;
const int NAVE_LEFT = 64;

class Nave : public Bitmap {
private:
		TimerType destroyedAt;
		
		static Nave *instance;
		Nave();
		
public:
		static Nave* get();
		static void  del();
		
		void shootGun();
		
		void makeInvulnerable(TimerType fpsAtMoment);
		void makeVulnerable(TimerType fpsAtMoment);
		
		bool checkColisionWith(Bitmap *some) override;
		void drawBitmap(const int flags) override;
		void resetBitmap() override;
};

#endif //SPACESHIP_NAVE_H
