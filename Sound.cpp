#include "Sound.h"

Sound::Sound(){
  cout << "GAME: Iniciando allegro acodec" << endl;
  if (!al_init_acodec_addon()) {
    al_show_native_message_box(display,"Error","Error","Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  cout << "GAME: Iniciando allegro audio" << endl;
  if (!al_install_audio()) {
    al_show_native_message_box(display,"Error","Error","Failed to initialize allegro!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
    exit(EXIT_FAILURE);
  }

  sound_move = al_load_sample("thrust.wav");
}

Sound::~Sound()
{
  al_destroy_sample(sound_move);
  al_uninstall_audio();
}

void Sound::play_sound_move(){
  al_play_sample(sound_move, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
}
