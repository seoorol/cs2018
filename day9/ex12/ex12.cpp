// ex12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD _pos;
	_pos.X = 30;
	_pos.Y = 5;
	SetConsoleCursorPosition(hStdout, _pos);

	printf("login >");
	char szBuf[64];
	gets_s(szBuf, sizeof(szBuf));

	_pos.X = 30;
	_pos.Y = 5;
	SetConsoleCursorPosition(hStdout, _pos);
	printf("%s 님 접속중...", szBuf);

	_pos.X = 20;
	_pos.Y = 20;
	SetConsoleCursorPosition(hStdout, _pos);

    return 0;
}

