#include "pch.h"
#include "c_Bomb.h"

#include "c_GameManager.h"
#include "c_Ani.h"

c_Bomb::c_Bomb(int x, int y) : c_Object(x, y), m_pAni(new c_Ani())
{
	m_pAni->Resize(1);
	m_pAni->Add(0,
		{
		   {{"XXXXX"},
			{"XXXXX"},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"xxxxx"},
			{"xxxxx"},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"XXXXX"},
			{"XXXXX"},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"xxxxx"},
			{"xxxxx"},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{" XXX "},
			{" XXX "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{" xxx "},
			{" xxx "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"  X  "},
			{"  X  "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"  x  "},
			{"  x  "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"     "},
			{"  x  "},
			{"|   |"},
			{"| B |"},
			{"#####"}},

		   {{"     "},
			{"     "},
			{"|   |"},
			{"| B |"},
			{"#####"}},
		}
	);

	m_pAni->SetState(0);
	m_pNowAni = m_pAni->Get();
}

c_Bomb::~c_Bomb()
{
	SAFE_DELETE(m_pAni);
}

eObjectType c_Bomb::GetObjectType() const
{
	return eObjectType::Bomb;
}

void c_Bomb::Init()
{
	GameMng()->GetBombData(OUT this);
}

bool c_Bomb::_Update(float a_fDelta)
{
	m_pAni->Update(a_fDelta);
	m_pNowAni = m_pAni->Get();

	m_fLifeTime -= a_fDelta;
	if (m_fLifeTime <= 0.0f)
	{
		COORD c = rt.Center();
		GameMng()->ResistExplosion(this, rt.x, rt.y, m_nExplosiveRange);

		std::string s = "Explosion Pos : ";
		s += std::to_string(c.X);
		s += " //// ";
		s += std::to_string(c.Y);
		s += "\n";
		GameMng()->m_sLog += s;

		return true;
	}

	return false;
}

bool c_Bomb :: Explosived()
{
	GameMng()->ResistExplosion(this, rt.x, rt.y, m_nExplosiveRange);

	return true;
}
