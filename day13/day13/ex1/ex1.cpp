// ex2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../../engine/tge.h"
#include "maptool.h"

S_TGE_MAPTOOL g_MapToolObject;
enum { MODE_BRUSH_DRAW = 0, MODE_CMD_INPUT, MODE_BRUSH_MODE };

int main()
{

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode; //동기 비동기 교환

	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT); //or연산
		
	TGE::updateBuffer(hStdout, TGE::g_chiBuffer);

	initMapTool(&g_MapToolObject);
	int nFSM = MODE_BRUSH_DRAW;
	TGE::setCursor(hStdout, 0, 0);
	TGE::setCursor(hStdout, 0, 26);
	
	TGE::clearScreenBuffer(0x2e, 0x0007);
	while (1)
	{
		static char szCmdBuf[32];

		switch (nFSM) //유한상태기계
		{
		case MODE_BRUSH_DRAW:
		{	//비동기 키입력 처리
			static DWORD cNumRead;
			static INPUT_RECORD irInputBuf[128];
			ReadConsoleInput(hStdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0; i < cNumRead; i++)
			{
				if (irInputBuf[i].EventType == KEY_EVENT)
				{
					if (irInputBuf[i].Event.KeyEvent.bKeyDown)
					{
						TGE::setCursor(hStdout, 0, 0);
						TGE::setCursor(hStdout, 0, 26);
						printf("								    	 ]");
						TGE::setCursor(hStdout, 0, 26);
						printf("%d", irInputBuf[i].Event.KeyEvent.wVirtualScanCode);
						switch (irInputBuf[i].Event.KeyEvent.wVirtualScanCode)
						{
						case 28: //커맨드 입력 모드 전환
							nFSM = 1;
							SetConsoleMode(hStdin, fdwOldMode);
							break;
						case 50: //브러쉬 이동모드 전환 <M>
							nFSM = MODE_BRUSH_MODE;
							SetConsoleMode(hStdin, fdwOldMode);
							break;
						case 72:  //x증가 오른쪽 y증가 아래로  //up 72 down 80 left 75 right 77 back 14
							g_MapToolObject.m_cdCurrentCursorPos.Y -= 1;
							sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							//set g_cdCurrentCursorPos.X g_cdCurrentCursorPos.Y-1 0x20 0x00e0
							//strcpy_s(szCmdBuf, 32,)								
							break;
						case 80:
							g_MapToolObject.m_cdCurrentCursorPos.Y += 1;
							sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							break;
						case 75:
							g_MapToolObject.m_cdCurrentCursorPos.X -= 1;
							sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							break;
						case 77:
							g_MapToolObject.m_cdCurrentCursorPos.X += 1;
							sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
							break;
						}
						if (irInputBuf[i].Event.KeyEvent.wVirtualScanCode == 28)
						{
							nFSM = 1;
							SetConsoleMode(hStdin, fdwOldMode);
						}
					}
				}
				else if(irInputBuf[i].EventType == MOUSE_EVENT)  //마우스이벤트
				{
					if (irInputBuf[i].Event.MouseEvent.dwButtonState == 1)
					{
						int _posx = irInputBuf[i].Event.MouseEvent.dwMousePosition.X;
						int _posy = irInputBuf[i].Event.MouseEvent.dwMousePosition.Y;
						sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x",_posx, _posy,
							g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						g_MapToolObject.m_cdCurrentCursorPos.X = _posx;
						g_MapToolObject.m_cdCurrentCursorPos.Y = _posy;
					}
					else if(irInputBuf[i].Event.MouseEvent.dwButtonState == 2)
					{
						int _posx = irInputBuf[i].Event.MouseEvent.dwMousePosition.X;
						int _posy = irInputBuf[i].Event.MouseEvent.dwMousePosition.Y;
						sprintf_s(szCmdBuf, 32, "set %d %d %4x %4x", _posx, _posy,
							0x2e , 0x0007);
						g_MapToolObject.m_cdCurrentCursorPos.X = _posx;
						g_MapToolObject.m_cdCurrentCursorPos.Y = _posy;
					}
														
				}
			}
		}
		break;

		case MODE_CMD_INPUT:
		{
			//스크립트 입력처리
			TGE::setCursor(hStdout, 0, 0);
			TGE::setCursor(hStdout, 0, 26);
			printf("							       ]");
			TGE::setCursor(hStdout, 0, 26);
			printf("[cmd : ");
			gets_s(szCmdBuf, sizeof(szCmdBuf)); //동기모드	
			nFSM = 0;
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT); //or연산
		}
		break;
		case MODE_BRUSH_MODE:
		{
			//비동기 키입력 처리
			static DWORD cNumRead;
			static INPUT_RECORD irInputBuf[128];
			ReadConsoleInput(hStdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0; i < cNumRead; i++)
			{
				if (irInputBuf[i].EventType == KEY_EVENT)
				{
					if (irInputBuf[i].Event.KeyEvent.bKeyDown)
					{
						TGE::setCursor(hStdout, 0, 0);
						TGE::setCursor(hStdout, 0, 26);
						printf("								    	 ]");
						TGE::setCursor(hStdout, 0, 26);
						printf("%d", irInputBuf[i].Event.KeyEvent.wVirtualScanCode);
						switch (irInputBuf[i].Event.KeyEvent.wVirtualScanCode)
						{
						case 72:
						{
							g_MapToolObject.m_cdCurrentCursorPos.Y -= 1;
							sprintf_s(szCmdBuf, 32, "moveCursor %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						}
						break;

						case 80:
						{
							g_MapToolObject.m_cdCurrentCursorPos.Y += 1;
							sprintf_s(szCmdBuf, 32, "moveCursor %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						}
						break;
						case 75:
						{
							g_MapToolObject.m_cdCurrentCursorPos.X -= 1;
							sprintf_s(szCmdBuf, 32, "moveCursor %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						}
						break;
						case 77:
						{
							g_MapToolObject.m_cdCurrentCursorPos.X += 1;
							sprintf_s(szCmdBuf, 32, "moveCursor %d %d %4x %4x", g_MapToolObject.m_cdCurrentCursorPos.X, g_MapToolObject.m_cdCurrentCursorPos.Y,
								g_MapToolObject.m_wCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						}
						break;
						case 32:
							nFSM = MODE_BRUSH_DRAW;
							strcpy_s(szCmdBuf, 32, "moveCursorEnd");
							break;
						}
					}
				}
			} //end for
		}
		break;
		default:
			break;
		}


		//커멘드파싱
		if (!parseCmd(&g_MapToolObject, szCmdBuf)) break;

		//TGE::setCharacter(TGE::g_chiBuffer, g_cdCurrentCursorPos.X, g_cdCurrentCursorPos.Y, 0x20, 0x00e0);

		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}
	return 0;
}