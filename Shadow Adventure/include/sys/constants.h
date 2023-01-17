#pragma once

static int8_t MAX_AMMO = 3; // max player bullet
static int8_t MAX_PLAYERS = 3; // max players
static int SHOT_CD = 10; // cooldown for shot
static int KEY_CD = 20; // cooldown for any key
static int FPS_CD = 40; // cooldown for frame per second
static int JUMP_HEIGHT = 3; // player jump height
struct block { char character; int durability; int color; }; // user's type point