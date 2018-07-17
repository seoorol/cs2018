#include "stdafx.h"
#include "../../../engine/tge.h"
#include "maptool.h"

struct S_SPRITE_HEADER
{
	char szHeader[16];
	COORD m_cdWorkSpr;

};

struct S_SPRITE_OBJECT
{
	S_SPRITE_HEADER m_header;
	CHAR_INFO *m_pSpriteBuf;
};

void Init(S_SPRITE_OBJECT *pObj)
{
	pObj->m_header.m_cdWorkSpr = { 0, 0 };
	strcpy_s(pObj->m_header.szHeader, sizeof(pObj->m_header.szHeader), "TGESPR");
	pObj->m_pSpriteBuf = NULL;
}
int load(S_SPRITE_OBJECT *pObj, const char *szFileName)
{

	return 0;
}
int save(S_SPRITE_OBJECT *pObj, const char *szFileName)
{

	return 0;
}
int put(S_SPRITE_OBJECT *pObj, int posx, int posy, CHAR)
{
	TGE::putSprite(posx, posy,
		pObj->m_header.m_cdWorkSpr.X,
		pObj->m_header.m_cdWorkSpr.Y, TGE::g_chiBuffer, pObj->m_pSpriteBuf);


}
int get(S_SPRITE_OBJECT *pObj, int posx, int posy, int _width, int _height)
{
	if (pObj->m_pSpriteBuf != NULL) { free(pObj->m_pSpriteBuf); }
	pObj->m_pSpriteBuf = (CHAR_INFO *)malloc(sizeof(CHAR_INFO)*(_width*_height));
	pObj->m_header.m_cdWorkSpr = { (SHORT)_width, (SHORT)_height };

	return 0;
}

tge_sprite:: S_SPRITE_OBJECT = g_WorkSprObject;

void initMapTool(S_TGE_MAPTOOL *pObj)
{
	pObj->m_cdCurrentCursorPos.X = 40;
	pObj->m_cdCurrentCursorPos.Y = 12;
	pObj->m_wCurrentBrushCode = 0x20;
	pObj->m_wCurrentBrushAttr = 0x00e0;

	
}

int parseCmd(S_TGE_MAPTOOL *pObj, char *szCmdBuf)
{
	static char szTokenBuf[8][MAX_TOKEN_SIZE];
	//토큰처리
	TGE::doTokenize(szCmdBuf, szTokenBuf);
	if (!strcmp(szTokenBuf[0], "quit"))
	{
		printf("Bye Bye \n");
		return 0;
	}
	else if (!strcmp(szTokenBuf[0], "set"))
	{
		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[2]);
		WCHAR _code = (WCHAR)strtol(szTokenBuf[3], NULL, 16);
		WORD _attr = (WORD)strtol(szTokenBuf[4], NULL, 16);
		TGE::setCharacter(TGE::g_chiBuffer, _xpos, _ypos, _code, _attr);
	}
	else if (!strcmp(szTokenBuf[0], "moveCursor")|| !strcmp(szTokenBuf[0], "moveCursorEnd"))
	{
		static COORD _oldPos = { -1, -1 };
		static WCHAR _oldCode = -1;
		static WORD _oldAttr = -1;

		if (!strcmp(szTokenBuf[0], "moveCursorEnd"))
		{
			_oldPos.X = -1;
		}

		if (_oldPos.X >= 0) //초기값아니면 이전값으로 복원
		{
			TGE::setCharacter(TGE::g_chiBuffer, _oldPos.X, _oldPos.Y, _oldCode, _oldAttr);
		}
		//이전값 대피
		_oldPos.X = pObj->m_cdCurrentCursorPos.X;
		_oldPos.Y = pObj->m_cdCurrentCursorPos.Y;
		CHAR_INFO *oldInfo = TGE::getCharacter(TGE::g_chiBuffer, _oldPos.X, _oldPos.Y);
		_oldCode = oldInfo->Char.UnicodeChar;
		_oldAttr = oldInfo->Attributes;


		pObj->m_cdCurrentCursorPos.X = atoi(szTokenBuf[1]);
		pObj->m_cdCurrentCursorPos.Y = atoi(szTokenBuf[2]);
		WCHAR _code = (WCHAR)strtol(szTokenBuf[3], NULL, 16);
		WORD _attr = (WORD)strtol(szTokenBuf[4], NULL, 16);
		TGE::setCharacter(TGE::g_chiBuffer, pObj->m_cdCurrentCursorPos.X, pObj->m_cdCurrentCursorPos.Y, _code, _attr);
	}
	else if (!strcmp(szTokenBuf[0], "clear"))
	{		
		TGE::clearScreenBuffer(0x2e, 0x0007);
	}
	else if (!strcmp(szTokenBuf[0], "changeBrush"))
	{
		WCHAR _code = (WCHAR)strtol(szTokenBuf[1], NULL, 16);
		WORD _attr = (WORD)strtol(szTokenBuf[2], NULL, 16);
		pObj->m_wCurrentBrushCode = _code;
		pObj->m_wCurrentBrushAttr = _attr;
	}
	else if (!strcmp(szTokenBuf[0], "saveb")) //save 1.map
	{
		TGE::saveBufferBinary(TGE::g_chiBuffer, szTokenBuf[1]);
	}
	else if (!strcmp(szTokenBuf[0], "loadb"))
	{
		TGE::loadBufferBinary(TGE::g_chiBuffer, szTokenBuf[1]);
	}
	else if (!strcmp(szTokenBuf[0], "getSprite"))
	{
		int _xpos = atoi(szTokenBuf[1]);
		int _ypos = atoi(szTokenBuf[1]);
		int _width = atoi(szTokenBuf[1]);
		int _height = atoi(szTokenBuf[1]);
		
		TGE::
	}

	return 1;
}



