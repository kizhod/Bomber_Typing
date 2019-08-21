#pragma once

class c_ObjectFactory
{
public:
	static class c_Object* Make(eObjectType a_eType, int x, int y);
};

