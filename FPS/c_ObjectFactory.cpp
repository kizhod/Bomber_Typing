#include "pch.h"
#include "c_ObjectFactory.h"

#include "c_Wall.h"
#include "c_Box.h"
#include "c_Door.h"
#include "c_Item.h"
#include "c_Bomb.h"
#include "c_Monster.h"
#include "c_Player.h"

c_Object* c_ObjectFactory::Make(eObjectType a_eType, int x, int y)
{
	c_Object* pReturn = nullptr;
	switch (a_eType)
	{
	case eObjectType::Wall:		{pReturn = new c_Wall(x, y);} break;
	case eObjectType::Box:		{pReturn = new c_Box(x, y);} break;
	case eObjectType::Door:		{pReturn = new c_Door(x, y);} break;
	case eObjectType::Item:		{pReturn = new c_Item(x, y);} break;
	case eObjectType::Bomb:		{pReturn = new c_Bomb(x, y);} break;
	case eObjectType::Monster:	{pReturn = new c_Monster(x, y);} break;
	case eObjectType::Player:	{pReturn = new c_Player(x, y);} break;
	}

	assert(pReturn != nullptr);
	return pReturn;
}