//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_ASTEROIDS_INTERFACE_H
#define SPACESHIP2_ASTEROIDS_INTERFACE_H

#include "../bitmap_objects/asteroid.h"

class NAVE;

class ASTEROIDS
{
  private:
    std::vector<ASTEROID*> aster;
    std::vector<ASTEROID*> store;
    int fps_to_gen;

    ASTEROID* check_for_store();

    int  generate_random_fps_count();
    int  generate_random_num_of_asters();
    void create_new_row();

  public:
    ASTEROIDS();
    ~ASTEROIDS();

    void update_asteroids(int64_t frame_count);
    std::size_t size();
    bool empty();

    ASTEROID* operator[](std::size_t index);
    ASTEROID* at(std::size_t index);
    void put_on_store(std::size_t index);
};


#endif //SPACESHIP2_ASTEROIDS_INTERFACE_H
