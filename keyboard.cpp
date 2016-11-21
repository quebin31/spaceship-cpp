#include "keyboard.h"

/// Constructor
KEYBOARD::KEYBOARD() {
  key[0] = false;
  key[1] = false;
  key[2] = false;
  key[3] = false;
}

/// Devuelve el estado de una key
bool KEYBOARD::get_key_state(const int KEY_ID) { return key[KEY_ID]; }

/// Cambia el estado de una key
void KEYBOARD::change_key_state(const int KEY_ID, bool value) { key[KEY_ID] = value; }

/// Procedimiento cuando llege un evento al presionar una tecla
void KEYBOARD::key_down_event(ALLEGRO_EVENT &ev) {
  switch (ev.keyboard.keycode){
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
  }
}

/// Procedimiento cuando llegue un evento al soltar una tecla
void KEYBOARD::key_up_event(ALLEGRO_EVENT &ev, GAME &main) {
  switch (ev.keyboard.keycode){
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
    case ALLEGRO_KEY_ESCAPE:
      main.game_over = true;
      break;
  }
}
