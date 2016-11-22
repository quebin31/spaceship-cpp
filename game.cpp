#include "game.h"

SCREEN *create_screen(const int w, const int h, const float fps) {
  SCREEN* temp = new SCREEN;

  temp->width = w;
  temp->height = h;
  temp->fps = fps;

  return temp;
}
void destroy_screen(SCREEN *screen) { delete screen; }

/// Constructor con SCREEN
GAME::GAME(SCREEN *nscreen) {
|0}

/// Destructor
GAME::~GAME() {
  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
  destroy_screen(screen);
}

/// Cambia el color del display, y borra lo que tenga
void GAME::set_display_color(int r, int g, int b) {
  al_set_target_bitmap(al_get_backbuffer(display));
  al_clear_to_color(al_map_rgb(r,g,b));
}

/// Inicia el timer
void GAME::start_timer() { al_start_timer(timer); }

/// Verifica si la cola de eventos esta vacia
bool GAME::event_queue_is_empty() { return al_is_event_queue_empty(event_queue); }

/// Devuelve la direccion del display
ALLEGRO_DISPLAY *GAME::get_display() { return display; }

/// Devuelve la direccion del event_queue
ALLEGRO_EVENT_QUEUE *GAME::get_event_queue() { return event_queue; }

/// Devuelve la direccion del timer
ALLEGRO_TIMER *GAME::get_timer() { return timer; }

/// Devuelve la direccion del screen
SCREEN *GAME::get_screen() { return screen; }
