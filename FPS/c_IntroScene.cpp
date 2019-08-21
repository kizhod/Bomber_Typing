#include "pch.h"
#include "c_IntroScene.h"

#include "c_SceneManager.h"

c_IntroScene::c_IntroScene(class c_SceneManager* a_pParent) : c_Scene(a_pParent)
{
}

c_IntroScene::~c_IntroScene()
{
}

eScene c_IntroScene::GetScene() const
{
	return eScene::Intro;
}

void c_IntroScene::Update(float a_fDeltaTime)
{
	if (IsKeyDown(eKey::A) == true)
	{
		m_refParent->ChangeScene(eScene::Game);
	}
}

void c_IntroScene::Render()
{
	SetCursor(0, 0);
	cout << "Intro Scene" << endl;
	cout << "Press Any Key" << endl;
}
