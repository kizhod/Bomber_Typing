#pragma once

class c_SceneFactory
{
public:
	// Ŭ������ ��������� �ٸ� Ŭ������ �����ҽ� ��� �Ǵ°�?
	static class c_Scene* Make(class c_SceneManager* a_pParent, eScene a_eScene);
};

