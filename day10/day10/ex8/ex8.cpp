// ex8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "tge.h"






int main()
{

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	clearScreenBuffer(g_chiBuffer);

	drawBox(g_chiBuffer, 0, 1, 1, 24);
	drawBox(g_chiBuffer, 1, 1, 79, 1);
	drawBox(g_chiBuffer, 79, 1, 1, 24);
	
		
	updateBuffer(hStdout, g_chiBuffer);
	
	
	
	return 0;
}

