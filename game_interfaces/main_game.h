//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_MAIN_GAME_H
#define SPACESHIP2_MAIN_GAME_H

#include "../tools_and_headers/spaceship_includes.h"
#include "../bitmap_interfaces/game_facade.h"

#define GAMEOVER true
#define PAUSE true
#define EXIT true

class MainGame
{
  private:
    static MainGame     *_instance;
    MainGame();

  private:
    AllegroDisplay      *display;
    AllegroEventQueue   *event_queue;
    AllegroTimer        *timer;
    ObjectsInterface       *objects;

    bool                 done_main;
    bool                 gameover_or_pause;

  public:
    ~MainGame();

    int getW() const;
    int getH() const;

    void set_display_color(unsigned char r, unsigned char g, unsigned char b);

    bool get_main_activity_state();
    bool get_game_activity_state();
    void set_main_activity_state(const bool state);
    void set_game_activity_state(const bool state);

    void show_menu();
    void start_timer();
    void wait_for_event(AllegroEvent& event);
    void manage_event(AllegroEvent& event);
    void event_timer();

    int64_t get_timer_count();

    static MainGame* get();
    static void       del();
};


#endif //SPACESHIP2_MAIN_GAME_H
