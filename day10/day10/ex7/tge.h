#pragma once


void setCursor(HANDLE handle, int x, int y);
void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WORD attr);
void clearScreenBuffer(CHAR_INFO *pBuf); //버퍼 클리어
void updateBuffer(HANDLE handle, CHAR_INFO*pBuf);


extern CHAR_INFO g_chiBuffer[];
