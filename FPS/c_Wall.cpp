#include "pch.h"
#include "c_Wall.h"


c_Wall::c_Wall(int x, int y) : c_Object(x, y)
, m_Data{
		{ '1', '1', '1', '1', '1' },
		{ '1', 'M', 'M', 'M', '1' },
		{ '1', 'M', ' ', 'M', '1' },
		{ '1', 'M', 'M', 'M', '1' },
		{ '1', '1', '1', '1', '1' } }
{
	m_pNowAni = &m_Data;
}


c_Wall::~c_Wall()
{
}

eObjectType c_Wall::GetObjectType() const
{
	return eObjectType::Wall;
}
