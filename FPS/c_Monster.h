#include "c_Object.h"

class c_Monster:public c_Object
{
public:
	c_Monster(int x, int y);
	virtual ~c_Monster();

	// Object를 통해 상속됨
	virtual eObjectType GetObjectType() const override;
	RenderTile m_Data;
};

