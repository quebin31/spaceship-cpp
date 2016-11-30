//
// Created by kevin on 21/11/16.
//

#ifndef GAMENAVE_ASTEROID_H
#define GAMENAVE_ASTEROID_H

#include "bitmap.h"

#define NO_1  0
#define NO_2  45
#define NO_3  90
#define NO_4  135
#define NO_5  180

using namespace std;

extern int myAster[];                                   /// Arreglo con los valores NO_N (N = 1,2,3,4,5)
extern vector<int> type_of_asters;                      /// Vector que almacene los valores anteriores

class ASTEROID: public BITMAP
{
  public:
    ASTEROID(const int _no_asteroid);                   /// Constructor

    void draw_asteroid() const;                         /// Dibuja el asteroide
    void draw_asteroid();                               /// Dibuja el asteroide
};


#endif //GAMENAVE_ASTEROID_H
