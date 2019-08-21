#pragma once

class c_Object
{
public:
	c_Object(int _x, int _y);
	virtual ~c_Object(); // 소멸자가 왜 버추얼?
	virtual eObjectType GetObjectType() const = 0;

	void Update(float a_fDelta);
	void Render();
	void SetMap(char** a_refMap);

	virtual void Init();
	virtual void Explosived(class c_Bomb* a_refBomb);
	virtual void Interaction(class c_Hero* a_refHero);

	inline void SetPos(int _x, int _y) { x = _x; y = _y; }

protected:
	virtual void _PreUpdate(float a_fDelta); // 이전단계의 글자 지우기
	virtual void _Update(float a_fDelta);

public:
	int x;
	int y;

protected:

	char** m_refMap = nullptr;
	RenderTile* m_pNowAni = nullptr;
};

