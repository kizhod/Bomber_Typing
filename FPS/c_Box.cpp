#include "pch.h"
#include "c_Box.h"

#include "c_GameManager.h"

c_Box::c_Box(int x, int y) : c_Object(x, y)
, m_Data{
		{ '1', '1', '1', '1', '1' },
		{ '1', ' ', ' ', ' ', '1' },
		{ '1', ' ', ' ', ' ', '1' },
		{ '1', ' ', ' ', ' ', '1' },
		{ '1', '1', '1', '1', '1' },
} {m_pNowAni = &m_Data; }

c_Box::~c_Box(){}

eObjectType c_Box::GetObjectType() const
{
	return eObjectType::Box;
}

void c_Box::Explosived(c_Bomb* a_refBomb)
{
	GameMng()->RemoveObject(this);
	GameMng()->DropItem(this);
}
