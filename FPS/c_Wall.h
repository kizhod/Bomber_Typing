#pragma once
#include "c_Object.h"

class c_Wall : public c_Object
{
public:
	c_Wall(int x, int y);
	virtual ~c_Wall();

	// Object�� ���� ��ӵ�
	virtual eObjectType GetObjectType() const override;
	RenderTile m_Data;
};

