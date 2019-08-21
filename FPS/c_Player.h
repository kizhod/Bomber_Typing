#pragma once
#include "c_Object.h"

class c_Player : public c_Object
{
public:
	c_Player(int x, int y);
	virtual ~c_Player();

	// Object를 통해 상속됨
	virtual eObjectType GetObjectType() const override;
	RenderTile m_Data;
};

