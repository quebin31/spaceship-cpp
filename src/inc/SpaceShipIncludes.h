//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_SPACESHIPINCLUDES_H
#define SPACESHIP_SPACESHIPINCLUDES_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <random>
#include <sstream>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>

#include "Random.h"
#include "String.h"
#include "MiscTool.h"
#include "ScoreInterface.h"

typedef ALLEGRO_DISPLAY AllegroDisplay;
typedef ALLEGRO_EVENT_QUEUE AllegroEventQueue;
typedef ALLEGRO_TIMER AllegroTimer;
typedef ALLEGRO_EVENT AllegroEvent;
typedef ALLEGRO_BITMAP AllegroBitmap;
typedef ALLEGRO_FONT AllegroFont;
typedef ALLEGRO_SAMPLE AllegroAudio;
typedef ALLEGRO_SAMPLE_INSTANCE AllegroAudioInstance;

typedef int8_t GameFlags;
typedef int64_t TimerType;
typedef unsigned char Color;

#endif //SPACESHIP_SPACESHIPINCLUDES_H
