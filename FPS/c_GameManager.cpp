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
	m_eState = eGameState::Run;

	ClearObject();

	m_refMap = c_MapData::Get(m_nNowStage);
	assert(m_refMap != nullptr && m_refMap->pMap != nullptr);

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
			
			CreateObject(eType, x, y);
		}
	}
}

void c_GameManager::StageEnd()
{
	m_eState = eGameState::End;
}

void c_GameManager::ClearObject()
{
	for(auto& vc: m_arrObj )
	{ 
		for (auto* pObj : vc)
		{
			SAFE_DELETE(pObj);
		}
		
		vc.clear();
	}
}

c_Object* c_GameManager::CreateObject(eObjectType a_eObjType, int x, int y)
{
	auto* pObj = c_ObjectFactory::Make(a_eObjType, x, y);
	if (a_eObjType == eObjectType::Player)
	{
		m_pPlayer = static_cast<c_Player*>(pObj);
		m_pPlayer->SetStat(&m_stPlayerData);
	}
	else
	{
		int nDepthIndex = (int)a_eObjType / (int)eObjectType::RenderDepthGap;
		nDepthIndex -= 1;
		
		m_arrObj[nDepthIndex].push_back(pObj); // ≤®≥æ∂ß¥¬ æÓ∂ª∞‘?
	}

	pObj->SetMap(m_pMap); // set, pMap?
	return pObj;
}

void c_GameManager::Update(float a_fDeltaTime)
{
	m_vcDelete.clear();
	int nSize = m_arrObj.size();

	//static std::vector<class c_Object*> vcDelete;
	//vcDelete.clear();

	for (int i = 1; i < nSize; ++i)
	{
		auto& arrObj = m_arrObj[i];

		for (auto& pObj : arrObj)
		{
			c_Object* p = nullptr;

			if (pObj->Update(a_fDeltaTime) == true)
			{
				p = pObj;
			}

			if (pObj->Interaction(m_pPlayer) == true)
			{
				p = pObj;
			}

			if (p != nullptr)
			{
				m_vcDelete.push_back(p);
			}
		}
	}

	m_pPlayer->Update(a_fDeltaTime);


//	for (auto* pDeleteObj : vcDelete)
//	{
//		pDeleteObj->RenderClear();
//		RemoveObject(pDeleteObj);
//	}
//	vcDelete.clear();
//
//	m_pPlayer->Update(a_fDeltaTime);
}

void c_GameManager::Render()
{
	for (auto& vc : m_arrObj)
	{
		for (auto* pObj : vc)
		{
			pObj->Render();
		}
	}

	m_pPlayer->Render();
	m_refMap->Render();

	if (m_eState == eGameState::End)
	{
		StageStart();
	}

	cout << "pos : " << m_pPlayer->rt.x << " /// " << m_pPlayer->rt.y << endl;
	COORD center = m_pPlayer->rt.Center();

	cout << "center : " << center.X << " /// " << center.Y << endl;

	if (m_sLog.size() > 0)
	{
		cout << m_sLog.c_str() << endl;
		m_sLog.clear();
	}
}

void c_GameManager::PostRender()
{
	for (auto* pDeleteObj : m_vcDelete)
	{
		pDeleteObj->RenderClear();
		RemoveObject(pDeleteObj);
	}
	m_vcDelete.clear();

	for (auto& ex : m_vcExplosion)
	{
		int nBombX = ex.x;
		int nBombY = ex.y;
		int nPow = ex.pow;

		CreateObject(eObjectType::Explosion, nBombX, nBombY);

		CreateExplosionRecursive(eDir::Left, nBombX, nBombY, nPow);
		CreateExplosionRecursive(eDir::Top, nBombX, nBombY, nPow);
		CreateExplosionRecursive(eDir::Right, nBombX, nBombY, nPow);
		CreateExplosionRecursive(eDir::Bottom, nBombX, nBombY, nPow);
	}

	m_vcExplosion.clear();
}

void c_GameManager::CreateExplosionRecursive(eDir a_eDir, int nBombX, int nBombY, int a_nRemainPower)
{
	switch (a_eDir)
	{
		case eDir::Left:	{nBombX -= 1;}break;
		case eDir::Top:		{nBombX -= 1;}break;
		case eDir::Right:	{nBombX += 1;}break;
		case eDir::Bottom:	{nBombX += 1;}break;
	}

	CreateObject(eObjectType::Explosion, nBombX, nBombY);

	--a_nRemainPower;
	if (a_nRemainPower == 0) { return; }

	CreateExplosionRecursive(a_eDir, nBombX, nBombY, a_nRemainPower);
}


void c_GameManager::RemoveObject(class c_Object* a_pObj) // ??
{
	eObjectType eType = a_pObj->GetObjectType();

	int nLevelIndex = (int)eType / (int)eObjectType::RenderDepthGap;
	nLevelIndex -= 1;

	auto& vc = m_arrObj[nLevelIndex];

	auto itor = std::find_if(std::begin(vc),
		std::end(vc), [a_pObj](c_Object*p) {return p == a_pObj; });
	if (itor != vc.end())
	{
		vc.erase(itor);
		SAFE_DELETE(a_pObj);
	}
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
		m_stPlayerData.fMoveSpeed += 30;
		break;
	default:
		assert(false && "arg error");
		break;
	}
}

void c_GameManager::Die(class c_Object* a_refObj)
{
	cout << "Player Die" << endl;
}

c_Object* c_GameManager::AddBomb(int a_nPlayerX, int a_nPlayerY)
{
	if (FindObject_withPosition(eObjectType::Bomb, a_nPlayerX, a_nPlayerY) == false)
	{
		int nX = a_nPlayerX / TileSize;
		int nY = a_nPlayerY / TileSize;

		return CreateObject(eObjectType::Bomb, nX, nY);
	}
	return nullptr;

}

bool c_GameManager::FindObject_withPosition(eObjectType a_eObj, int x, int y)
{
	int nX = x / TileSize;
	int nY = y / TileSize;
	int nIndex = ((int)a_eObj / (int)eObjectType::RenderDepthGap) - 1;

	for (auto* pObj : m_arrObj[nIndex])
	{
		if (pObj->GetObjectType() == a_eObj)
		{
			if (pObj->rt.IsIn(x, y)== true)
			{
				return true;
			}
		}
	}

	return false;
}

void c_GameManager::ResistExplosion(c_Object* a_refBomb, int x, int y, int pow)
{
	m_pPlayer->ResetBomb(a_refBomb);
	m_vcExplosion.emplace_back(x / TileSize, y / TileSize, pow);
}

bool c_GameManager::MoveCheck(c_Object* a_pMoveIgnoreObject)
{
	for (auto& vc : m_arrObj)
	{
		for (auto* pObj : vc)
		{
			if (a_pMoveIgnoreObject == pObj) { continue; }

			if (pObj->CanMove() == true) { continue; }

			if (pObj->IsCross(m_pPlayer) == true)
			{
				return false;
			}
		}
	}
	return true;
}

void c_GameManager::CheckExplosion(c_Object* a_refExplosion)
{
	int nIndex = (int)eObjectType::RenderDepthGap3 - 1;
	const auto& vc = m_arrObj[nIndex];

	for (auto* pObj : vc)
	{
		if (pObj == a_refExplosion) { continue; }

		if (a_refExplosion->IsCross(pObj) == true)
		{
			if (pObj->Explosived() == true)
			{
				m_vcDelete.push_back(pObj);
			}
		}
	}
}

void c_GameManager::AddScore(int a_nScore)
{
	m_nScore += m_nScore;
}

#include "c_Bomb.h"
void c_GameManager::GetBombData(OUT c_Bomb* a_refBomb) const
{
	a_refBomb->m_fLifeTime = m_stPlayerData.fBombTime;
	a_refBomb->m_nExplosiveRange = m_stPlayerData.nBombPower;
}