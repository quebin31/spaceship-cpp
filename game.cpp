#include <stdlib.h>
#include "game.h"
#include "keyboard.h"
#include "nave.h"
#include "asteroids_engine.h"
#include "bitmap.h"

using namespace std;

/* SCREEN create_screen
 * Crea una nueva plantilla para la pantalla */
SCREEN *create_screen(const int w, const int h, const float fps) {
  SCREEN* temp = new SCREEN;

  temp->width = w;
  temp->height = h;
  temp->fps = fps;

  return temp;
}

/* SCREEN destroy_screen
 * Destruye la plantilla de la pantalla */
void destroy_screen(SCREEN *screen) { delete screen; }

/* Constructor GAME
 * al_init() inicia el plugin de Allegro, si es que devuelve falso (fallo), muestra un mensaje del fallo y cierra el programa
 * al_init_image_addon() inicia el plugin de imagen de Allegro, si es que devuelve falso (fallo), muestra un mensaje del fallo y cierra el programa
 * al_init_font_addon() inicia el plugin de fuentes de Allegro, si es que devuelve falso (fallo), muestra un mensaje del fallo y cierra el programa
 * al_init_ttf_addon() inicia el plugin de ttf de Allegro, si es que devuelve falso (fallo), muestra un mensaje del fallo y cierra el programa
 * al_init_acodec_addon() inicia el plugin de acodec de Allegro, si es que devuelve falso (fallo), muestra un mensaje del fallo y cierra el programa
 * al_install_audio() inicia el servicio de audio, para que pueda ser controlado por Allegro
 * al_install_keyboard() inicia el servicio del teclado, para que pueda ser controlado por Allegro
 * al_create_display(), crea un display nuevo de Allegro
 * al_create_event_queue(), crea una cola de eventos, donde se guardaran todos los eventos por venir (FPS, teclado, etc)
 * al_create_timer(), crea el timer, que manda un nuevo evento cada cierto tiempo (1/60 segundos es lo normal)
 * done, (bool) controla el while principal del juego
 * gameover_or_pause, (bool) controla el while de la actividad del juego
 * vidas, (int) vidas que tiene el jugador antes de perder el juego
 * al_register_event_source, registra los diferentes eventos que ocurriran durante el juego
 * al_load_font, carga fuentes y las guarda (font1, font2)
 * al_load_sample, carga audio y lo guarda (move_sound)
 * framework, (marco del juego), un simple bitmap que funciona como marco del juego*/
GAME::GAME(SCREEN *ndisplay) : screen(ndisplay)
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
  display = al_create_display(screen->width, screen->height);
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
  timer = al_create_timer(1.0 / screen->fps);
  if (!timer)
  {
    al_show_native_message_box(display,"Error","Error","Failed to initialize timer!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: La pantalla actual es de " << screen->width << "x" << screen->height << endl;

  done = false;
  game_over_or_pause = false;
  invulnerable = false;
  vidas = 3;
  destroyed_at = 0;

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

  cout << "GAME: Cargando marco" << endl;
  framework = new BITMAP("marco.png");
  int framewk_w = 600, framewk_h = 440;
  framework->setW(framewk_w);
  framework->setH(framewk_h);
  life1 = new LIFE;
  //life2 = new LIFE;
  //life3 = new LIFE;
  life1->setX(40);
  life1->setY(40);
  //life2->setX(70);
  //life2->setY(40);
  //life3->setX(100);
  //life3->setY(40);
  al_set_window_position(display, 350, 180);
  set_display_color(26,26,26);
  cout << "GAME: All done." << endl;
}

/* Desctructor GAME
 * Destruye todos los objetos creados anteriormente:
 * screen
 * display
 * timer
 * event_queue
 * font1
 * font2
 * move_sound
 * framework*/
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
  delete framework;
  delete life1;
  delete life2;
  delete life3;
  cout << "GAME: All done. Bye." << endl;
}

/* Metodo set_display_color
 * Recolorea el display, haciendo que todos los objetos que estaban en pantalla sean sobrepuestos por el nuevo color */
void GAME::set_display_color(int r, int g, int b)
{
  al_set_target_bitmap(al_get_backbuffer(display));
  al_clear_to_color(al_map_rgb(r,g,b));
}

/* Metodo start_timer
 * Inicia el timer del juego, para que mande un evento cada 1/60 segundos */
void GAME::start_timer()
{
  cout << "GAME: Iniciando el timer" << endl;
  al_start_timer(timer);
  game_over_or_pause = false;
}

/* Metodo wait_for_event
 * Espera la señal de algun evento y lo guarda en un receptor que luego sera usado para saber de que tipo de evento se trataba y asi poder actuar al respecto */
void GAME::wait_for_event(ALLEGRO_EVENT &ev) { al_wait_for_event(event_queue, &ev); }

/* Metodo show_menu
 * Muestra el menu del juego, dependiendo de si el juego recien se inicio muestra la pantalla de bienvenida, en caso contrario, muestra la pantalla de pausa */
void GAME::show_menu()
{
  int64_t flag = al_get_timer_count(timer);
  char* title;
  char* state;
  if (flag == 0)
  {
    title = "ASTEROID GAME";
    state = "INICIAR (PRESIONA ENTER)";
  }
  else if (vidas == 0)
  {
    title = "GAME OVER";
    state = "REINICIAR (PRESIONA ENTER)";
  }
  else
  {
    title = "PAUSE";
    state = "RESUMIR (PRESIONA ENTER)";
  }
  set_display_color(26,26,26);
  al_draw_text(font1, al_map_rgb(200,10,50), screen->width/2, screen->height/2, ALLEGRO_ALIGN_CENTRE, title);
  al_draw_text(font2, al_map_rgb(20,30,60), screen->width/2, screen->height/2+60, ALLEGRO_ALIGN_CENTRE, state);
  al_draw_text(font2, al_map_rgb(20,30,60), screen->width/2, screen->height/2+120, ALLEGRO_ALIGN_CENTRE,"SALIR (PRESIONA ESCAPE)");
  al_flip_display();
}

/* Metodo event_timer
 * Cuando la señal del evento recibida sea del tipo de timer, se realizaran las siguientes acciones:
 * Se verificara el estado de las teclas, de acuerdo a eso se movera la nave y se seleccionara su posicion (hacia donde mira)
 * Tambien se puede verificar, si se apreto la tecla A, que hace que dispare la nave, pero solo dispara cada cierto tiempo
 * Se limpia el display, se verifican las colisiones de la nave con los asteroides (lo que incluye choce nave con asteroide, y balas con asteroides)
 * Luego se mueven y dibujan las balas, tambien los asteroides y en caso se necesite tambien se genera una nueva fila de asteroides
 * Se dibuja la nave, y se dibuja el marco del juego, por ultimo se muestra el display.*/
void GAME::event_timer(KEYBOARD &keyboard, NAVE &nave, ASTEROIDS_ENG &asters) {
  if (keyboard.get_key_state(UP) && nave.getY() >= 4.0 + 76)
  {
    nave.moveY(-4.0);
    nave.select_nave(NAVE_UP);
    play_move_sound();
  }
  else if (keyboard.get_key_state(RIGHT) && nave.getX() <= framework->getW() - nave.getW() - 4.0 )
  {
    nave.moveX(4.0);
    nave.select_nave(NAVE_RIGHT);
    play_move_sound();
  }
  else if (keyboard.get_key_state(DOWN) && nave.getY() <= framework->getH() - nave.getH() - 4.0)
  {
    nave.moveY(4.0);
    nave.select_nave(NAVE_UP);
    play_move_sound();
  }
  else if (keyboard.get_key_state(LEFT) && nave.getX() >= 4.0 + 40)
  {
    nave.moveX(-4.0);
    nave.select_nave(NAVE_LEFT);
    play_move_sound();
  }
  else
  {
    nave.select_nave(NAVE_UP);
  }

  if (keyboard.get_key_state(CHAR_A) && get_timer_count()%18 == 0)
  {
    nave.shoot();
  }

  if (!invulnerable)
  {
    if (nave.destroyed)
    {
      vidas -= 1;
      invulnerable = true;
      destroyed_at = get_timer_count();
    }
  }
  else
  {
    if (nave.destroyed)
    {
      if (get_timer_count() == destroyed_at + 90)
      {
        invulnerable = false;
        nave.destroyed = false;
      }
    }
  }

  if (vidas == 0)
  {
    game_over_or_pause = true;
  }

  set_display_color(26,26,26);
  nave.check_colisions(asters);
  nave.move_and_draw_bullets();
  asters.move_draw_and_gen_asteroids(this);
  nave.draw_nave();
  framework->draw_bitmap(0);
  life1->draw_life();
  //life2->draw_life();
  //life3->draw_life();
  al_flip_display();
}

void GAME::manage_events(ALLEGRO_EVENT &ev, KEYBOARD& keyboard, NAVE& nave, ASTEROIDS_ENG& asters)
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

int64_t GAME::get_timer_count()const { return al_get_timer_count(timer); }

int GAME::get_framework_W() {
  return framework->getW();
}

int GAME::get_framework_H() {
  return framework->getH();
}
