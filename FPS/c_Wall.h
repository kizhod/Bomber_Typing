#pragma once
#include "c_Object.h"

class c_Wall : public c_Object
{
public:
	c_Wall(int x, int y);
	virtual ~c_Wall();

	// Object를 통해 상속됨
	virtual eObjectType GetObjectType() const override;
	RenderTile m_Data;
};

