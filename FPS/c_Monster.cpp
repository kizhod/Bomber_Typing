#include "pch.h"
#include "c_Monster.h"

#include "c_Player.h"
#include "c_GameManager.h"


c_Monster::c_Monster(int x, int y) : c_Object(x, y)
, m_Data{
		{ '1', '1', '1', '1', '1' },
		{ '1', 'M', 'M', 'M', '1' },
		{ '1', 'M', 'M', 'M', '1' },
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

bool c_Monster::CanMove() const
{
	return true;
}

bool c_Monster::Interaction(c_Player* a_refHero)
{
	if (IsCross(a_refHero) == true)
	{
		GameMng()->Die(this);
	}

	return false;
}

bool c_Monster::Explosived()
{
	--m_nLife;
	if (m_nLife <= 0)
	{
		GameMng()->AddScore(MonsterScore);
		return true;
	}

	return false;
}

