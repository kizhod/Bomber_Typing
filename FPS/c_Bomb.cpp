#include "pch.h"
#include "c_Bomb.h"

#include "c_GameManager.h"

c_Bomb::c_Bomb(int x, int y) : c_Object(x,y)
, m_Data{
		{ '1', '1', '1', '1', '1' },
		{ '1', 'B', 'B', 'B', '1' },
		{ '1', 'B', 'B', 'B', '1' },
		{ '1', 'B', 'B', 'B', '1' },
		{ '1', '1', '1', '1', '1' },
}
{
	m_pNowAni = &m_Data;
}

c_Bomb::~c_Bomb(){}

eObjectType c_Bomb::GetObjectType() const
{
	return eObjectType::Bomb;
}

void c_Bomb::Init()
{
	GameMng()->GetBombData(this);
}

void c_Bomb::_Update(float a_fDelta)
{
	m_fLifeTime -= a_fDelta;

	if (m_fLifeTime <= 0.0f)
	{
		// Bomb!
	}
}

void c_Bomb :: Explosived(c_Bomb* a_refBomb)
{
	if (a_refBomb == this) { return; }

	// Bomb!
}
