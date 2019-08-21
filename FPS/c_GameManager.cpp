#include "pch.h"
#include "c_GameManager.h"

#include "c_MapData.h"
#include "c_Object.h"
#include "c_Player.h"
#include "c_ObjectFactory.h"

CharacterData::CharacterData()
{
	fMoveSpeed = c_GameManager::MoveSpeed;
	fBombTime = c_GameManager::BombTime;
	nBombPower = c_GameManager::BombBasePower;
	nBombCount = c_GameManager::BombBaseCount;
}

c_GameManager::c_GameManager(){}

c_GameManager::~c_GameManager()
{
	ClearObject();
	SAFE_DELETE(m_pPlayer);
}

void c_GameManager::Init()
{
	c_MapData::Init();
}

void c_GameManager::Release()
{
	c_MapData::Release();
}

void c_GameManager::GameInit()
{
	m_nNowLife = 3;
	m_nScore = 0;
	m_nNowStage = 0;
}

void c_GameManager::StageStart()
{
	++m_nNowStage;
	m_fGameTime = RoundTime;

	ClearObject();

	m_refMap = c_MapData::Get(m_nNowStage);
	assert(m_refMap != nulptr && m_refMap->pMap != nullptr);

	int nWidth = m_refMap->x;
	int nHeight = m_refMap->y;
	const std::string& sRef = m_refMap->mapOriginData;
	m_pMap = m_refMap->pMap;
	
	//∏  ¡¶¿€
	for (int y = 0; y < nHeight; ++y)
	{
		for (int x = 0; x < nWidth; ++x)
		{
			int nIndex = y * nWidth + x; // y* ≥–¿Ã+ x??
			eObjectType eType = c_MapData::DataToObjectType(sRef[nIndex]);

			if (eType == eObjectType::None) { continue; }

			if (eType == eObjectType::Player && m_pPlayer != nullptr)
			{
				m_pPlayer->SetPos(x, y);
				m_pPlayer->SetMap(m_pMap);
				continue;
			}
			
			auto* pObj = c_ObjectFactory::Make(eType, x, y);
			if (eType == eObjectType::Player)
			{
				m_pPlayer = static_cast<c_Player*>(pObj);
			}
			else
			{
				int nLevel = (int)eType / (int)eObjectType::LevelGap;
				m_vcObj[nLevel - 1].push_back(pObj); // ≤®≥æ∂ß¥¬ æÓ∂ª∞‘?
			}

			pObj->SetMap(m_pMap); // set, pMap?
		}
	}
}

void c_GameManager::ClearObject()
{
	for(auto& vc: m_vcObj )
	{ 
		for (auto* pObj : vc)
		{
			SAFE_DELETE(pObj);
		}
		
		vc.clear();

	}
}

void c_GameManager::Update(float a_fDeltaTime)
{
	for (auto& vc : m_vcObj)
	{
		for (auto* pObj : vc)
		{
			pObj->Update(a_fDeltaTime);
		}

	}

	m_pPlayer->Update(a_fDeltaTime);
}

void c_GameManager::Render()
{
	for (auto& vc : m_vcObj)
	{
		for (auto* pObj : vc)
		{
			pObj->Render();
		}
	}

	m_pPlayer->Render();
	m_refMap->Render();
}

void c_GameManager::RemoveObject(class c_Object* a_pObj) // ??
{
	eObjectType eType = a_pObj->GetObjectType();

	int nLevelIndex = (int)eType / (int)eObjectType::LevelGap;
	nLevelIndex -= 1;

	auto& vc = m_vcObj[nLevelIndex];

	auto itor = std::find_if(std::begin(vc),
		std::end(vc), [a_pObj](c_Object*p) {return p == a_pObj; });
	assert(itor != vc.end());
	vc.erase(itor);
}

void c_GameManager::DropItem(c_Object* a_pObj)
{}

void c_GameManager::ObtainItem(eItem a_eItem)
{
	switch (a_eItem)
	{
	case eItem::PowerUp:
		m_stPlayerData.nBombPower += 1;
		break;
	case eItem::BombCount:
		m_stPlayerData.nBombCount += 1;
		break;
	case eItem::SpeedUp:
		m_stPlayerData.fMoveSpeed += 1;
		break;
	default:
		assert(false && "arg error");
		break;
	}
}

#include "c_Bomb.h"
void c_GameManager::GetBombData(c_Bomb* a_refBomb) const
{
	a_refBomb->m_fLifeTime = m_stPlayerData.fBombTime;
	a_refBomb->m_nExplosiveRange = m_stPlayerData.nBombPower;
}