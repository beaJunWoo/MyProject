#pragma once
#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

#define BufferWidth 150
#define BufferHeight 150
#define PlayerBulletCount 50

enum SceneId
{
	EXIT,
	MENU,
	LOGO,
	STAGE,
	RANKING
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

enum BlockType {
	L,
	Z,
	E,
	I,
	T,
};

