//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_MAIN_GAME_H
#define SPACESHIP2_MAIN_GAME_H

#include "../tools_and_headers/spaceship_includes.h"
#include "../bitmap_interfaces/game_facade.h"


class MAIN_GAME
{
  private:
    static MAIN_GAME    *main_game_instance;
    MAIN_GAME();

  private:
    ALLEGRO_DISPLAY     *display;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_TIMER       *timer;
    OBJS_FACADE         *objects;

    bool                 done_main;
    bool                 gameover_or_pause;

  public:
    ~MAIN_GAME();

    int getW() const;
    int getH() const;

    void set_display_color(unsigned char r, unsigned char g, unsigned char b);

    bool get_main_activity_state();
    bool get_game_activity_state();
    void set_main_activity_state(const bool state);
    void set_game_activity_state(const bool state);

    void show_menu();
    void start_timer();
    void wait_for_event(ALLEGRO_EVENT& event);
    void manage_event(ALLEGRO_EVENT& event);
    void event_timer();

    int64_t get_timer_count();

    static MAIN_GAME* get();
    static void       del();
};


#endif //SPACESHIP2_MAIN_GAME_H
