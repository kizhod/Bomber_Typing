#include "pch.h"
#include "c_Item.h"

#include "c_GameManager.h"
#include "c_Ani.h"

#include "c_Player.h"

c_Item::c_Item(int x, int y) : c_Object(x, y), m_pAni(new c_Ani())
{
	int nNum = (rand() % (int)eItem::Max);
	m_eType = (eItem)nNum;

	m_pAni->Resize((int)eItem::Max);
	m_pAni->Add((int)eItem::PowerUp,
		{
		   {{"     "},
			{"|   |"},
			{"| P |"},
			{"|   |"},
			{"     "}},

		   {{"     "},
			{"| P |"},
			{"|   |"},
			{"|   |"},
			{"     "}},

		   {{"     "},
			{"|   |"},
			{"|   |"},
			{"| P |"},
			{"     "}},
		}
	);

	m_pAni->Add((int)eItem::SpeedUp,
		{
		   {{"     "},
			{"|   |"},
			{"| S |"},
			{"|   |"},
			{"     "}},

		   {{"     "},
			{"| S |"},
			{"|   |"},
			{"|   |"},
			{"     "}},

		   {{"     "},
			{"|   |"},
			{"|   |"},
			{"| S |"},
			{"     "}},
		}
	);

	m_pAni->Add((int)eItem::BombCount,
		{
		   {{"     "},
			{"|   |"},
			{"|B-C|"},
			{"|   |"},
			{"     "}},

		   {{"     "},
			{"|B-C|"},
			{"|   |"},
			{"|   |"},
			{"     "}},

		   {{"     "},
			{"|   |"},
			{"|   |"},
			{"|B-C|"},
			{"     "}},
		}
	);

	m_pAni->SetState((int)m_eType);
	m_pNowAni = m_pAni->Get;
}

c_Item::~c_Item()
{
	SAFE_DELETE(m_pAni)
}

eObjectType c_Item::GetObjectType() const
{
	return eObjectType::Item;
}

bool c_Item::Interaction(class c_Player* a_refHero)
{
	if (IsCross(a_refHero) == true)
	{
		GameMng()->ObtainItem(m_eType);
		return true;
	}
	return false;
	//GameMng()->RemoveObject(this);
}

bool c_Item::CanMove() const
{
	return true;
}

void c_Item::_PreUpdate(float a_fDelta)
{
	RenderClear();
}

bool c_Item::_Update(float a_fDelta)
{
	m_pAni->Update(a_fDelta);
	m_pNowAni = m_pAni->Get();

	return false;
}