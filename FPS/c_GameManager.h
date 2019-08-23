#pragma once

struct CharacterData
{
	float	fMoveSpeed;
	float	fBombTime;
	int		nBombPower;
	int		nBombCount;

	CharacterData();
};

struct Explosion
{
	int x;
	int y;
	int pow;

	Explosion(int _x, int _y, int _pow) : x(_x), y(_y), pow(_pow)
	{}
};

struct CreateObj
{
	int x;
	int y;
	eObjectType type;

	CreateObj(int _x, int _y, eObjectType _type) : x(_x), y(_y), type(_type)
	{}
};

class c_GameManager
{
#pragma region SINGLE_TON
private:
	static inline c_GameManager* m_pInstance = nullptr;
	c_GameManager();
	~c_GameManager();

	c_GameManager operator=(c_GameManager&) = delete; // 연산자 오버로딩 막기
	c_GameManager(c_GameManager&&) = delete; // 이동막기
	c_GameManager(const c_GameManager&) = delete; // 참조막기?

public:

	static void CreateInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new c_GameManager();
			m_pInstance->Init();
		}
	}

	static c_GameManager* GetInstance()
	{
		return m_pInstance;
	}

	static void ReleaseInstance()
	{
		m_pInstance->Release();
		SAFE_DELETE(m_pInstance);
	}

#pragma endregion

public:
	enum
	{
		MaxLife = 3,
		RoundTime = 90,

		MoveSpeed = 10,
		BombTime = 2,
		BombBasePower = 2,
		BombBaseCount = 1,
	};

	enum class eGameState
	{
		None,

		Run,
		End,
	};

	void Init();
	void Release();

	void GameInit();
	void StageStart();
	void StageEnd();

	void Update(float a_fDeltaTime);
	void Render();
	void PostRender();

	void ClearObject();
	class c_Object* CreateObject(eObjectType a_eObjType, int x, int y);

	// 상호작용
	void RemoveObject(class c_Object* a_pObj);
	void DropItem(class c_Object* a_pObj);
	void GetBombData(OUT class c_Bomb* a_refBomb) const;
	void ObtainItem(eItem a_eItem);
	void Die(class c_Object* a_refObj);

	class c_Object* AddBomb(int a_nPlayerX, int a_nPlayerY);
	void ResistExplosion(c_Object* a_refBomb, int x, int y, int pow);
	bool MoveCheck(class c_Object* a_pMoveIgnoreObject = nullptr);
	void CheckExplosion(c_Object* a_refExplosion);
	void AddScore(int a_nScore);
	//void AddBomb(int a_nPlayerX, int a_nPlayerY);

private:

	void CreateExplosionRecursive(eDir a_eDir, int nBombX, int nBombY, int a_nRemainPower);
	bool FindObject_withPosition(eObjectType a_eObj, int x, int y);

private:
	// 오브젝트
	std::array<std::vector<class c_Object*>, (int)eObjectType::RenderDepthCount> m_arrObj;
	class c_Player* m_pPlayer = nullptr;

	// 스테이지 정보
	int m_nNowStage = 0;
	//남은시간
	float m_fGameTime = 0;
	class c_MapData* m_refMap = nullptr;
	char** m_pMap = nullptr; // ??

	//데이터
	int m_nNowLife = 0;
	int m_nScore = 0;

	std::vector<class c_Object*> m_vcDelete;

	std::vector<CreateObj> m_vcCreate;

	// 폭발
	std::vector<Explosion>m_vcExplosion;

	// 현재 플레이어 데이터
	CharacterData m_stPlayerData;

	eGameState m_eState = eGameState::None;

public:
	std::string m_sLog = "";

};

#define InitGameMng()		{c_GameManager::CreateInstance();}
#define GameMng()			(c_GameManager::GetInstance())
#define ReleaseGameMng()	(c_GameManager::ReleaseInstance())

