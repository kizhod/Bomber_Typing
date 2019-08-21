#include "pch.h"
#include "c_Monster.h"


c_Monster::c_Monster(int x, int y) : c_Object(x, y)
, m_Data{
		{ '1', '1', '1', '1', '1' },
		{ '1', 'M', 'M', 'M', '1' },
		{ '1', 'M', ' ', 'M', '1' },
		{ '1', 'M', 'M', 'M', '1' },
		{ '1', '1', '1', '1', '1' }
}
{
	m_pNowAni = &m_Data;
}

c_Monster::~c_Monster()
{
}

eObjectType c_Monster::GetObjectType() const
{
	return eObjectType::Monster;
}

