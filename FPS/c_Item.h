#pragma once
#include "c_Object.h"

class c_Item : public c_Object
{
public:
	c_Item(int x, int y);
	virtual ~c_Item();

	virtual eObjectType GetObjectType() const override;
	virtual void Render() override;
	virtual void Interaction(class c_Hero* a_refHero) override;

	eItem m_eType = eItem::None;
	RenderTile m_Item[(int)eItem::Max];
};

