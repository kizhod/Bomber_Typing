#include "pch.h"
#include "c_MapData.h"

c_MapData c_MapData::m_arrData[eGame::MaxStage] = { {}, }; // {}??

c_MapData* c_MapData::Get(int a_nStage)
{
	return &m_arrData[a_nStage-1];
}

void c_MapData::Init()
{
	// 1스테이지
	m_arrData[0].x = 10;
	m_arrData[0].y = 10;
	m_arrData[0].mapOriginData =
		"1111111111"
		"1000000601"
		"1020007001"
		"1000000001"
		"1000300001"
		"1000000001"
		"1000004001"
		"1000000001"
		"1050000001"
		"1111111111";
	m_arrData[0].MakeMapBuffer();

	// 2스테이지
	m_arrData[1].x = 10;
	m_arrData[1].y = 10;
	m_arrData[1].mapOriginData =
		"1111111111"
		"1000000601"
		"1020007001"
		"1000000001"
		"1000300001"
		"1000000001"
		"1000004001"
		"1000000001"
		"1050000001"
		"1111111111";
	m_arrData[1].MakeMapBuffer();

	// 3스테이지
	m_arrData[2].x = 10;
	m_arrData[2].y = 10;
	m_arrData[2].mapOriginData =
		"1111111111"
		"1000000601"
		"1020007001"
		"1000000001"
		"1000300001"
		"1000000001"
		"1000004001"
		"1000000001"
		"1050000001"
		"1111111111";
	m_arrData[2].MakeMapBuffer();
}

void c_MapData::Release()
{
	for (auto& mapData : m_arrData)
	{
		mapData.ReleaseData();
	}
}

void c_MapData::MakeMapBuffer()
{
	int nX = x * TileSize;
	int nY = y * TileSize;

	pMap = new char*[nY];

	for (int i = 0; i < nY; ++i)
	{
		pMap[i] = new char[nX + 1];
		pMap[i][nX] = 0;
	}
}

/*
void c_MapData::MakeMap() // 이해가 안되는 부분.
{
	pMap = new char*[y]; // char** pMap and char*[y] ??

	for (int i = 0; i < y; ++i)
	{
		pMap[i] = new char[x + 1];

		int gap = i * x;

		memcpy_s(pMap[i], sizeof(char) * (x + 1),
			mapOriginData + gap, sizeof(char)* x);

		pMap[i][x] = 0;
	}
}
*/

void c_MapData::ReleaseData()
{
	for (int i = 0; i < y; ++i)
	{
		SAFE_DELETE_ARR(pMap[i])
	}

	SAFE_DELETE_ARR(pMap);
}

void c_MapData::Render()
{
	for (int i = 0; i < y; ++i)
	{
		cout << pMap[i] << endl;
	}
}