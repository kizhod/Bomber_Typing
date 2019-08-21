#pragma once

class c_Object
{
public:
	c_Object(int _x, int _y);
	virtual ~c_Object(); // �Ҹ��ڰ� �� ���߾�?
	virtual eObjectType GetObjectType() const = 0;

	virtual void Init();
	virtual void Update(float a_fDelta);
	virtual void Render();
	virtual void Explosived(class c_Bomb* a_refBomb);
	virtual void Interaction(class c_Hero* a_refHero);

	inline void SetPos(int _x, int _y) { x = _x; y = _y; }
	inline void SetMap(char** a_refMap)
	{ assert(a_refMap != nullptr); m_refMap = a_refMap; }

public:
	int x;
	int y;

protected:

	char** m_refMap = nullptr;
	RenderTile* m_pNowAni = nullptr;
};

