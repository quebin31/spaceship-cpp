//
// Created by kevin on 1/06/17.
//

#include "inc/Keyboard.h"

Keyboard::Keyboard() {
	for (KeysID i = UP; i <= ESC; ++i)
		keyStates[i] = false;
}

bool& Keyboard::operator[](KeysID identifier) { return keyStates[identifier]; }

void Keyboard::keyDownEvent(AllegroEvent &event) {
	switch (event.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			keyStates[UP] = true;
			break;
		case ALLEGRO_KEY_DOWN:
			keyStates[DOWN] = true;
			break;
		case ALLEGRO_KEY_LEFT:
			keyStates[LEFT] = true;
			break;
		case ALLEGRO_KEY_RIGHT:
			keyStates[RIGHT] = true;
			break;
		case ALLEGRO_KEY_A:
			keyStates[CHAR_A] = true;
			break;
		default:
			break;
	}
}

void Keyboard::keyUpEvent(AllegroEvent &event) {
	switch (event.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			keyStates[UP] = false;
			break;
		case ALLEGRO_KEY_DOWN:
			keyStates[DOWN] = false;
			break;
		case ALLEGRO_KEY_LEFT:
			keyStates[LEFT] = false;
			break;
		case ALLEGRO_KEY_RIGHT:
			keyStates[RIGHT] = false;
			break;
		case ALLEGRO_KEY_A:
			keyStates[CHAR_A] = false;
			break;
		case ALLEGRO_KEY_ESCAPE:
			keyStates[ESC] = true;
			break;
		default:
			break;
	}
}

void Keyboard::resetKeyboard() {
	for (KeysID i = UP; i <= ESC; ++i)
		keyStates[i] = false;
}

Keyboard *Keyboard::get() {
	if (!instance) instance = new Keyboard;
	return instance;
}

Keyboard *Keyboard::instance = nullptr;
