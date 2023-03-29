#include "../../include/sys/audiomgr.h"

Sounds::Sounds() {
  this->channel = 0;
  FMOD::System_Create(&this->system);
  system->init(32, FMOD_INIT_NORMAL, 0);
  system->createSound(music::BOOST, FMOD_DEFAULT, 0, &boost);
  system->createSound(music::CHANGE, FMOD_DEFAULT, 0, &change);
  system->createSound(music::DEATH, FMOD_DEFAULT, 0, &death);
  system->createSound(music::JUMP, FMOD_DEFAULT, 0, &jump);
  system->createSound(music::LADDER, FMOD_DEFAULT, 0, &ladder);
  system->createSound(music::MAIN, FMOD_DEFAULT, 0, &main);
  system->createSound(music::MENU, FMOD_DEFAULT, 0, &menu);
  system->createSound(music::SHOT, FMOD_DEFAULT, 0, &shot);
  boost->setMode(FMOD_LOOP_OFF);
  change->setMode(FMOD_LOOP_OFF);
  death->setMode(FMOD_LOOP_OFF);
  jump->setMode(FMOD_LOOP_OFF);
  ladder->setMode(FMOD_LOOP_OFF);
  main->setMode(FMOD_LOOP_OFF);
  shot->setMode(FMOD_LOOP_OFF);
}

Sounds::~Sounds() {
  this->boost->release();
  this->change->release();
  this->death->release();
  this->jump->release();
  this->ladder->release();
  this->main->release();
  this->menu->release();
  this->shot->release();
  this->system->release();
  this->system->close();
}

void Sounds::play(std::string name) {
  if (name == "boost") {
    system->playSound(this->boost, 0, false, &this->channel);
  }
  else if (name == "change") {
    system->playSound(this->change, 0, false, &this->channel);
  }
  else if (name == "death") {
    system->playSound(this->death, 0, false, &this->channel);
  }
  else if (name == "jump") {
    system->playSound(this->jump, 0, false, &this->channel);
  }
  else if (name == "ladder") {
    system->playSound(this->ladder, 0, false, &this->channel);
  }
  else if (name == "main") {
    system->playSound(this->main, 0, false, &this->channel);
  }
  else if (name == "shot") {
    system->playSound(this->shot, 0, false, &this->channel);
  }
  else if (name == "change") {
    system->playSound(this->change, 0, false, &this->channel);
  }
  else if (name == "menu") {
    system->playSound(this->menu, 0, false, &this->channel);
  }
  else {
    return;
  }
}

void Sounds::update() {
  this->system->update();
}