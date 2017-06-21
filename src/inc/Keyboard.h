//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_KEYBOARD_H
#define SPACESHIP_KEYBOARD_H

#include "SpaceShipIncludes.h"

enum KeysID {
	UP, DOWN, LEFT, RIGHT, CHAR_A, ESC
};

const int numberOfKeys = 6;

class Keyboard {
private:
		bool keyStates[numberOfKeys];
		static Keyboard *instance;
		
		Keyboard();

public:
		
		bool& operator[](KeysID identifier);
		
		void keyDownEvent(AllegroEvent& event);
		void keyUpEvent(AllegroEvent& event);
		
		void resetKeyboard();
		
		static Keyboard* get();
};



#endif //SPACESHIP_KEYBOARD_H
