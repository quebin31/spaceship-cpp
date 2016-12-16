//
// Created by kevin on 8/12/16.
//

#ifndef SPACESHIP2_GAME_OBJECTS_H
#define SPACESHIP2_GAME_OBJECTS_H


#include "../bitmap_objects/image.h"
#include "../bitmap_objects/nave.h"
#include "asteroids_interface.h"
#include "bullet_interface.h"
#include "hearts_interface.h"
#include "../bitmap_objects/power_up.h"

class OBJS_FACADE
{
  private:
    NAVE_GUN        *nave_gun;
    ASTEROIDS       *asteroids;
    HEARTS          *hearts;
    IMAGE           *frame;
    std::string      score;

  private:
    ALLEGRO_FONT    *title_font;
    ALLEGRO_FONT    *options_font;
    ALLEGRO_FONT    *score_font;

  public:
    OBJS_FACADE();
    ~OBJS_FACADE();

    void show_menu();

    void check_bullets_with_asteroids();
    void check_nave_with_asteroids();
    void check_nave_with_powerups();
    void receive_score();

    void update_objects();

    void draw_objects();
    void draw_information();

    bool no_hearts();
};


#endif //SPACESHIP2_GAME_OBJECTS_H
