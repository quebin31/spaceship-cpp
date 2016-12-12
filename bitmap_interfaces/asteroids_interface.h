//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_ASTEROIDS_INTERFACE_H
#define SPACESHIP2_ASTEROIDS_INTERFACE_H

#include "../bitmap_objects/asteroid.h"

class ASTEROIDS_STORE
{
  private:
    static std::vector<ASTEROID*> store;

  public:
    ASTEROIDS_STORE() {}
    ~ASTEROIDS_STORE();

    static ASTEROID* check_for_store();
    static void put_on_store(ASTEROID* aster);
};

class ASTEROIDS
{
  private:
    std::vector<ASTEROID*> aster;
    int fps_to_gen;

    int  generate_random_num_of_asters();
    int  generate_random_fps_count();
    void create_new_row();

  public:
    ASTEROIDS();
    ~ASTEROIDS();

    void update_asteroids(int64_t frame_count);

    ASTEROID* operator[](std::size_t index);
    ASTEROID* at(std::size_t index);
    std::size_t size();
    bool empty();

    void erase(std::size_t index);
};


#endif //SPACESHIP2_ASTEROIDS_INTERFACE_H
