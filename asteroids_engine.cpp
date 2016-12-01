//
// Created by kevin on 22/11/16.
//

#include "asteroids_engine.h"
#include "nave.h"
#include "game.h"

using namespace std;

/* Constructor ROA
 * Genera aleatoariamente el numero de asteroides para esta fila
 * Genera aleatoariamente un tipo de asteroide para cada nuevo asteroide
 * Se crean nuevos asteroides, y se configuran sus coordenadas de manera aleatoria
 * Y se añaden al final del vector */
ROW_OF_ASTEROIDS::ROW_OF_ASTEROIDS()
{
  int no_of_asters = generate_random_no_of_asteroids();
  for (int i = 0; i < no_of_asters; i++)
  {
    int type = generate_random_type_of_asteroid();
    ASTEROID* new_aster = new ASTEROID(type_of_asters[type]);
    new_aster->setX(generate_random_coorX());
    new_aster->setY(generate_random_coorY());
    row.push_back(new_aster);
  }
  cout << "ROA: Nueva fila de asteroides." << endl;
}

/* Destructor ROA
 * Recorre los elementos restantes que queden en la fila al momento de cerra el juego y los elimina del heap */
ROW_OF_ASTEROIDS::~ROW_OF_ASTEROIDS()
{
  for (int i = 0; i < row.size(); i++)
    delete row[i];
  cout << "ROA: All deleted." << endl;
}

/* Metodo generate_random_no_of_asteroids
 * Genera un numero aleatorio, para designar el numero de asteroides de una fila
 * TODO: Añadir una variable miembro a ROA que mida la dificultad actual del juego y asi incremente el numero de asteroides que puede generar por fila */
int ROW_OF_ASTEROIDS::generate_random_no_of_asteroids()
{
  random_device randomDevice;
  mt19937 eng(randomDevice());
  uniform_int_distribution<> distr(3, 7);
  return distr(eng);
}

/* Metodo generate_random_type_of_asteroid()
 * Genera un numero aleatorio, para designar el tipo de asteroide
 * TODO: Añadir una variable miembro a ROA que mida la dificultad actual del juego, y asi agregar nuevos tipos de asteroides, más grandes */
int ROW_OF_ASTEROIDS::generate_random_type_of_asteroid()
{
  random_device randomDevice;
  mt19937 eng(randomDevice());
  uniform_int_distribution<> distr(0, 5);
  return distr(eng);
}

/* Metodos generate_random_coorX (1) , generate_random_coorY (2)
 * (1): Genera una coordenada X aleatoria, para designarla al objeto asteroide
 * (2): Genera una coordenada Y aleatoria, para designarla al objeto asteroide */
coor_t ROW_OF_ASTEROIDS::generate_random_coorX()
{
  random_device randomDevice;
  mt19937 eng(randomDevice());
  uniform_int_distribution<> distr(30, 600);
  return distr(eng);
}
coor_t ROW_OF_ASTEROIDS::generate_random_coorY()
{
  random_device randomDevice;
  mt19937 eng(randomDevice());
  uniform_int_distribution<> distr(0, 30);
  return distr(eng);
}

/* Metodo empty_row
 * Verifica si es que el vector de ROA, se encuentra vacio, y devuelve un bool (true o false), dependiendo del estado de la condicion */
bool ROW_OF_ASTEROIDS::empty_row()
{
  return row.empty();
}

/* Metodo reached_limit
 * Verifica si todos los asteroides dentro del vector de ROA, alcanzaron su limite en pantalla, devuelve un bool (true o false), dependiendo del estado de la condicion */
bool ROW_OF_ASTEROIDS::reached_limit()
{
  int count = 0;
  for (unsigned int i = 0; i < row.size(); i++)
  {
    if (row[i]->getY() >= 480) count++;
  }
  return (count == row.size());
}

/* Metodo check_asteroids
 * Verifica el estado de los asteroides en el vector row
 * Si es que el asteroide en la posicion i, tiene como coordenada Y igual a 480, significa que llego al limite en pantallay sera destruido
 * Si es que el asteroide en la posicion i, fue destruido sera eliminado.
 * En caso no se cumpla lo anterior, se verificara si el asteroide choco con el bitmap del parametro, si es que si ambos seran destruidos */
void ROW_OF_ASTEROIDS::check_asteroids(NAVE* nave)
{
  for (unsigned int i = 0; i < row.size(); i++)
  {
    if (row[i]->getY() == 480 || row[i]->destroyed)
    {
      delete row[i];
      row.erase(row.begin()+i);
    }
    else
    {
      GUN* nave_gun = nave->get_gun();
      nave_gun->check_bullets(*row[i]);

      if (nave->check_colision(*row[i]))
      {
        row[i]->destroyed = true;
        nave->destroyed = true;
      }
    }
  }
}

/* Metodo move_asteroids
 * Se encarga de mover todos los asteroides
 * TODO: Añadir una variable miembro a ROA que mida la dificultad del juego, y asi hacer que los asteroides se muevan mucho más rapido y/o  que tambien se muevan sus coordenadas X */
void ROW_OF_ASTEROIDS::move_asteroids()
{
  for (unsigned int i = 0; i < row.size(); i++)
  {
    row[i]->moveY(1.8);
  }
}

/* Metodo draw_asteroids
 * Dibuja los asteroides actuales en el vector, que todavia no han sido destruidos */
void ROW_OF_ASTEROIDS::draw_asteroids()
{
  for (unsigned int i = 0; i < row.size(); i++)
  {
    if (!row[i]->destroyed) row[i]->draw_asteroid();
  }
}

/* Metodo manage_asteroids
 * Encapsulamiento de los 2 metodos anteriores */
void ROW_OF_ASTEROIDS::move_and_draw_asteroids()
{
  move_asteroids();
  draw_asteroids();
}

ASTEROIDS_ENG::ASTEROIDS_ENG()
{
  generate_row();
  fps_to_gen = generate_random_fps();
}

ASTEROIDS_ENG::~ASTEROIDS_ENG()
{
  for (int i = 0; i < rows_of_asters.size(); i++)
  {
    delete_row(rows_of_asters[i]);
  }
  cout << "ASTEROIDS_ENG: Deleted all rows" << endl;
}

void ASTEROIDS_ENG::generate_row()
{
  cout << "ASTEROID_ENG: New row" << endl;
  ROW_OF_ASTEROIDS* new_row = new ROW_OF_ASTEROIDS;
  rows_of_asters.push_back(new_row);
  no_of_rows = rows_of_asters.size();
  cout << "ASTEROID_ENG: Tamaño del vector " << no_of_rows << endl;
}

void ASTEROIDS_ENG::delete_row(ROW_OF_ASTEROIDS* obj)
{
  delete obj;
}

int ASTEROIDS_ENG::generate_random_fps()
{
  random_device randomDevice;
  mt19937 eng(randomDevice());
  uniform_int_distribution<> distr(100, 120);
  return distr(eng);
}

void ASTEROIDS_ENG::check_asteroids(NAVE* nave)
{
  for (unsigned int i = 0; i < rows_of_asters.size(); i++)
  {
    if (rows_of_asters[i]->empty_row())
    {
      delete_row(rows_of_asters[i]);
      rows_of_asters.erase(rows_of_asters.begin() + i);
    }
    else if (rows_of_asters[i]->reached_limit())
    {
      delete_row(rows_of_asters[i]);
      rows_of_asters.erase(rows_of_asters.begin() + i);
    }
    else
    {
      rows_of_asters[i]->check_asteroids(nave);
    }
  }
}

void ASTEROIDS_ENG::move_draw_and_gen_asteroids(const GAME* game)
{
  int64_t frames = game->get_timer_count();
  if (frames % fps_to_gen == 0)
  {
    generate_row();
    fps_to_gen = generate_random_fps();
  }
  for (unsigned int i = 0; i < rows_of_asters.size(); i++)
  {
    rows_of_asters[i]->move_and_draw_asteroids();
  }
}
