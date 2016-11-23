//
// Created by kevin on 21/11/16.
//

#include "game.h"
#include "keyboard.h"
#include "bitmap.h"
#include "nave.h"
#include "set_of_asteroids.h"

using namespace std;

SCREEN* screen = create_screen(640,480,60);
int direction  = NAVE_UP;

int main(int argc, const char **argv) {
  GAME           SpaceShip(screen);
  KEYBOARD       keyboard;
  NAVE           nave("nave1.png");
  SetOfAsteroids myAsters("asteroides.png");

  nave.setX((coor_t)(screen->width  / 2.0 - nave.getW()  / 2.0));
  nave.setY((coor_t)(screen->height / 2.0 - nave.getH()  / 2.0));

  bool done=false;
  while (!done){
    SpaceShip.set_display_color(0,0,0);
    al_draw_text(SpaceShip.font1, al_map_rgb(200,10,50), screen->width/2, screen->height/2, ALLEGRO_ALIGN_CENTRE,"ASTEROID GAME");
    al_draw_text(SpaceShip.font2, al_map_rgb(20,30,60), screen->width/2, screen->height/2+60, ALLEGRO_ALIGN_CENTRE,"START (PRESS ENTER)");
    al_draw_text(SpaceShip.font2, al_map_rgb(20,30,60), screen->width/2, screen->height/2+120, ALLEGRO_ALIGN_CENTRE,"EXIT (PRESS ESCAPE)");
    al_flip_display();
    SpaceShip.game_over=false;
    ALLEGRO_EVENT eve;
    al_wait_for_event(SpaceShip.get_event_queue() ,&eve);

    if (eve.type == ALLEGRO_EVENT_KEY_UP){
      if(eve.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
        done=true;
      }
    }
    else if(eve.type == ALLEGRO_EVENT_KEY_DOWN){
      if(eve.keyboard.keycode == ALLEGRO_KEY_ENTER){

        SpaceShip.set_display_color(0,0,0);
        nave.draw_nave(NAVE_UP);
        myAsters.draw_asteroids();
        al_flip_display();
        SpaceShip.start_timer();

        while (!SpaceShip.game_over) {
          ALLEGRO_EVENT ev;
          al_wait_for_event(SpaceShip.get_event_queue(), &ev);


          if (ev.type == ALLEGRO_EVENT_TIMER) {
            if (keyboard.get_key_state(UP) && nave.getY() >= 4.0){
              nave.moveY(-4.0);
              direction=NAVE_UP;
              SpaceShip.redraw = true;
            }
            else if (keyboard.get_key_state(DOWN) && nave.getY() <= screen->height - nave.getH() - 4.0){
              nave.moveY(4.0);
              direction=NAVE_UP;
              SpaceShip.redraw = true;
            }
            else if (keyboard.get_key_state(LEFT) && nave.getX() >= 4.0){
              nave.moveX(-4.0);
              direction=NAVE_LEFT;
              SpaceShip.redraw = true;
            }
            else if (keyboard.get_key_state(RIGHT) && nave.getX() <= screen->width - nave.getW() - 4.0) {
              nave.moveX(4.0);
              direction = NAVE_RIGHT;
              SpaceShip.redraw = true;
            }

            if (keyboard.get_key_state(CHAR_A)){
              nave.shoot();
              keyboard.change_key_state(CHAR_A, false);
            }

            SpaceShip.set_display_color(0,0,0);
            myAsters.move_asteroids();
            myAsters.draw_asteroids();
            nave.draw_nave(direction);
            al_flip_display();
            cout << SpaceShip.get_timer_count() << endl;

          }
          else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
          else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
            keyboard.key_down_event(ev);
          else if (ev.type == ALLEGRO_EVENT_KEY_UP)
            keyboard.key_up_event(ev, SpaceShip);
<<<<<<< HEAD
          if (SpaceShip.redraw && SpaceShip.event_queue_is_empty()){
=======

          // fixme: ¿Es necesaria esta parte?
          /*if (SpaceShip.redraw && SpaceShip.event_queue_is_empty()){
>>>>>>> 7b8fe6f5a7ebe56c105a7de2d6aa958800b5d20e
            SpaceShip.redraw = false;
            SpaceShip.set_display_color(0,0,0);
            nave.draw_nave(direction);
            al_flip_display();
          }*/
        }
      }
    }
    else if (eve.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
      done=true;
<<<<<<< HEAD
    // fixme: Realmente es necesario, mas arriba se dibuja la nave y los asteroides.
//    if (SpaceShip.redraw && SpaceShip.event_queue_is_empty()){
//      SpaceShip.redraw = false;
//      SpaceShip.set_display_color(0,0,0);
//      nave.draw_nave(direction);
//      al_flip_display();
//    }
=======
>>>>>>> 7b8fe6f5a7ebe56c105a7de2d6aa958800b5d20e
  }

  cout << al_get_time() << endl;
  return 0;
}
