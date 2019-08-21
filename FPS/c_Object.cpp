#include "pch.h"
#include "c_Object.h"

c_Object::c_Object(int _x, int _y) : x(_x), y(_y) { }
c_Object::~c_Object(){}

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

void c_Object::Update(float a_fDelta)
{
	_PreUpdate(a_fDelta);
	_Update(a_fDelta);
}

void c_Object::Render()
{
	int nX = x * TileSize;
	int nY = y * TileSize;

	for (int i = 0; i < TileSize; ++i)
	{
		char* pDest = m_refMap[nY + i];

		memcpy_s((pDest + nX), TileSize * sizeof(char),
			(*m_pNowAni)[i], TileSize * sizeof(char));
	}
}
