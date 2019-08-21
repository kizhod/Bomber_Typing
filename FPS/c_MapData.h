#pragma once

class c_MapData
{
public:
	c_MapData() = default;
	static c_MapData* Get(int a_nStage);
	static void Init();
	static void Release();

private:
	static c_MapData m_arrData[eGame::MaxStage];

private:

	void MakeMapBuffer();
	//void MakeMap();
	void ReleaseData();

public:
	void Render();

public:
	int x;
	int y;
	const char* mapOriginData;
	char** pMap = nullptr; // ??
};

