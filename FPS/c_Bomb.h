#pragma once
#include "c_Object.h"

class c_Bomb : public c_Object
{
public:
	c_Bomb(int x, int y);
	virtual ~c_Bomb();

	// Object를 통해 상속됨
	virtual eObjectType GetObjectType() const override;

	void Init() override;
	void _Update(float a_fDelta) override;
	void Explosived(class c_Bomb* a_refBomb) override;

	float		m_fLifeTime = 2.0f;
	int			m_nExplosiveRange = 2;
	RenderTile	m_Data;
};

