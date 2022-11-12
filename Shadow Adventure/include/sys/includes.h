#pragma once

// system's libs
#include <vector>
#include <map>
#include <iostream>
#include <windows.h>
#include <WinUser.h>
#include <thread>
#include <string>
#include <mmsystem.h>

// user's libs
#include "config.h"
#include "render.h"
#include "../map.h"
#include "../control.h"
#include "../gravity.h"
#include "../elistener.h"
#include "../entities/player.h"
#include "../entities/bullet.h"
#include "../entities/mob.h"
#include "../spawn.h"
#include "musicloader.h"
#include "../entities/sys/cooldowns_s.h"
#include "../entities/sys/change.h"