#include "../../include/sys/audiomgr.h"

void playSound(const char* filePath) {
  FMOD::System* system;
  FMOD_RESULT result = FMOD::System_Create(&system);
  if (result != FMOD_OK) {
    return;
  }

  result = system->init(32, FMOD_INIT_NORMAL, 0);
  if (result != FMOD_OK) {
    system->release();
    return;
  }

  FMOD::Sound* sound;
  result = system->createSound(filePath, FMOD_DEFAULT, 0, &sound);
  if (result != FMOD_OK) {
    system->release();
    return;
  }

  FMOD::Channel* channel;
  result = system->playSound(sound, 0, false, &channel);
  if (result != FMOD_OK) {
    system->release();
    return;
  }

  channel->setCallback([](FMOD_CHANNELCONTROL* chan, FMOD_CHANNELCONTROL_TYPE type, FMOD_CHANNELCONTROL_CALLBACK_TYPE callbackType, void* commandData1, void* commandData2) {
    FMOD::Sound* sound;
  FMOD::Channel* channel = (FMOD::Channel*)chan;
  channel->getCurrentSound(&sound);
  sound->release();
  return FMOD_OK;
    });

  while (true) {
    system->update();
    bool isPlaying;
    channel->isPlaying(&isPlaying);
    if (!isPlaying) {
      break;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  system->close();
  system->release();
}