#include "pch.h"

#include "c_SceneManager.h"
#include "c_Scene.h"

#include "c_SceneFactory.h"

c_SceneManager::c_SceneManager()
{
	int nIndex = 0;

	m_arrKeys[(int)eKey::A]		= 'A';
	m_arrKeys[(int)eKey::Left]	= VK_LEFT;
	m_arrKeys[(int)eKey::W]		= 'W';
	m_arrKeys[(int)eKey::Up]	= VK_UP;
	m_arrKeys[(int)eKey::D]		= 'S';
	m_arrKeys[(int)eKey::Right] = VK_RIGHT;
	m_arrKeys[(int)eKey::S]		= 'D';
	m_arrKeys[(int)eKey::Left]	= VK_LEFT;
	m_arrKeys[(int)eKey::SPACE]	= VK_SPACE;
	m_arrKeys[(int)eKey::A]		= 'F';

	for (eInputState& state : m_KeyState)
	{
		state = eInputState::None;
	}
}

c_SceneManager::~c_SceneManager()
{
	SAFE_DELETE(m_pNowScene);
}

void c_SceneManager::Init()
{
	ChangeScene(eScene::Scene_First);
}

void c_SceneManager::ChangeScene(eScene a_eScene)
{
	SAFE_DELETE(m_pNowScene);

	m_pNowScene = c_SceneFactory::Make(this, a_eScene); // 현재 씬?

	assert((m_pNowScene != nullptr) && "error");

	system("cls");

	m_pNowScene->Init();
}

void c_SceneManager::Update(float a_fDeltaTime)
{
	KeyCheck();
	m_pNowScene->Update(a_fDeltaTime);
}

void c_SceneManager::Render()
{
	m_pNowScene->Render();
}

void c_SceneManager::KeyCheck() // 비트연산??
{
	for (int i = 0; i < (int)eKey::Max; ++i)
	{
		int nNowPress = (GetAsyncKeyState(m_arrKeys[i]) & 0x8000) ? 1 : 0;
		m_KeyState[i] = (eInputState)(nNowPress | m_BeforeKeyState[i]);
		m_BeforeKeyState[i] = (nNowPress << 1);
	}
}

eInputState c_SceneManager::GetKeyState(eKey a_eKey)
{
	return m_KeyState[(int)a_eKey];
}
