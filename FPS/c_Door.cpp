#include "pch.h"
#include "c_Door.h"

#include "c_GameManager.h"

c_Door::c_Door(int x, int y) : c_Object(x, y)
{
}

c_Door::~c_Door()
{
}

eObjectType c_Door::GetObjectType() const
{
	return eObjectType::Door;
}

void c_Door::Init()
{
	m_eState = eDoorState::Close;
}

void c_Door::Interaction(class c_Hero* a_refHero)
{
	if (m_eState == eDoorState::Close) { return; }
	GameMng()->StageStart();
}