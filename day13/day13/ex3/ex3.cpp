// ex2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../../engine/tge.h"
#include "playerObject.h"


/*//////주인공오브젝트///////
COORD g_cdPlayerPos;////////
int g_nInven_keyCount;
///////////////////////////*/
playerobject::S_PlayerObject g_gamePlayer;

int main()
{

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode; //동기 비동기 교환
	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT); //or연산

	CHAR_INFO *pBackScreenBuffer = TGE::CreateScreenBuffer();
	CHAR_INFO *pMapDataBuffer = TGE::CreateScreenBuffer();

	TGE::loadBufferBinary(pMapDataBuffer, "../../../pub_res/1.map");
	/*g_cdPlayerPos.X = 1;  //캐릭터위치초기화
	g_cdPlayerPos.Y = 19;
	g_nInven_keyCount = 0; //키 갯수 초기화*/
	playerobject::Init(&g_gamePlayer, 1, 19);

	bool _bLoop = true;
	static int _nFSM = 0;
	while (_bLoop) //무한루프
	{
		static char szCmdBuf[128];

		switch (_nFSM) //입력 처리
		{
		case 0:      //비동기모드
			static DWORD cNumRead;
			static INPUT_RECORD irInputBuf[128];
			ReadConsoleInput(hStdin, irInputBuf, 128, &cNumRead);

			for (DWORD i = 0; i < cNumRead; i++)
			{
				if (irInputBuf[i].EventType == KEY_EVENT)
				{
					if (irInputBuf[i].Event.KeyEvent.bKeyDown)
					{
						switch (irInputBuf[i].Event.KeyEvent.wVirtualKeyCode)
						{
						case VK_RETURN: //커맨드 입력 모드 전환
							_nFSM = 1;
							SetConsoleMode(hStdin, fdwOldMode);
							break;
						case VK_UP:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 0 -1");
							break;
						case VK_DOWN:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 0 1");
							break;
						case VK_LEFT:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move -1 0");
							break;
						case VK_RIGHT:
							sprintf_s(szCmdBuf, sizeof(szCmdBuf), "move 1 0");
							break;
						}

					}
				}
			}
			break;
		case 1:  //동기모드		
				 //스크립트 입력처리
			TGE::setCursor(hStdout, 0, 0);
			TGE::setCursor(hStdout, 0, 26);
			printf("							       ]");
			TGE::setCursor(hStdout, 0, 26);
			printf("[cmd : ");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			_nFSM = 0;
			SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT); //or연산

			break;  //동기모드 getch함수

		}
		//커멘드처리
		{
			char szTokenBuf[8][64];
			if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0)
			{
				if (!strcmp(szTokenBuf[0], "quit"))
				{
					_bLoop = false;
				}
				else if (!strcmp(szTokenBuf[0], "move"))

				{
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);

					playerobject::move(&g_gamePlayer, pMapDataBuffer, _dx, _dy);
				}
			}
			else if (!strcmp(szTokenBuf[0], "use"))
			{
				int _dx = atoi(szTokenBuf[1]);
				int _dy = atoi(szTokenBuf[2]);
				switch (playerobject::use(&g_gamePlayer, pMapDataBuffer, _dx, _dy))
				{
				case 0x00c0:
					printf("문을 열었습니다.");
					break;
				case 0x00a0:
					printf("탈출성공");
					_bLoop = false;
					break;
				default:
					printf("문이 없습니다.");
					break;
				}

			}
			else if (!strcmp(szTokenBuf[0], "get"))
			{
				int _dx = atoi(szTokenBuf[1]);
				int _dy = atoi(szTokenBuf[2]);

				if (playerobject::get(&g_gamePlayer, pMapDataBuffer, _dx, _dy) == 1)
				{
					printf("열쇠발견");
				}
				else
				{
					printf("아무것도없습니다.");
				}
			}
			else if (!strcmp(szTokenBuf[0], "drop"))
			{

			}
			else if (!strcmp(szTokenBuf[0], "teleport"))
			{
				int _x = atoi(szTokenBuf[1]);
				int _y = atoi(szTokenBuf[2]);

				//g_cdPlayerPos.X = _x;
				//g_cdPlayerPos.Y = _y;
			}

			szCmdBuf[0] = 0x00;
		}

		//배경다시 그리기
		memcpy_s(pBackScreenBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pMapDataBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));
		//오브젝트처리
		playerobject::DrawObject(&g_gamePlayer, pBackScreenBuffer);
		//전체 화면 갱신<랜더링>
		memcpy_s(TGE::g_chiBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO), pBackScreenBuffer, SCREEN_BUF_SIZE * sizeof(CHAR_INFO));
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);  //화면갱신

	}

	free(pBackScreenBuffer);
	free(pMapDataBuffer);
	return 0;
}


