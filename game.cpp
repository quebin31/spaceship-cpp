#include <stdlib.h>
#include "game.h"
#include "keyboard.h"
#include "nave.h"

using namespace std;

SCREEN *create_screen(const int w, const int h, const float fps) {
  SCREEN* temp = new SCREEN;

  temp->width = w;
  temp->height = h;
  temp->fps = fps;

  return temp;
}
void destroy_screen(SCREEN *screen) { delete screen; }

/// Constructor con SCREEN
GAME::GAME(SCREEN *nscreen): screen(nscreen)
{
  cout << "GAME: Iniciando allegro" << endl;
  if (!al_init())
  {
    al_show_native_message_box(display,"Error","Error","Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando allegro image" << endl;
  if (!al_init_image_addon())
  {
    al_show_native_message_box(display,"Error","Error","Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando allegro font" << endl;
  if (!al_init_font_addon())
  {
    al_show_native_message_box(display,"Error","Error","Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando allegro ttf" << endl;
  if (!al_init_ttf_addon())
  {
    al_show_native_message_box(display,"Error","Error","Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando allegro acodec" << endl;
  if (!al_init_acodec_addon())
  {
    al_show_native_message_box(display,"Error","Error","Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando allegro audio" << endl;
  if (!al_install_audio())
  {
    al_show_native_message_box(display,"Error","Error","Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando el teclado" << endl;
  if (!al_install_keyboard())
  {
    al_show_native_message_box(display,"Error","Error","Failed to initialize keyboard!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando el display" << endl;
  display = al_create_display(nscreen->width, nscreen->height);
  if (!display)
  {
    al_show_native_message_box(display,"Error","Error","Failed to initialize display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    al_destroy_timer(timer);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando la cola de eventos" << endl;
  event_queue = al_create_event_queue();
  if (!event_queue)
  {
    al_show_native_message_box(display,"Error","Error","Failed to initialize bitmap!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    al_destroy_display(display);
    al_destroy_timer(timer);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando el timer" << endl;
  timer = al_create_timer(1.0 / nscreen->fps);
  if (!timer)
  {
    al_show_native_message_box(display,"Error","Error","Failed to initialize timer!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: La pantalla actual es de " << screen->width << "x" << screen->height << endl;

  done = false;
  game_over_or_pause = false;
  vidas = 3;

  cout << "GAME: Registrando todos los eventos" << endl;
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source());

  cout << "GAME: Cargando las fuentes" << endl;
  font1 = al_load_font("PressStart2P.ttf",30,0);
  font2 = al_load_font("Joystick.otf",20,0);

  cout << "GAME: Cargando el audio" << endl;
  move_sound = al_load_sample("thrust.wav");
  al_reserve_samples(1);

  al_set_window_position(display, 350, 180);
  set_display_color(0,0,0);
  cout << "GAME: All done." << endl;
}

/// Destructor
GAME::~GAME()
{
  cout << "GAME: Finalizando el juego" << endl;
  destroy_screen(screen);
  al_destroy_display(display);
  al_destroy_timer(timer);
  al_destroy_event_queue(event_queue);
  al_destroy_font(font1);
  al_destroy_font(font2);
  al_destroy_sample(move_sound);
  cout << "GAME: All done. Bye." << endl;
}

/// Cambia el color del display, y borra lo que tenga
void GAME::set_display_color(int r, int g, int b)
{
  al_set_target_bitmap(al_get_backbuffer(display));
  al_clear_to_color(al_map_rgb(r,g,b));
}

/// Inicia el timer
void GAME::start_timer()
{
  cout << "GAME: Iniciando el timer" << endl;
  al_start_timer(timer);
  game_over_or_pause = false;
}

/// Espera por un evento de SpaceShip
void GAME::wait_for_event(ALLEGRO_EVENT &ev) { al_wait_for_event(event_queue, &ev); }

/// Muestra el menu inicial o de pausa
void GAME::show_menu()
{
  int64_t flag = al_get_timer_count(timer);
  const char* state = (flag == 0) ? "INICIAR (PRESIONA ENTER)" : "RESUMIR (PRESIONA ENTER)";
  const char* title = (flag == 0) ? "ASTEROID GAME" : "PAUSE";
  set_display_color(0,0,0);
  al_draw_text(font1, al_map_rgb(200,10,50), screen->width/2, screen->height/2, ALLEGRO_ALIGN_CENTRE, title);
  al_draw_text(font2, al_map_rgb(20,30,60), screen->width/2, screen->height/2+60, ALLEGRO_ALIGN_CENTRE, state);
  al_draw_text(font2, al_map_rgb(20,30,60), screen->width/2, screen->height/2+120, ALLEGRO_ALIGN_CENTRE,"SALIR (PRESIONA ESCAPE)");
  al_flip_display();
}

void GAME::event_timer(KEYBOARD &keyboard, NAVE &nave, ROW_OF_ASTEROIDS &asters) {
  if (keyboard.get_key_state(UP) && nave.getY() >= 4.0)
  {
    nave.moveY(-4.0);
    nave.select_nave(NAVE_UP);
    play_move_sound();
  }
  else if (keyboard.get_key_state(RIGHT) && nave.getX() <= screen->width - nave.getW() - 4.0)
  {
    nave.moveX(4.0);
    nave.select_nave(NAVE_RIGHT);
    play_move_sound();
  }
  else if (keyboard.get_key_state(DOWN) && nave.getY() <= screen->height - nave.getH() - 4.0)
  {
    nave.moveY(4.0);
    nave.select_nave(NAVE_UP);
    play_move_sound();
  }
  else if (keyboard.get_key_state(LEFT) && nave.getX() >= 4.0)
  {
    nave.moveX(-4.0);
    nave.select_nave(NAVE_LEFT);
    play_move_sound();
  }

  if (keyboard.get_key_state(CHAR_A))
  {
    nave.shoot();
    keyboard.change_key_state(CHAR_A, false);
  }

  set_display_color(0, 0, 0);
  asters.manage_asteroids(nave);
  nave.draw_nave();
  al_flip_display();
}

void GAME::manage_events(ALLEGRO_EVENT &ev, KEYBOARD& keyboard, NAVE& nave, ROW_OF_ASTEROIDS& asters)
{
  if (ev.type == ALLEGRO_EVENT_TIMER)
    event_timer(keyboard, nave, asters);
  else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
    keyboard.key_down_event(ev);
  else if (ev.type == ALLEGRO_EVENT_KEY_UP)
    keyboard.key_up_event(ev, this);
  else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
    exit(EXIT_SUCCESS);
}

/// Reproduce el audio move_sound
void GAME::play_move_sound() { al_play_sample(move_sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0); }

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

/// Devuelve la fuente del titulo principal
ALLEGRO_FONT *GAME::get_font1() { return font1;}

/// Devuelve la fuente de los titulos de instrucciones
ALLEGRO_FONT *GAME::get_font2() { return font2;}


int64_t GAME::get_timer_count() { return al_get_timer_count(timer); }


