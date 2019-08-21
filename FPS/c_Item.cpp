#include "pch.h"
#include "c_Item.h"

#include "c_GameManager.h"

c_Item::c_Item(int x, int y) : c_Object(x, y)
{
}


c_Item::~c_Item()
{
}

eObjectType c_Item::GetObjectType() const
{
	return eObjectType::Item;
}

void c_Item::Interaction(class c_Hero* a_refHero)
{
	GameMng()->RemoveObject(this);
	GameMng()->ObtainItem(m_eType);
}