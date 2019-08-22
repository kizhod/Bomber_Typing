#include "pch.h"
#include "c_Ani.h"

void c_Ani::Resize(int a_nAniTypeCount)
{
	m_vcAni.resize(a_nAniTypeCount)
}

c_Ani::~c_Ani()
{
	
}

void c_Ani::Resize(int a_nAniTypeCount)
{
	m_vcAni.resize(a_nAniTypeCount);
}

void c_Ani::Add(int a_nAni, RenderTile* tile)
{
	m_vcAni[a_nAni].push_back(tile);
}

void c_Ani::SetState(int a_nAni, int a_nFrame)
{
	m_pCurrentAni = &m_vcAni[a_nAni];

	m_nAniType = a_nAni;
	m_nCut = a_nFrame;
	m_nNowMaxFrame = m_pCurrentAni->size();
}

RenderTile* c_Ani::Get()
{
	RenderTile* r = (*m_pCurrentAni)[m_nCut++];
	m_nCut %= m_nNowMaxFrame;
	return r;
}


