#pragma once
#include "c_Object.h"

class c_Item : public c_Object
{
public:
	c_Item(int x, int y);
	virtual ~c_Item();

	// Object를 통해 상속됨
	virtual eObjectType GetObjectType() const override;
	virtual void Interaction(class c_Hero* a_refHero) override;

	virtual void _PreUpdate(float a_fDelta) override;
	virtual void _Update(float a_fDelta) override;

	eItem m_eType = eItem::None;
	class c_Ani* m_pAni = nullptr;
};

