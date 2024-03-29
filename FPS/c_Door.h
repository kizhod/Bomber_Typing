#pragma once
#include "c_Object.h"

class c_Door : public c_Object
{
public:
	enum class eDoorState
	{
		Close,
		Open,
	};

	c_Door(int x, int y);
	virtual ~c_Door();

	// Object�� ���� ��ӵ�
	virtual eObjectType GetObjectType() const override;
	virtual bool CanMove() const override;

	virtual void Init() override;
	virtual bool Interaction(class c_Player* a_refHero) override;

	eDoorState m_eState = eDoorState::Close;

	RenderTile m_Close;
	RenderTile m_Open;

};

