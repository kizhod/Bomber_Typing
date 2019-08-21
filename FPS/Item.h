#pragma once
#include "Object.h"

class Item : public Object
{
public:
	Item(int x, int y);
	virtual ~Item();

	// Object��(��) ���� ��ӵ�
	virtual eObjectType GetObjectType() const override;

	virtual void Interaction(class Hero* a_refHero) override;

	eItem m_eType = eItem::None;
};

