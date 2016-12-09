#include <iostream>
#include "game_interfaces/main_game.h"

using namespace std;

int main(int argc, const char **argv)
{
  cout << "MAIN: Starting game " << endl;
  while (!MAIN_GAME::get()->get_main_activity_state()){
    MAIN_GAME::get()->show_menu();
    ALLEGRO_EVENT event;
    MAIN_GAME::get()->wait_for_event(event);

    if (event.type == ALLEGRO_EVENT_KEY_UP && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
    {
      MAIN_GAME::get()->set_main_activity_state(EXIT);
      cout << "MAIN: Saliendo" << endl;
    }
    else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
      MAIN_GAME::get()->set_main_activity_state(EXIT);
      cout << "MAIN: Saliendo" << endl;
    }
    else if(event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
    {
      MAIN_GAME::get()->start_timer();

      while (!MAIN_GAME::get()->get_game_activity_state())
      {
        ALLEGRO_EVENT ev;
        MAIN_GAME::get()->wait_for_event(ev);
        MAIN_GAME::get()->manage_event(ev);
      }
    }
  }
  cout << "MAIN: Tiempo transcurrido: " << al_get_time() << endl;
  return 0;
}