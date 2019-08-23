#pragma once
#include "c_Object.h"

class c_Explosion : public c_Object
{
public:
	c_Explosion(int x, int y);
	virtual ~c_Explosion();

	// Object을(를) 통해 상속됨
	virtual eObjectType GetObjectType() const override;
	virtual bool CanMove() const override;

	virtual void _PreUpdate(float a_fDelta) override;
	virtual bool _Update(float a_fDelta) override;

	float		m_fLife = 2.0f;
	class c_Ani* m_pAni = nullptr;

};