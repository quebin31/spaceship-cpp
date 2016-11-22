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
  BITMAP   bouncer(32);

  nave.setX((coor_t)(screen->width / 2.0 - nave.get_width() / 2.0));
  nave.setY((coor_t)(screen->height / 2.0 - nave.get_height() / 2.0));

  bouncer.setX((coor_t)(screen->width / 2.0 - nave.get_width() / 2.0));
  bouncer.setY((coor_t)(screen->height / 2.0 - nave.get_height() / 2.0 - 100));

  bouncer.set_bitmap_color(255,0,255,SpaceShip);
  bouncer.draw_bitmap(0);
  nave.draw_bitmap(0);


}
