#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "game.h"

enum KEYS{
  UP, RIGHT, LEFT, DOWN
};

class KEYBOARD {
  private:
    bool key[4];
  public:
    KEYBOARD();

    bool get_key_state(const int KEY_ID);                   /// Obtiene el estado de la teclado del indice especificado
    void change_key_state(const int KEY_ID, bool value);    /// Cambia el estado de la tecla del indice especificado

    void key_down_event(ALLEGRO_EVENT& ev);                 /// Secuencia de instrucciones a realizar si se detecta una tecla presionada
    void key_up_event(ALLEGRO_EVENT& ev, GAME& main);       /// Secuencia de instrucciones a realizar cuando se deja de presionar una tecla
};

#endif // KEYBOARD_H
