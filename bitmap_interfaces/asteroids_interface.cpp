//
// Created by kevin on 7/12/16.
//

#include "asteroids_interface.h"

/* check_for_store
 * Verifica si exista algun asteroide ya creado en el almacen para sacarlo y usarlo nuevamente.
 * Si es que no hay ninguno para usar, se crea uno nuevo */
//ASTEROID *ASTEROIDS::check_for_store()
//{
//  if (!store.empty())
//  {
//    ASTEROID* aster = store.back();
//    store.pop_back();
//    aster->reset_bitmap();
//    return aster;
//  }
//  return new ASTEROID;
//}

/* generate_random_num_of_asters
 * Genera un numero aleatorio (int) entre 3 y 7.
 * El numero aleatorio generado representa el numero de asteroides que se creara para esa ronda. */
int ASTEROIDS::generate_random_num_of_asters()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(3, 7);
  return distr(eng);
}

/* generate_random_fps_count
 * Genera un numero aleatorio (int) entre 90 y 110.
 * El numero aleatorio generado representa el cada cuantos frames se debe crear una nueva ronda de asteroides.
 * (Varia cada vez que se cree una nueva ronda) */
int ASTEROIDS::generate_random_fps_count()
{
  std::random_device randomDevice;
  std::mt19937 eng(randomDevice());
  std::uniform_int_distribution<> distr(90, 110);
  return distr(eng);
}

/* create_new_row
 * Crea una nueva ronda de asteroides
 * Genera un numero aleatorio de asteroides.
 * En cada iteracion, invoca a la funcion check_for_store, que usa un asteroide creado anteriormente o crea uno nuevo.
 * Luego hace push_back al "nuevo" asteroide. */
void ASTEROIDS::create_new_row()
{
  int num_of_asters = generate_random_num_of_asters();
  for (int i = 0; i < num_of_asters; i++)
  {
    ASTEROID *new_aster = ASTEROIDS_STORE::check_for_store();
    aster.push_back(new_aster);
  }
}

/* ASTEROIDS
 * En la primera llamada crea una nueva ronda de asteroides.
 * Y genera un numero aleatorio para la generacion de asteroides. */
ASTEROIDS::ASTEROIDS()
{
  create_new_row();
  fps_to_gen = generate_random_fps_count();
}

/* ~ASTEROIDS
 * Borra los asteoides que se encuentran en aster y en store. */
ASTEROIDS::~ASTEROIDS()
{
  for (int i = 0; i < aster.size(); i++)
    delete aster[i];
  std::cout << "Asteroides eliminados \n";
}

/* update_asteroids
 * En caso se tenga que crear una nueva ronda de asteroides se crea.
 * Luego recorre el vector de asteroides y los mueve y dibuja. */
void ASTEROIDS::update_asteroids(int64_t frame_count)
{
  if (frame_count%fps_to_gen == 0)
  {
    create_new_row();
    fps_to_gen = generate_random_fps_count();
  }

  for (int i = 0; i < aster.size(); i++)
  {
    if (!aster[i]->getDestroyed())
    {
      aster[i]->moveY(2.5);
      aster[i]->draw_bitmap(0);
    }
  }
}

/* operator[], at
 * Devuelve por referencia el asteroide de la posicion index. */
ASTEROID *ASTEROIDS::operator[](std::size_t index)
{ return aster[index]; }
ASTEROID *ASTEROIDS::at(std::size_t index)
{ return aster.at(index); }

/* size
 * Devuelve el tamaño del vector de asteroides.*/
std::size_t ASTEROIDS::size()
{ return aster.size(); }

/* empty
 * Devuelve el valor que devuelva aster.empty(), que verifica si el vector esta vacio o no.*/
bool ASTEROIDS::empty()
{ return aster.empty(); }

/* erase
 * Coloca el asteroide de la posicion index, en el almacen y lo borra del vector aster. */
void ASTEROIDS::erase(std::size_t index)
{
  ASTEROID* temp = aster[index];
  ASTEROIDS_STORE::put_on_store(temp);
  aster.erase(aster.begin()+index);
}

std::vector<ASTEROID*> ASTEROIDS_STORE::store;

ASTEROIDS_STORE::~ASTEROIDS_STORE()
{
  for (int i = 0; i < store.size(); i++)
    delete store[i];
}

ASTEROID *ASTEROIDS_STORE::check_for_store()
{
  if (!store.empty())
  {
    ASTEROID* aster = store.back();
    store.pop_back();
    return aster;
  }
  return new ASTEROID;
}

void ASTEROIDS_STORE::put_on_store(ASTEROID *aster)
{
  aster->reset_bitmap();
  store.push_back(aster);
}
