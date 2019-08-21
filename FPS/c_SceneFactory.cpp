#include "pch.h"
#include "c_SceneFactory.h"

#include "c_IntroScene.h"
#include "c_GameScene.h"
#include "c_GameOverScene.h"

// class Scene을 담을 수 있는 포인터 SceneFactory::Make 의 의미는?
c_Scene* c_SceneFactory::Make(class c_SceneManager* a_pParent, eScene a_eScene)
{
	c_Scene* pMakedScene = nullptr;
	switch (a_eScene)
	{
	case eScene::Intro:
		pMakedScene = new c_IntroScene(a_pParent);
		break;
	case eScene::Game:
		pMakedScene = new c_GameScene(a_pParent);
		break;
	case eScene::GameOver:
		pMakedScene = new c_GameOverScene(a_pParent);
		break;
	default:
		assert(false && "arg error");
		break;
	}

	return pMakedScene;
}
