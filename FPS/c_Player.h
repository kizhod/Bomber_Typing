#pragma once
#include "c_Object.h"

class c_Player : public c_Object
{
public:
	c_Player(int x, int y);
	virtual ~c_Player();

	// Object를 통해 상속됨
	virtual eObjectType GetObjectType() const override;

	virtual Rect GetRenderRect() const override;
	void SetStat(struct CharacterData* a_pStat);
	void ResetBomb(c_Object* a_refBomb);
	virtual bool Explosived() override;

private:
	void Move(float a_fDeltaTime);
	void BombCheck();

protected:

	virtual void _PreUpdate(float a_fDelta) override;
	virtual bool _Update(float a_fDelta) override;

	RenderTile m_Data;
	struct CharacterData* m_refStat;

	int m_nPutBombCount = 0;
	c_Object* m_refBomb = nullptr;
};

