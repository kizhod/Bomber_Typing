#include "pch.h"
#include "c_Object.h"

RenderTile c_Object::Empty = RenderTile{
	{"     "},
	{"     "},
	{"     "},
	{"     "},
	{"     "},
};

c_Object::c_Object(int _x, int _y) : x(_x), y(_y) { }
{
	rt.x = (float)(_x * TileSize);
	rt.y = (float)(_x * TileSize);
	rt.w = TileSize;
	rt.h = TileSize;
}

c_Object::~c_Object()
{
	m_pNowAni = nullptr;
	m_refMap = nullptr;
}

void c_Object::Init() { }

void c_Object::Explosived(class c_Bomb* a_refBomb) { }
void c_Object::Interaction(class c_Hero* a_refHero) { }
void c_Object::_PreUpdate(float a_fDelta){}
void c_Object::_Update(float a_fDelta){}

void c_Object::SetMap(char** a_refMap)
{
	assert(a_refMap != nullptr);
	m_refMap = a_refMap;
}

bool c_Object::Update(float a_fDelta)
{
	_PreUpdate(a_fDelta);
	_Update(a_fDelta);
}

Rect c_Object::GetRenderRect() const
{
	return rt;
}

void c_Object::RenderClear()
{
	Rect rt = GetRenderRect();
	int nX = (int)rt.x;
	int nY = (int)rt.y;

	for (int i = 0; i < TileSize; ++i)
	{
		char* pDest = m_refMap[nY + i];

		memcpy_s((pDest + nX), TileSize * sizeof(char),
			Empty[i], TileSize * sizeof(char));
	}
}

void c_Object::Render()
{
	Rect rt = GetRenderRect();
	int nX = (int)rt.x;
	int nY = (int)rt.y;

	for (int i = 0; i < TileSize; ++i)
	{
		char* pDest = m_refMap[nY + i];

		memcpy_s((pDest + nX), TileSize * sizeof(char),
			(*m_pNowAni)[i], TileSize * sizeof(char));
	}
}