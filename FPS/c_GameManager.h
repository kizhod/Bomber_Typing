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

	void RemoveObject(class c_Object* a_pObj);
	void DropItem(class c_Object* a_pObj);
	void GetBombData(class c_Bomb* a_refBomb) const;
	void ObtainItem(eItem a_eItem);

private:
	
	std::vector<class Object*> m_vcObj;
	class c_Player* m_pPlayer = nullptr;

	int m_nNowStage = 0;
	float m_fGameTime = 0;
	class c_MapData* m_refMap = nullptr;
	char** m_pMap = nullptr; // ??

	int m_nNowLife = 0;
	int m_nScore = 0;

	std::queue<class c_Bomb*> m_qBomb;

	CharacterData m_stPlayerData;

};

#define InitGameMng()		{c_GameManager::CreateInstance();}
#define GameMng()			(c_GameManager::GetInstance())
#define ReleaseGameMng()	(c_GameManager::ReleaseInstance())

