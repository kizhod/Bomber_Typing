#include "pch.h"

#include "c_Scene.h"
#include <cassert>

c_Scene::c_Scene(c_SceneManager* a_pParent)
{
	assert(a_pParent != nullptr);
	m_refParent = a_pParent;
}

c_Scene::~c_Scene()
{
	m_refParent = nullptr;
}

void c_Scene::Init() {}
void c_Scene::Update(float a_fDeltaTime){}
void c_Scene::Render() {}
