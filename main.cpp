#include <iostream>
#include "game_interfaces/main_game.h"

using namespace std;

int main(int argc, const char **argv)
{
  cout << "MAIN: Starting game " << endl;
  while (!MainGame::get()->get_main_activity_state()){
    MainGame::get()->show_menu();
    AllegroEvent event;
    MainGame::get()->wait_for_event(event);

    if (event.type == ALLEGRO_EVENT_KEY_UP && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
    {
      MainGame::get()->set_main_activity_state(EXIT);
      cout << "MAIN: Saliendo" << endl;
    }
    else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    {
      MainGame::get()->set_main_activity_state(EXIT);
      cout << "MAIN: Saliendo" << endl;
    }
    else if(event.type == ALLEGRO_EVENT_KEY_UP && event.keyboard.keycode == ALLEGRO_KEY_ENTER)
    {
      MainGame::get()->start_timer();

      while (!MainGame::get()->get_game_activity_state())
      {

        AllegroEvent ev;
        MainGame::get()->wait_for_event(ev);
        MainGame::get()->manage_event(ev);
      }
    }
  }

  cout << "MAIN: Tiempo transcurrido: " << al_get_time() << endl;
  MainGame::del();
  return 0;
}

