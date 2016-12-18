#include "strategy_power_up.h"

strategy_power_up* strategy_power_up::_instance = 0;

std::vector<NaveGun*> strategy_power_up::guns;
std::vector<FILES*> strategy_power_up::files;

strategy_power_up::strategy_power_up(){
  FILES *arch1 = new FILES;
  FILES *arch2 = new FILES;
  FILES *arch3 = new FILES;
  arch1->name_file = "bullet2.png";
  arch1->width = 10;
  arch1->heigh = 10;
  arch2->name_file = "laser.png";
  arch2->width = 10;
  arch2->heigh = 39;
  //arch3->name_file = "inmunity.png";
  //arch3->width = 256;
  //arch3->width = 256;
  files.push_back(arch1);
  files.push_back(arch2);
  //files.push_back(arch3);
  for (unsigned i = 0; i < files.size(); i++){
    NaveGun* gun = new NaveGun(files[i]->name_file, files[i]->width, files[i]->heigh );
    guns.push_back(gun);
  }
}

strategy_power_up::~strategy_power_up(){
  for (unsigned i = 0; i < guns.size(); i++)
    delete guns[i];
  for (unsigned i = 0; i < files.size(); i++)
    delete files[i];
  delete _instance;
}

NaveGun* strategy_power_up::get_gun(int random){
  if (!(random < 0 || random >= files.size()))
    return guns[random];
}

int strategy_power_up::get_guns_size() {return guns.size();}
