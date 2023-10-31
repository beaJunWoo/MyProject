#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

#define BufferWidth 80
#define BufferHeight 100
#define PlayerBulletCount 50

enum SceneId
{
	MENU,
	LOGO,
	STAGE,
};

enum Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE,

};

enum Dir
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};