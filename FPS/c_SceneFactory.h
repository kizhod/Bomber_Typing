#pragma once

class c_SceneFactory
{
public:
	// 클래스의 멤버변수로 다른 클래스를 선언할시 어떻게 되는가?
	static class c_Scene* Make(class c_SceneManager* a_pParent, eScene a_eScene);
};

