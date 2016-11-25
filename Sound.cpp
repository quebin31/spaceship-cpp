#include "Sound.h"

using namespace std;

Sound::Sound(){
  sound_move = al_load_sample("thrust.wav");
  al_reserve_samples(1);
}

Sound::~Sound()
{
  al_destroy_sample(sound_move);
  al_uninstall_audio();
}

void Sound::play_sound_move(){
  al_play_sample(sound_move, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
}
