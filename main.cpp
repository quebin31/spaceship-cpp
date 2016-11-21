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

  al_flip_display();
  SpaceShip.start_timer();
  int dir=DOWN; //DIRECCION
  bool active=true;
  while (!SpaceShip.game_over)
  {
    ALLEGRO_EVENT ev;
    al_wait_for_event(SpaceShip.get_event_queue(), &ev);

    if (ev.type == ALLEGRO_EVENT_TIMER)
    {
      if (keyboard.get_key_state(UP) && nave.getY() >= 4.0){
        nave.moveY(-4.0);
        dir=UP;
      }
      else if (keyboard.get_key_state(DOWN) && nave.getY() <= screen->height - nave.get_height() - 4.0){
        nave.moveY(4.0);
        dir=DOWN;
      }
      else if (keyboard.get_key_state(LEFT) && nave.getX() >= 4.0){
        nave.moveX(-4.0);
        dir=LEFT;
      }
      else if (keyboard.get_key_state(RIGHT) && nave.getX() <= screen->width - nave.get_width() - 4.0){
        nave.moveX(4.0);
        dir=RIGHT;
      }
      else
        active=false;
      if (active){
        nave.refresh_sourceX();
      }
      else
        nave.change_sourceX(96);
      if (nave.get_sourceX() >= al_get_bitmap_width(nave.get_bitmap()));
        nave.change_sourceX(0);
      nave.change_sourceY(dir);
      SpaceShip.redraw = true;
    }
    else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
      break;
    else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
      keyboard.key_down_event(ev);
    else if (ev.type == ALLEGRO_EVENT_KEY_UP)
      keyboard.key_up_event(ev, SpaceShip);

    if (SpaceShip.redraw && SpaceShip.is_event_queue_empty())
    {
      SpaceShip.redraw = false;

      SpaceShip.set_display_color(0,0,0);
      nave.draw_nave();
      bouncer.draw_bitmap(0);
      al_flip_display();
    }
  }

  return 0;
}
