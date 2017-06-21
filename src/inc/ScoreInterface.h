//
// Created by kevin on 5/06/17.
//

#ifndef SPACESHIP_SCOREINTERFACE_H
#define SPACESHIP_SCOREINTERFACE_H

#include "SpaceShipIncludes.h"

class Score {
private:
		int score;
	
		static Score *instance;
		Score();
public:
		
		static Score* get();
		static void   del();

		std::string getScore();
		void setScore(int score);

		void incScore(int value);
		void decScore(int value);
};


#endif //SPACESHIP_SCOREINTERFACE_H
