#ifndef SOUND_H
#define SOUND_H

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

class Sound{
protected:
  ALLEGRO_SAMPLE* sound_move;
public:
  Sound();
  ~Sound();
  void play_sound_move();
};

#endif // SOUND_H
