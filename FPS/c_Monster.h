#include "c_Object.h"

class c_Monster:public c_Object
{
public:

	enum { MonsterScore = 100, };

	c_Monster(int x, int y);
	virtual ~c_Monster();

	// Object를 통해 상속됨
	virtual eObjectType GetObjectType() const override;
	virtual bool CanMove() const override;
	virtual bool Interaction(class c_Player* a_refHero) override;
	virtual bool Explosived() override;

	int m_nLife = 1;
	RenderTile m_Data;
};

