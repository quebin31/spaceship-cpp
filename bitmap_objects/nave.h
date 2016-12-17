//
// Created by kevin on 7/12/16.
//

#ifndef SPACESHIP2_NAVE_H
#define SPACESHIP2_NAVE_H

#include "bitmap.h"

#define NAVE_UP    0
#define NAVE_RIGHT 32
#define NAVE_LEFT  64

class NaveGun;

class Nave : public Bitmap
{
  private:
    NaveGun       *nave_gun;
    static Nave   *_instance;
    int64_t        destroyed_at;

  public:
    Nave();
    ~Nave() override;

    static Nave* Instance();

    void shoot_gun();
    void update_bullets();
    NaveGun* getGun();

    void make_invulnerable(const int64_t fps_count);
    void make_vulnerable();
    int64_t getWhenDestroyed();

    void draw_bitmap(const int flags) override;
    void reset_bitmap() override;
};


#endif //SPACESHIP2_NAVE_H
