// ex13.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <windows.h>

int main()
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO csblnfo;
	WORD wOldColorAttr;

	GetConsoleScreenBufferInfo(hConsole, &csblnfo);

	wOldColorAttr = csblnfo.wAttributes;


	// 0000			0000
	// 8421			8421
	// background   foreground
	// iRGB			iRGB
	// 
	SetConsoleTextAttribute(hConsole, 0x1e);
	printf("hello \n");
	SetConsoleTextAttribute(hConsole, 0x2e);
	printf("world \n");

	SetConsoleTextAttribute(hConsole, wOldColorAttr);
	

    return 0;
}

