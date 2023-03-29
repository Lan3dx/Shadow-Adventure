#pragma once
#include "includes.h"
#include "fmod.hpp"

class Sounds {
public:
  FMOD::System* system;
  FMOD::Channel* channel;
  FMOD::Sound* death, * jump, * main, * shot, * boost, * ladder, * change, * menu;

public:
  Sounds();
  ~Sounds();
  void update();
  void play(std::string);
};