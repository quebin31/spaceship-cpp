//
// Created by kevin on 21/11/16.
//

#include "asteroid.h"

/* myAster[], contiene los macros para la eleccion de asteroides
 * type_of_asters, contiene los valores antes mencionados */
int myAster[] = {NO_1, NO_2, NO_3, NO_4, NO_5};
vector<int> type_of_asters(myAster, myAster+5);

/* Constructor ASTEROID
 * type_aster, tipo de asteroid que sera (1,2,3,4,5)
 * "asteroides.png", direccion de la imagen de los asteroides */
ASTEROID::ASTEROID(const int _no_asteroid): BITMAP("asteroides.png")
{
  destroyed = false;
  width = 45;
  height = 45;
  posX = 0;
  posY = 0;
  sourceX = _no_asteroid;
  sourceY = 0;
}

/* Metodo draw_asteroid
 * Agiliza el proceso de dibujado del asteroide */
void ASTEROID::draw_asteroid() const
{
  al_draw_bitmap_region(bitmap, sourceX, sourceY, 45, 45, posX, posY, 0);
}
void ASTEROID::draw_asteroid()
{
  al_draw_bitmap_region(bitmap, sourceX, sourceY, 45, 45, posX, posY, 0);
}



