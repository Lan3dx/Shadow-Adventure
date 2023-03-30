#pragma once

// system's libs
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <WinUser.h>
#include <stdlib.h>
#include <thread>
#include <string>
#include <filesystem>
#include <mmsystem.h>

// user's libs
#include "config.h"
#include "logger.h"
#include "musicloader.h"
#include "../map.h"
#include "../control.h"
#include "../gravity.h"
#include "../corners.h"
#include "../elistener.h"
#include "../entities/sys/dlistener.h"
#include "../entities/player.h"
#include "../entities/bullet.h"
#include "../entities/mob.h"
#include "../entities/sys/render.h"
#include "../entities/sys/cooldowns_s.h"
#include "../entities/sys/change.h"
#include "../sys/audiomgr.h"

// third-party libs
#include <fmod.hpp>