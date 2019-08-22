#pragma once

using std::cout;
using std::endl;

enum class eUpdateState
{
	Run,
	Final,
};

enum class eKey
{
	None = -1,

	A,
	Left,
	W,
	Up,
	S,
	Right,
	D,
	Down,
	SPACE,
	Fire,

	Max,
};

enum class eInputState : short // : short?
{
	None	= 0b00,
	Down	= 0b11,
	Press	= 0b01,
	Up		= 0b10,
};

enum class eScene
{
	Intro,
	Game,
	GameOver,

	Scene_First = Intro,
};

enum class eObjectType
{
	None = 0,
	RenderDepthGap = 1000,

	RenderDepthGap1 = RenderDepthGap * 1,
	RenderDepthGap2 = RenderDepthGap * 2,
	RenderDepthGap3 = RenderDepthGap * 3,
	RenderDepthCount= 3,

	Wall = RenderDepthGap1 + 1,
	Box,
	Door,

	Item = RenderDepthGap2 + 1,
	Bomb,

	Player = RenderDepthGap3 +1,
	Monster,
};

enum eItem
{
	None = 1,

PowerUp,
BombCount,
SpeedUp,

Max,
};


enum eGame
{
	MaxStage = 3,
	TileSize = 5,
};

#define SAFE_DELETE(x) {if((x) != nullptr){delete(x); (x)=nullptr;}}
#define SAFE_DELETE_ARR(x) {if((x) != nullptr){delete(x); (x)=nullptr;}}

#include "c_SceneManager.h"
inline bool IsKeyDown(eKey a_eKey) { return c_SceneManager::GetKeyState(a_eKey) == eInputState::Down; }
inline bool IsKeyUp(eKey a_eKey) { return c_SceneManager::GetKeyState(a_eKey) == eInputState::Up; }

//using RenderTile = char[TileSize][TileSize];

enum class CURSOR_TYPE { NOCURSOR, SOLIDCURSOR, NORMALCURSOR };

void SetCursor(const COORD& a_stPos);
void SetCursor(int a_nPosX, int a_nPosY);
void SetCursorType(CURSOR_TYPE c);
void SetConsoleSize(int a_nWidth, int a_nHeight, int a_nX = 200, int a_nY = 200);

struct RenderLine
{
	RenderLine() = default;
	RenderLine(std::initializer_list<char> a)
	{
		assert(a.size() <= TileSize);

		int nIndex = 0;
		for (auto& _c : a)
		{
			c[nIndex++] = _c;
		}
		c[TileSize] = 0;
	}

	RenderLine(const char* s)
	{
		size_t nLen = strlen(s);
		assert(nLen <= TileSize);

		strcpy_s(c, sizeof(char)*(TileSize + 1), s);
	}

	operator const char*() const
	{
		return c;
	}

	char c[TileSize + 1];
};


struct RenderTile
{
	RenderTile() = default;
	RenderTile(std::initializer_list<RenderLine> a)
	{
		assert(a.size() <= TileSize);

		int nIndex = 0;
		for (auto& _c : a)
		{
			l[nIndex++] = _c;
		}
	}

	RenderLine& operator[](int a_nIndex)
	{
		assert(a_nIndex >= 0 && a_nIndex <= TileSize);
		return l[a_nIndex];
	}

	RenderLine l[TileSize];
};


struct Rect
{
	float x;
	float y;
	float w;
	float h;

	bool IsCross(const Rect& rt)
	{
		if ((x >= rt.x + rt.w)) ||
			(x + w <= rt.x) ||
			(y >= rt.y + h) ||
			(y + h <= rt.y))
		{
		return false;
		}

		return true;
	}

	bool IsIn(int _x, int _y)
	{
		if ((x <= _x) && (_x <= x + w) &&
			(y <= _y) && (_y <= y + h))
		{
			return true;
		}

		return false;
	}

	COORD Center()
	{
		return COORD{ (short)(x + w / 2), (short)(y + h / 2) };
	}

};