#ifndef GAME_H
#define GAME_H

<<<<<<< HEAD
#include "allegro_includes.h"
=======
#include "types.h"
#include <cstdio>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

#define MAIN_MENU 0
#define PAUSE     2
>>>>>>> 724a8db93a258487e85f9c7b3846ed888840c571

typedef struct SCREEN {
  int width;      /// Ancho
  int height;     /// Alto
  float fps;      /// FPS (Frames Per Second)
} SCREEN;

SCREEN* create_screen(const int w, const int h, const float fps);
void destroy_screen(SCREEN*);

class GAME {
  private:
    ALLEGRO_DISPLAY       *display;               /// ALLEGRO_DISPLAY
    ALLEGRO_EVENT_QUEUE   *event_queue;           /// ALLEGRO_EVENT_QUEUE
    ALLEGRO_TIMER         *timer;                 /// ALLEGRO_TIMER
    SCREEN                *screen;                /// SCREEN
    ALLEGRO_FONT          *font1;                 /// Fuente para el titulo principal
    ALLEGRO_FONT          *font2;                 /// Fuente para las instrucciones
  public:
    bool                  game_over_or_pause;              /// Game Over (bool), controla el while principal del juego
    int                   vidas;                  /// Vidas del juego

    GAME(SCREEN* nscreen);                        /// Constructor de GAME en base a la pantalla
    ~GAME();                                      /// Destructor

    void set_display_color(int r, int g, int b);  /// Colorea el display
    void start_timer();                           /// Empieza el timer (FPS)
    void show_menu();                             /// Muestra el menu del juego
    bool event_queue_is_empty();                  /// Verifica si la lista de eventos ya esta vacia

    ALLEGRO_DISPLAY*      get_display();          /// Devuelve la direccion del display
    ALLEGRO_EVENT_QUEUE*  get_event_queue();      /// Devuelve la direccion del event queue
    ALLEGRO_TIMER*        get_timer();            /// Devuelve la direccion del timer
    SCREEN*               get_screen();           /// Devuelve la direccion del screen template
    ALLEGRO_FONT*         get_font1();            /// Devuelve la fuente del titulo principal
    ALLEGRO_FONT*         get_font2();            /// Devuelve la fuente de los titulos para instrucciones
    int64_t               get_timer_count();      /// Devuelve la cantidad de frames desde que se inicio el timer
};

#endif // GAME_H
