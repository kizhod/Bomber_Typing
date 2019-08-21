#pragma once
#include "c_Object.h"

class c_Door : public Object
{
public:
	enum class eDoorState
	{
		Close,
		Open,
	};

	c_Door(int x, int y);
	virtual ~c_Door();

	virtual eObjectType GetObjectType() const override;

	virtual void Init() override;
	virtual void Interaction(class c_Hero* a_refHero) override;

	eDoorState m_eState = eDoorState::Close;

};

