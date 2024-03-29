#pragma once
#include "c_Object.h"

class c_Item : public c_Object
{
public:
	c_Item(int x, int y);
	virtual ~c_Item();

	// Object�� ���� ��ӵ�
	virtual eObjectType GetObjectType() const override;
	virtual bool Interaction(class c_Player* a_refHero) override;
	
	virtual bool CanMove() const override;
	
	virtual void _PreUpdate(float a_fDelta) override;
	virtual bool _Update(float a_fDelta) override;

	eItem m_eType = eItem::None;
	class c_Ani* m_pAni = nullptr;
};

