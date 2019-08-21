#pragma once
#include "c_Scene.h"

class c_GameScene : public c_Scene
{
public:
	c_GameScene(class c_SceneManager* a_pParent);
	virtual ~c_GameScene();

	virtual eScene GetScene() const override;

	virtual void Init() override;
	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;
};

