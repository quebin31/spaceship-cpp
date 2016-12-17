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

class ObjectsFacade
{
  private:
<<<<<<< HEAD
    Nave              *nave;
    NaveGun           *nave_gun;
    Hearts            *hearts;
    Image             *frame;
    std::string       score;
=======
    NAVE_GUN        *nave_gun;
    ASTEROIDS       *asteroids;
    HEARTS          *hearts;
    IMAGE           *frame;
    std::string      score;
>>>>>>> 27e201519406282de8a3c267430e611e08b76ca1

  private:
    AllegroFont       *title_font;
    AllegroFont       *options_font;
    AllegroFont       *score_font;

  public:
    ObjectsFacade();
    ~ObjectsFacade();

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
