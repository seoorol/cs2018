// ex3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../../engine/tge.h"


int main()
{

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	TGE::startTGE();

	while (1)
	{

		SetConsoleCursorPosition(hStdout, { 0 , 10 });
		printf("%d %d", TGE::input::g_KeyTable[VK_SPACE], TGE::input::g_KeyTable['M']);
	}

	TGE::endTGE();
    return 0;
}

