//
// Created by kevin on 22/11/16.
//

#include "gun.h"


using namespace std;


/* Constructor GUN
 * munition (6): tamaño del cargador
 * actual_munition(6): balas disponibles
 * bullets_in_screen(0): numero de balas en la pantalla */
GUN::GUN(): munition(6), actual_munition(6), bullets_in_screen(0) {}

/* Destructor GUN
 * Recorre el vector, borrando todas las balas al momento en el que el juego termina */
GUN::~GUN()
{
  for (unsigned int i = 0; i < bullets.size(); i++){
    delete bullets[i];
    cout << "GUN: DELETED" << endl;
  }
}

/* Metodo shoot_gun
 * X, Y, middle_nave_X, middle_nave_Y: Valores para poder calcular donde aparecera la nueva bala
 * Se crea una nueva bala, se añade como ultimo elemento al vector
 * Se modifica sus valores de X e Y
 * Y el numero de balas en pantalla aumenta en 1 */
void GUN::shoot_gun(coor_t X, coor_t Y, int middle_nave_X, int middle_nave_Y)
{
  BULLET* bullet = new BULLET;
  this->bullets.push_back(bullet);
  bullet->setX(X+middle_nave_X);
  bullet->setY(Y+middle_nave_Y);
  bullets_in_screen += 1;
}


/* Metodo check_bullets
 * Ya que las balas unicamente interactuan con los asteroides, y los asteroides son manejados por ASTEROID_ENG, se recibe como argumento el motor de los asteroides
 * Recorre el vector de las balas, si es que la coordenada Y de una bala llega a ser igual que 50, se destruye dicha bala, ya que alcanzo el limite de la pantalla
 * Si es que la bala en la posicion i, fue destruida se borra del heap, y tambien se borra del vector
 * Y en caso no paso nada de lo anterior simplemente se verifica si es que esa bala, no choco con ningun asteroide todavia */
void GUN::check_bullets(BITMAP& obj){
  for (unsigned int i = 0; i < bullets.size(); i++)
  {
    if (bullets[i]->getY() == 50 || bullets[i]->destroyed)
    {
      delete bullets[i];
      bullets.erase(bullets.begin() + i);
    }
    else if (obj.check_colision(bullets[i]))
    {
      bullets[i]->destroyed = true;
      obj.destroyed = true;
    }
  }
}

/* Metodo move_bullets
 * Mueve las balas en 3 unidades hacia arriba */
void GUN::move_bullets()
{
  for (unsigned int i = 0; i < bullets.size(); i++)
  {
    bullets[i]->moveY(-3.0);
  }
}

/* Metodo draw_bullets
 * Se encarga de dibujar cada bala, y verifica que no hayan sido destruidas, ya que el proceso de borrado recien comienza despues de que se detecto una colision */
void GUN::draw_bullets()
{
  for (unsigned int i = 0; i < this->bullets.size(); i++)
  {
    if (!bullets[i]->destroyed) bullets[i]->draw_bitmap(0);
  }
}