#include "pch.h"
#include "c_Door.h"

#include "c_GameManager.h"
#include "c_Player.h"

c_Door::c_Door(int x, int y) : c_Object(x, y)
, m_Close{
			{ 'X', '-', '-', '-', 'X' },
			{ '|', 'X', ' ', 'X', '|' },
			{ '|', ' ', 'X', ' ', '|' },
			{ '|', 'X', ' ', 'X', '|' },
			{ 'X', '-', '-', '-', 'X' },
}
, m_Open{
			{ ' ', 'D', 'D', 'D', ' ' },
			{ 'D', ' ', ' ', ' ', 'D' },
			{ 'D', ' ', ' ', ' ', 'D' },
			{ 'D', ' ', ' ', ' ', 'D' },
			{ ' ', 'D', 'D', 'D', ' ' },
} {
	m_pNowAni = &m_Close;
}

c_Door::~c_Door()
{
}

eObjectType c_Door::GetObjectType() const
{
	return eObjectType::Door;
}

bool c_Door::CanMove() const
{
	return (m_eState == eDoorState::Open);
}

void c_Door::Init()
{
	m_eState = eDoorState::Close;
}

bool c_Door::Interaction(class c_Player* a_refHero)
{
	if (m_eState == eDoorState::Close) { return; }

	if (IsCross(a_refHero) == true)
	{
		GameMng()->StageStart();
	}

	return false;
}