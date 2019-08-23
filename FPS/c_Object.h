#pragma once

class c_Object
{
public:
	c_Object(int _x, int _y);
	virtual ~c_Object(); // 소멸자가 왜 버추얼?
	virtual eObjectType GetObjectType() const = 0;
	virtual bool CanMove() const;

	bool Update(float a_fDelta);
	void Render();
	void SetMap(char** a_refMap);
	void RenderClear();

	virtual void Init();
	virtual bool Explosived();
	virtual bool Interaction(class c_Player* a_refHero);

	inline void SetPos(int _x, int _y) { x = _x; y = _y; }
	inline bool IsCross(const c_Object& a_refObj) const
	{
		return rt.IsCross(a_refObj.rt);
	}
	inline bool IsCross(c_Object* a_refObj) const
	{
		assert((a_refObj != nullptr) && "arg error");
		return IsCross(*a_refObj);
	}

	virtual Rect GetRenderRect() const;

protected:
	virtual void _PreUpdate(float a_fDelta); // 이전단계의 글자 지우기
	virtual bool _Update(float a_fDelta);

public:
	int x;
	int y;
	Rect rt;

protected:

	static RenderTile Empty;
	char** m_refMap = nullptr;
	RenderTile* m_pNowAni = nullptr;
};

