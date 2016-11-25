#ifndef NAVE_H
#define NAVE_H

#include "bitmap.h"
#include "gun.h"

#define NAVE_UP    0
#define NAVE_RIGHT 32
#define NAVE_LEFT  64

class NAVE : public BITMAP {
private:
  GUN nave_gun;
public:
  NAVE();

  void shoot();
  void get_ammo_info();
  void draw_nave(const int _nave_no);
};

#endif // NAVE_H
