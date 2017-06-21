//
// Created by kevin on 1/06/17.
//

#ifndef SPACESHIP_MAINGAME_H
#define SPACESHIP_MAINGAME_H

#include "SpaceShipIncludes.h"

const GameFlags MAIN_LOOP { 0x01 };
const GameFlags GAME_OVER { 0x02 };
const GameFlags PAUSE     { 0x04 };

class MainGame {
private:
		static MainGame *instance;
		MainGame();
		
		AllegroDisplay        *display;
		AllegroEventQueue     *eventQueue;
		AllegroTimer          *timer;
		AllegroAudio          *audio;
		AllegroAudioInstance  *instanceSong;
		GameFlags              stateFlags;
		
public:
		~MainGame();
		
		int getDisplayWidth() const;
		
		void setDisplayColor(Color r, Color g, Color b);
		
		
		GameFlags getFlags();
		void setFlags(GameFlags newState);
		
		void showMenu();
		void startTimer();
		void waitForEvent(AllegroEvent& event);
		void manageEvent(AllegroEvent& event);
		void eventTimer();
		
		TimerType getTimerCount();
		
		void resetGame();
		
		static MainGame* get();
		static void      del();
		
};

#endif //SPACESHIP_MAINGAME_H
