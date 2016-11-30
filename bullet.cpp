#include "bullet.h"

using namespace std;

/* Constructor default
 * width, height (10): Tamaño de la bala que sera usado para futura deteccion de colisiones */
BULLET::BULLET(): BITMAP("bullet2.png")
{
  width = 10;
  height = 10;
  destroyed = false;
}



