#include "pch.h"
#include "c_Explosion.h"

#include "c_Ani.h"

c_Explosion::c_Explosion(int x, int y) : c_Object(x, y), m_pAni(new c_Ani())
{
	m_pAni->Resize(1);
	m_pAni->Add(0,
		{
		   {{"* * *"},
			{"     "},
			{"* * *"},
			{"     "},
			{"* * *"}},
		   {{" * * "},
			{"*   *"},
			{"  *  "},
			{"*   *"},
			{" * * "}},
		}
	);

	m_pAni->SetState(0);
	m_pNowAni = m_pAni->Get();
}

c_Explosion::~c_Explosion()
{
	SAFE_DELETE(m_pAni);
}

eObjectType c_Explosion::GetObjectType() const
{
	return eObjectType::Explosion;
}

bool c_Explosion::CanMove() const
{
	return true;
}

void c_Explosion::_PreUpdate(float a_fDelta)
{

}

bool c_Explosion::_Update(float a_fDelta)
{
	m_pAni->Update(a_fDelta);
	m_pNowAni = m_pAni->Get();

	m_fLife -= a_fDelta;

	if (m_fLife < 0)
	{
		return true;
	}

	return false;
}