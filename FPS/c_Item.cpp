#include "pch.h"
#include "c_Item.h"

#include "c_GameManager.h"

c_Item::c_Item(int x, int y) : c_Object(x, y),

m_Item{
	{
			{ ' ', ' ', ' ', ' ', ' ' },
			{ '|', 'P', 'P', ' ', '|' },
			{ '|', 'P', 'P', ' ', '|' },
			{ '|', 'P', ' ', ' ', '|' },
			{ ' ', ' ', ' ', ' ', ' ' },
	},

	{
			{ ' ', ' ', ' ', ' ', ' ' },
			{ '|', 'C', 'C', 'C', '|' },
			{ '|', 'C', ' ', ' ', '|' },
			{ '|', 'C', 'C', 'C', '|' },
			{ ' ', ' ', ' ', ' ', ' ' },
	},

	{
			{ ' ', ' ', ' ', ' ', ' ' },
			{ '|', ' ', 'S', ' ', '|' },
			{ '|', 'S', 'S', 'S', '|' },
			{ '|', ' ', 'S', ' ', '|' },
			{ ' ', ' ', ' ', ' ', ' ' },
	},
}
{
	int nNum = (rand() % (int)eItem::Max);
	m_eType = (eItem)nNum;

	m_pNowAni = &m_Item[nNum];
}

c_Item::~c_Item(){}

eObjectType c_Item::GetObjectType() const
{
	return eObjectType::Item;
}

void c_Item::Interaction(class c_Hero* a_refHero)
{
	GameMng()->RemoveObject(this);
	GameMng()->ObtainItem(m_eType);
}