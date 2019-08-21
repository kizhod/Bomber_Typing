#include "pch.h"
#include "c_GameOverScene.h"


c_GameOverScene::c_GameOverScene(class c_SceneManager* a_pParent) : c_Scene(a_pParent)
{
}

c_GameOverScene::~c_GameOverScene()
{
}

eScene c_GameOverScene::GetScene() const
{
	return eScene::GameOver;
}

void c_GameOverScene::Update(float a_fDeltaTime)
{
}

void c_GameOverScene::Render()
{
}