#include "pch.h"
#include "c_GameScene.h"
#include "c_GameManager.h"


c_GameScene::c_GameScene(class c_SceneManager* a_pParent) : c_Scene(a_pParent){}
c_GameScene::~c_GameScene(){}

eScene c_GameScene::GetScene() const
{
	return eScene::Game;
}

void c_GameScene::Init()
{
	GameMng()->GameInit();
	GameMng()->StageStart();
}

void c_GameScene::Update(float a_fDeltaTime)
{
	GameMng()->Update(a_fDeltaTime);
}

void c_GameScene::Render()
{
	GameMng()->Render();
}

void c_GameScene::PostRender()
{
	GameMng()->PostRender();
}