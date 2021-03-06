// ex4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../../engine/tge.h"
#include "maptool.h"

S_TGE_MAPTOOL g_MapToolObject;
enum { MODE_BRUSH_DRAW = 0, MODE_CMD_INPUT, MODE_BRUSH_MODE };

int main()
{
	
	DWORD cNumRead, fdwMode;
	HANDLE hStdin= GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD fdwOldMode; //동기 비동기 교환
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; //마우스모드 활성화
	SetConsoleMode(hStdin, fdwMode);
			

	TGE::clearScreenBuffer(0x2e, 0x0007);
	TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	initMapTool(&g_MapToolObject);
	int nFSM = MODE_BRUSH_DRAW;
	TGE::setCursor(hStdout, 0, 0);
	TGE::setCursor(hStdout, 0, 26);

	bool bLoop = true;

	while (bLoop)
	{
		static char szCmdBuf[32];
		static DWORD cNumRead;
		static INPUT_RECORD irInputBuf[128];

		ReadConsoleInput(hStdin, irInputBuf, sizeof(irInputBuf) / sizeof(INPUT_RECORD), &cNumRead); //무한루프
		for (DWORD i = 0; i < cNumRead; i++)
		{

			switch (irInputBuf[i].EventType)
			{
			case MOUSE_EVENT:
			{
				if (irInputBuf->Event.MouseEvent.dwButtonState == 1)
				{
					sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x \n", irInputBuf[i].Event.MouseEvent.dwMousePosition.X, irInputBuf[i].Event.MouseEvent.dwMousePosition.Y,
						g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
					//sprintf_s(szCmdBuf, 32, "set %4x %4x",
					//g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
				}
				else
				{
					if (irInputBuf[i].Event.MouseEvent.dwButtonState)
					{
						bLoop = false;
					}

					sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x \n", irInputBuf[i].Event.MouseEvent.dwMousePosition.X, irInputBuf[i].Event.MouseEvent.dwMousePosition.Y,
						g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
				}
				}

			}
		}
		break;
	}


    return 0;
}

