#pragma once
#include "c_Object.h"

class c_Player : public c_Object
{
public:
	c_Player(int x, int y);
	virtual ~c_Player();

	virtual eObjectType GetObjectType() const override;

	virtual void Render() override;

	RenderTile m_Data;
};

