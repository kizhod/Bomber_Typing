#include "pch.h"
#include "c_Define.h"
#include "c_SceneManager.h"

void SetCursor(const COORD& a_stPos)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a_stPos);
}

void SetCursor(int a_nPosX, int a_nPosY)
{
	SetCursor(COORD{ (short)a_nPosX, (short)a_nPosY });
}

void SetCursorType(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch (c)
	{
	case CURSOR_TYPE::NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = false;
		break;
	case CURSOR_TYPE::SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = true;
		break;
	case CURSOR_TYPE::NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = true;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void SetConsoleSize(int a_nWidth, int a_nHeight, int a_nX, int a_nY)
{
	HWND console = GetConsoleWindow();
	MoveWindow(console, a_nX, a_nY, a_nWidth, a_nHeight, TRUE);
}