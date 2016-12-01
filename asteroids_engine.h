//
// Created by kevin on 22/11/16.
//

#ifndef SPACESHIP_SET_OF_ASTEROIDS_H
#define SPACESHIP_SET_OF_ASTEROIDS_H

#include "asteroid.h"

class NAVE;

class ROW_OF_ASTEROIDS
{
private:
  vector<ASTEROID*> row;                                            /// Vector que almacena punteros a ASTEROID
public:
  ROW_OF_ASTEROIDS();                                               /// Constructor
  ~ROW_OF_ASTEROIDS();                                              /// Destructor

  int generate_random_no_of_asteroids();                            /// Genera aleatoriamente un numero de asteroides
  int generate_random_type_of_asteroid();                           /// Genera aleatoriamente un tipo de asteroide
  coor_t generate_random_coorX();                                   /// Genera aleatoriamente una coordenada X
  coor_t generate_random_coorY();                                   /// Genera aleatoriamente una coordenada Y

  bool empty_row();                                                 /// Verifica si la fila de asteroides esta vacia
  bool reached_limit();                                             /// Verifica si todos los asteroides llegaron al limite de la pantalla

  void check_asteroids(NAVE* nave);                                 /// Verifica el estado de los asteroides
  void move_asteroids();                                            /// Mueve los asteroides
  void draw_asteroids();                                            /// Dibuja los asteroides
  void move_and_draw_asteroids();                                   /// Encapsulamiento de las 2 funciones anteriores
};


class ASTEROIDS_ENG
{
private:
  vector<ROW_OF_ASTEROIDS*> rows_of_asters;
  unsigned long no_of_rows;
  int fps_to_gen;
public:
  ASTEROIDS_ENG();
  ~ASTEROIDS_ENG();

  void generate_row();
  void delete_row(ROW_OF_ASTEROIDS* obj);

  int generate_random_fps();

  void check_asteroids(NAVE* nave);
  void move_draw_and_gen_asteroids(const GAME* game);

};


#endif //SPACESHIP_SET_OF_ASTEROIDS_H
