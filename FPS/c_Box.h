#pragma once

#include "c_Object.h"

class c_Box : public c_Object
{
public:
	c_Box(int x, int y);
	virtual ~c_Box();

	// Object를 통해 상속됨
	virtual eObjectType GetObjectType() const override;
	virtual bool Explosived() override;

	RenderTile m_Data;
};

