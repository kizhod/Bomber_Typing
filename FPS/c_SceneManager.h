#pragma once

class c_SceneManager
{
public:
	static inline c_SceneManager* m_pInstance = nullptr;
	c_SceneManager();
	~c_SceneManager();

	c_SceneManager operator=(c_SceneManager&) = delete;
	c_SceneManager(c_SceneManager&&) = delete; // &&?? ½Ì±ÛÅæ?
	c_SceneManager(const c_SceneManager&) = delete;

public:

	static void CreateInstance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new c_SceneManager();
		}
	}

	static c_SceneManager* GetInstance()
	{
		return m_pInstance;
	}

	static void ReleaseInstance()
	{
		SAFE_DELETE(m_pInstance);
	}

public:

	void Init();
	void ChangeScene(eScene a_eScene);

	void Update(float a_fDeltaTime);
	void Render();

	eInputState GetKeyState(eKey a_eKey);

private:

	void KeyCheck();

private:
	class c_Scene*	m_pNowScene = nullptr;

	int				m_arrKeys[(int)eKey::Max];
	int				m_BeforeKeyState[(int)eKey::Max];
	eInputState		m_KeyState[(int)eKey::Max];
};

#define InitSceneMng()		{c_SceneManager::CreateInstance(); c_SceneManager::GetInstance()->Init();}
#define SceneMng()			(c_SceneManager::GetInstance())
#define ReleaseSceneMng()	(c_SceneManager::ReleaseInstance())