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

	c_GameManager operator=(c_GameManager&) = delete; // ������ �����ε� ����
	c_GameManager(c_GameManager&&) = delete; // �̵�����
	c_GameManager(const c_GameManager&) = delete; // ��������?

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

	void ClearObject();
	void CreateObject(eObjectType a_eObjType, int x, int y);

	// ��ȣ�ۿ�
	void RemoveObject(class c_Object* a_pObj);
	void DropItem(class c_Object* a_pObj);
	void GetBombData(class c_Bomb* a_refBomb) const;
	void ObtainItem(eItem a_eItem);
	void Die(class c_Object* a_refObj);
	bool AddBomb(int a_nPlayerX, int a_nPlayerY);
	void ResistExplosion(int a_nBombX, int a_nBombY, int a_nPower);

private:
	// ������Ʈ
	std::array<std::vector<class c_Object*>, (int)eObjectType::RenderDepthCount> m_arrObj;
	class c_Player* m_pPlayer = nullptr;

	// �������� ����
	int m_nNowStage = 0;
	//�����ð�
	float m_fGameTime = 0;
	class c_MapData* m_refMap = nullptr;
	char** m_pMap = nullptr; // ??

	//������
	int m_nNowLife = 0;
	int m_nScore = 0;

	// ����
	std::queue<class c_Bomb*> m_qBomb;

	// ���� �÷��̾� ������
	CharacterData m_stPlayerData;

	eGameState m_eState = eGameState::None;

	std::string m_sLog = "";

};

#define InitGameMng()		{c_GameManager::CreateInstance();}
#define GameMng()			(c_GameManager::GetInstance())
#define ReleaseGameMng()	(c_GameManager::ReleaseInstance())

