#pragma once
#include "c_Scene.h"

class c_IntroScene : public c_Scene
{
public:
	c_IntroScene(class c_SceneManager* a_pParent);
	virtual ~c_IntroScene();

	// Scene을 통해 상속
	virtual eScene GetScene() const override;

	virtual void Update(float a_fDeltaTime) override;
	virtual void Render() override;
};

