#include "c_Object.h"

class c_Monster:public c_Object
{
public:
	c_Monster(int x, int y);
	virtual ~c_Monster();

	// Object�� ���� ��ӵ�
	virtual eObjectType GetObjectType() const override;
	RenderTile m_Data;
};

