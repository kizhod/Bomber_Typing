#include "pch.h"
#include "c_Player.h"


c_Player::c_Player(int x, int y) : c_Object(x, y)
, m_Data{
		{ 'P', 'P', 'P', 'P', 'P' },
		{ 'P', ' ', ' ', ' ', 'P' },
		{ 'P', ' ', ' ', ' ', 'P' },
		{ 'P', ' ', ' ', ' ', 'P' },
		{ 'P', 'P', 'P', 'P', 'P' } }
{
	m_pNowAni = &m_Data;
}

c_Player::~c_Player()
{
}

eObjectType c_Player::GetObjectType() const
{
	return eObjectType::Player;
}

void c_Player::Render()
{

}

