// ex2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../../engine/tge.h"
///////주인공오브젝트///////
COORD g_cdPlayerPos;

////////////////////////////
int main()
{

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	DWORD fdwOldMode; //동기 비동기 교환
	GetConsoleMode(hStdin, &fdwOldMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT); //or연산

	TGE::loadBufferBinary(TGE::g_chiBuffer, "../../../pub_res/1.map");
	g_cdPlayerPos.X = 1;  //캐릭터위치초기화
	g_cdPlayerPos.Y = 19;

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
						switch (irInputBuf[i].Event.KeyEvent.wVirtualScanCode)
						{
						case 28: //커맨드 입력 모드 전환
							_nFSM = 1;
							SetConsoleMode(hStdin, fdwOldMode);
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
			if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0 )
			{
				if (!strcmp(szTokenBuf[0], "quit"))
				{
					_bLoop = false;
				}
				else if (!strcmp(szTokenBuf[0], "move"))
				{
					int _dx = atoi(szTokenBuf[1]);
					int _dy = atoi(szTokenBuf[2]);
					g_cdPlayerPos.X += _dx;
					g_cdPlayerPos.Y += _dy;
				}
			}

			szCmdBuf[0] = 0x00;
		}

		

		//오브젝트처리
		TGE::setCharacter(TGE::g_chiBuffer, g_cdPlayerPos.X, g_cdPlayerPos.Y, 0x41, 0x000f);
		//랜더링
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);  //화면갱신

	}


	return 0;
}


