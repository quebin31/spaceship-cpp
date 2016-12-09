//
// Created by kevin on 7/12/16.
//

#include "keyboard.h"

KEYBOARD::KEYBOARD()
{
  key[UP]     = false;
  key[DOWN]   = false;
  key[LEFT]   = false;
  key[RIGHT]  = false;
  key[CHAR_A] = false;
  key[ESC]    = false;
}

bool KEYBOARD::operator[](keys index) { return key[index]; }

void KEYBOARD::set_state_to(keys index, bool status) { key[index] = status; }

void KEYBOARD::key_dw_event(ALLEGRO_EVENT& ev)
{
  switch (ev.keyboard.keycode)
  {
    case ALLEGRO_KEY_UP:
      key[UP] = true;
      break;
    case ALLEGRO_KEY_DOWN:
      key[DOWN] = true;
      break;
    case ALLEGRO_KEY_LEFT:
      key[LEFT] = true;
      break;
    case ALLEGRO_KEY_RIGHT:
      key[RIGHT] = true;
      break;
    case ALLEGRO_KEY_A:
      key[CHAR_A] = true;
      break;
    default:
      break;
  }
}

void KEYBOARD::key_up_event(ALLEGRO_EVENT& ev)
{
  switch (ev.keyboard.keycode)
  {
    case ALLEGRO_KEY_UP:
      key[UP] = false;
      break;
    case ALLEGRO_KEY_DOWN:
      key[DOWN] = false;
      break;
    case ALLEGRO_KEY_LEFT:
      key[LEFT] = false;
      break;
    case ALLEGRO_KEY_RIGHT:
      key[RIGHT] = false;
      break;
    case ALLEGRO_KEY_A:
      key[CHAR_A] = false;
      break;
    case ALLEGRO_KEY_ESCAPE:
      key[ESC] = true;
      break;
    default:
      break;
  }
}

KEYBOARD *KEYBOARD::get()
{
  if (!keyboard_instance)
    keyboard_instance = new KEYBOARD;
  return keyboard_instance;
}

KEYBOARD *KEYBOARD::keyboard_instance = 0;