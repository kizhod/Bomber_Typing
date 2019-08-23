#pragma once

#include "c_SceneManager.h"

class c_Scene
{
public:
	c_Scene(c_SceneManager* a_pParent);
	virtual ~c_Scene();

	virtual eScene GetScene() const = 0;

	virtual void Init();
	virtual void Update(float a_fDeltaTime);
	virtual void Render();
	virtual void PostRender();


public:

	class c_SceneManager* m_refParent = nullptr;
};

