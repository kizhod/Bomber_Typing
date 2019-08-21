#pragma once
#include "c_Scene.h"

class c_GameOverScene : public c_Scene
{
public:
	c_GameOverScene(class c_SceneManager* a_pParent);
	virtual ~c_GameOverScene();

	virtual eScene GetScene() const override;

	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;
};

