// ex1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <Windows.h>


int main()
{

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD _oldInputMode;
	DWORD _NumRead;
	INPUT_RECORD irInBuf[128];

	GetConsoleMode(hStdin, &_oldInputMode);
	SetConsoleMode(hStdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	

	bool _bloop = true;
	double _tick = 0;

	while (_bloop)
	{
		ReadConsoleInput(hStdin, irInBuf, 128, &_NumRead);

		for (DWORD i = 0; i < _NumRead; i++)
		{
			if (irInBuf[i].EventType == KEY_EVENT)
			{
				if (irInBuf[i].Event.KeyEvent.bKeyDown)
				{
					SetConsoleCursorPosition(hStdout, { 0,10 });
					printf("%5d", irInBuf[i].Event.KeyEvent.wVirtualKeyCode);
				}
			}
		}
		_tick += 0.001;
		SetConsoleCursorPosition(hStdout, { 35,1 });
		printf("%5lf", _tick);
	}
	SetConsoleMode(hStdin, _oldInputMode);



    return 0;
}

