// ex7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "tge.h"


/*
void setCursor(HANDLE handle, int x, int y);
void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WORD attr);
void clearScreenBuffer(CHAR_INFO *pBuf); //버퍼 클리어
void updateBuffer(HANDLE handle, CHAR_INFO*pBuf);


extern CHAR_INFO g_chiBuffer[];
*/
int main()
{
	

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursor(hStdout,0, 26);

	
	clearScreenBuffer(g_chiBuffer);
	
	setCharacter(g_chiBuffer, 20, 3, 'A', 0x00cf);
	setCharacter(g_chiBuffer, 20, 4, 'B', 0x00cf);

	updateBuffer(hStdout, g_chiBuffer);

	

	


    return 0;
}

/*
for (int i = 0; i < SCREEN_BUF_SIZE; i++)    //클리어부분
{
chiBuffer[i].Char.UnicodeChar = 9678;
chiBuffer[i].Attributes = 0x009f;
}
*/



/*
COORD coordBufSize;
COORD coordBufferCoord;
coordBufSize.X = 80;
coordBufSize.Y = 25;
coordBufferCoord.X = 0;
coordBufferCoord.Y = 0;

SMALL_RECT destRect;
destRect.Top = 0;
destRect.Left = 0;
destRect.Bottom = destRect.Top + coordBufSize.Y - 1;
destRect.Right = destRect.Left + coordBufSize.X - 1;



WriteConsoleOutput(hStdout, chiBuffer, coordBufSize, coordBufferCoord, &destRect);

*/