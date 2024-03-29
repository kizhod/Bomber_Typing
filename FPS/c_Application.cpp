#include "pch.h"
#include "c_Application.h"
#include <ctime>
#include <cstdlib>

#include "c_SceneManager.h"
#include "c_GameManager.h"

constexpr float c_Application::GetTargetFPS()
{
	constexpr float nTargetFPS = 60;
	return (1 / nTargetFPS) * 1000;
}

c_Application::c_Application()
{
	SetConsoleSize(1400, 1200);
	SetCursorType(CURSOR_TYPE::NOCURSOR);
	srand((unsigned int)time(0));

	InitSceneMng();
	InitGameMng();
}

c_Application::~c_Application()
{
	ReleaseGameMng();
	ReleaseSceneMng();
}

void c_Application::Run()
{
	while (true)
	{
		clock_t now = clock();
		clock_t term = now - m_nLastStamp;

		if (term > GetTargetFPS())
		{
			m_nDeltaTick = term;
			m_nLastStamp = now;

			float fDeltaTime = m_nDeltaTick / (float)1000;

			if (Update(fDeltaTime) == eUpdateState::Final) { break; }

			Render();

			PostRender();
		}
	}
}

eUpdateState c_Application::Update(float a_fDelta)
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		return eUpdateState::Final;
	}

	SceneMng()->Update(a_fDelta);

	return eUpdateState::Run;
}

void c_Application::Render()
{
	SceneMng()->Render();
}

void c_Application::PostRender()
{
	SceneMng()->PostRender();
}