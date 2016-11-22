//
// Created by kevin on 21/11/16.
//

#include "game.h"
#include "keyboard.h"
#include "bitmap.h"
#include "nave.h"

using namespace std;

SCREEN* screen = create_screen(640,480,60);

int main(int argc, const char **argv) {
  GAME     SpaceShip(screen);
  KEYBOARD keyboard;
  NAVE     nave("Seker.png");

  nave.setX((coor_t)(screen->width / 2.0 - nave.get_width() / 2.0));
  nave.setY((coor_t)(screen->height / 2.0 - nave.get_height() / 2.0));
  nave.draw_bitmap(0);

  al_flip_display();
  SpaceShip.start_timer();
  int dir=UP;
//  bool active=true;

  cout << nave.get_height() << endl;
  while (!SpaceShip.game_over) {
    ALLEGRO_EVENT ev;
    al_wait_for_event(SpaceShip.get_event_queue(), &ev);

    if (ev.type == ALLEGRO_EVENT_TIMER) {
      if (keyboard.get_key_state(UP) && nave.getY() >= 4.0){
        nave.moveY(-4.0);
        dir=UP;
      }
      else if (keyboard.get_key_state(DOWN) && nave.getX() <= screen->height - nave.get_height() - 4.0){
        nave.moveY(-4.0);
        dir=DOWN;
      }
    }
  }
}
