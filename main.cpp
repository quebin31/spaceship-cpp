//
// Created by kevin on 21/11/16.
//

#include "game.h"
#include "nave.h"
#include "keyboard.h"
#include "set_of_asteroids.h"

using namespace std;

SCREEN* screen = create_screen(640,480,60);
int direction  = NAVE_UP;

int main(int argc, const char **argv){
  GAME           SpaceShip(screen, 600, 440);
  KEYBOARD       keyboard;
  NAVE           nave;
  ASTEROIDS_ENG  asters;
  cout << "MAIN: Todos los objetos fueron creados correctamente" << endl;

  nave.setX((coor_t)(SpaceShip.get_framework_W()  / 2.0 - nave.getW()  / 2.0));
  nave.setY((coor_t)(SpaceShip.get_framework_H()  / 2.0 - nave.getH()  / 2.0 + 200));

  cout << "MAIN: Starting game " << endl;
  while (!SpaceShip.done){
    SpaceShip.show_menu();
    ALLEGRO_EVENT event;
    SpaceShip.wait_for_event(event);

    if (event.type == ALLEGRO_EVENT_KEY_UP && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
    {
      SpaceShip.done = true;
      cout << "MAIN: Saliendo" << endl;
    }
    else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
      SpaceShip.done = true;
      cout << "MAIN: Saliendo" << endl;
    }
    else if(event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
    {
      SpaceShip.set_display_color(0, 0, 0);
      nave.draw_nave(NAVE_UP);
      al_flip_display();
      SpaceShip.start_timer();

      while (!SpaceShip.game_over_or_pause)
      {
        ALLEGRO_EVENT ev;
        SpaceShip.wait_for_event(ev);
        SpaceShip.manage_events(ev, keyboard, nave, asters);
      }
    }
  }
  cout << "MAIN: Numero de fotogramas al terminar: " << SpaceShip.get_timer_count() << endl;
  cout << "MAIN: Tiempo transcurrido: " << al_get_time() << endl;
  return 0;
}
