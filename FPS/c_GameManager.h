#pragma once

struct CharacterData
{
	float	fMoveSpeed;
	float	fBombTime;
	int		nBombPower;
	int		nBombCount;

	CharacterData();
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

	void Init();
	void Release();

	void GameInit();
	void StageStart();

	void Update(float a_fDeltaTime);
	void Render();

	void ClearObject();

	// 상호작용
	void RemoveObject(class c_Object* a_pObj);
	void DropItem(class c_Object* a_pObj);
	void GetBombData(class c_Bomb* a_refBomb) const;
	void ObtainItem(eItem a_eItem);

private:
	// 오브젝트
	std::vector<class Object*> m_vcObj[(int)eObjectType::LevelMax];
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

	// 폭발
	std::queue<class c_Bomb*> m_qBomb;

	// 현재 플레이어 데이터
	CharacterData m_stPlayerData;

};

#define InitGameMng()		{c_GameManager::CreateInstance();}
#define GameMng()			(c_GameManager::GetInstance())
#define ReleaseGameMng()	(c_GameManager::ReleaseInstance())

