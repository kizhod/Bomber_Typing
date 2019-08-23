#pragma once
#include "c_Object.h"

class c_Bomb : public c_Object
{
public:
	c_Bomb(int x, int y);
	virtual ~c_Bomb();

	// Object를 통해 상속됨
	virtual eObjectType GetObjectType() const override;

	virtual void Init() override;
	virtual bool _Update(float a_fDelta) override;
	virtual bool Explosived() override;

	float		m_fLifeTime = 2.0f;
	int			m_nExplosiveRange = 2;
	
	class c_Ani* m_pAni = nullptr;
};

