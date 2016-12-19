//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_KEYBOARD_H
#define SPACESHIP2_KEYBOARD_H

#include "../tools_and_headers/spaceship_includes.h"

enum keys{
  UP, DOWN, LEFT, RIGHT, CHAR_A, ESC
};

class KEYBOARD
{
  private:
    bool key[6];
    static KEYBOARD* keyboard_instance;

    KEYBOARD();

  public:

    bool operator[](keys index);
    void set_state_to(keys index, bool state);

    void key_dw_event(ALLEGRO_EVENT&);
    void key_up_event(ALLEGRO_EVENT&);

    void reset_keyboard();

    static KEYBOARD* get();

};


#endif //SPACESHIP2_KEYBOARD_H
