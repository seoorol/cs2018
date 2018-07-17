// ex1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../../engine/tge.h"

int main()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	TGE::clearScreenBuffer(0x2e, 0x0007);
	
	TGE::drawLineH(5, 5, 20, 0x20, 0x00c0);
	TGE::drawLineH(5, 6, 19, 0x20, 0x00a0);
	
	TGE::drawLineV(7, 3, 20, 0x20, 0x00e0);

		//TGE::drawBox(TGE::g_chiBuffer, 0, 11,80, 1);
		//TGE::drawBox(TGE::g_chiBuffer, 79, 1, 1, 24);
		//TGE::drawBox(TGE::g_chiBuffer, 0, 1, 1, 24);
	
	

	TGE::updateBuffer(hStdout, TGE::g_chiBuffer);


    return 0;
}

