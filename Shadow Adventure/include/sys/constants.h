#pragma once
#include <string>

static int MAX_AMMO = 3; // max player bullet
static int MAX_PLAYERS = 3; // max players
static int SHOT_CD = 20; // cooldown for shot
static int KEY_CD = 20; // cooldown for any key
static int FPS_CD = 40; // cooldown for frame per second
static int JUMP_HEIGHT = 3; // player jump height
static int PLAYER_DMG = 5; // default player damage
static int MOB_DMG = 1; // default mob damage
struct block { char character; int durability; int color; }; // user's type point
struct Corners { int left; int up; };
struct PlayerFrame { int x; int y; int length; bool ischanged; };
struct animation { int X; int Y; int LT; std::string Text; int counter; };