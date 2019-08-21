#pragma once
#include "c_Object.h"

class c_Wall : public c_Object
{
public:
	c_Wall(int x, int y);
	virtual ~c_Wall();

	virtual eObjectType GetObjectType() const override;

	virtual void Render() override;

	RenderTile m_Data;
};

