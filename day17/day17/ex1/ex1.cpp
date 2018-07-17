//TGE skeleton 
#include "stdafx.h"
#include "../../../engine/tge.h"
#include "../../../engine/tge_sprite.h"
#include "gameobject.h"

void _loadSprite(tge_sprite::S_SPRITE_OBJECT *spr, const char *szFileName)
{	
	tge_sprite::Init(spr);
	tge_sprite::load(spr, szFileName);
}


int main()
{

	HANDLE hStdout = NULL;
	TGE::startTGE(&hStdout);	
	
	//리소스로딩
	CHAR_INFO *pMapDataBuffer = TGE::CreateScreenBuffer();
	CHAR_INFO *pBakBuffer = TGE::CreateScreenBuffer();
	TGE::loadBufferBinary(pMapDataBuffer, "../../../pub_res/m.map");
	tge_sprite::S_SPRITE_OBJECT sprMiw, sprAilen, sprFire, sprClaw;
	_loadSprite(&sprMiw, "../../../pub_res/c.spr");
	_loadSprite(&sprAilen, "../../../pub_res/a.spr");
	_loadSprite(&sprClaw, "../../../pub_res/cross.spr");
	_loadSprite(&sprFire, "../../../pub_res/f.spr");

	cs2018prj::S_GAMEOBJECT objPlayer, objAilen, objFire, objClaw;

	cs2018prj::playerObject::Init(&objPlayer, irr::core::vector2df(5,7),3,&sprMiw);
	objPlayer.m_bActive = true;
	objPlayer.m_translation = irr::core::vector2df(-1, -3);

	cs2018prj::attackObject::fire::Init(&objFire, irr::core::vector2df(0, 0), 7, &sprFire);
	objFire.m_translation = irr::core::vector2df(-1, -1);

	cs2018prj::ailenObject::Init(&objAilen, irr::core::vector2df(10, 10), 2,  &sprAilen);
	objAilen.m_translation = irr::core::vector2df(-1, -3);
	objAilen.m_nFSM = 10;

	objPlayer.m_pWepon = &objFire;

	cs2018prj::S_GAMEOBJECT *pObjList[1024] = {};
	int nObjectList_index = 0;

	pObjList[nObjectList_index++] = &objPlayer;
	pObjList[nObjectList_index++] = &objAilen;
	pObjList[nObjectList_index++] = &objFire;


	bool _bLoop = true;
	static int _nFSM = 0;
	UINT64 _oldTick = TGE::util::GetTimeMs64();

	while (_bLoop)
	{
		UINT64 _curTick = TGE::util::GetTimeMs64();
		UINT64 _deltaTick = _curTick - _oldTick;
		_oldTick = _curTick;

		double _dbDeltaTick = (double)(_deltaTick) / 1000.0;

		//SetConsoleCursorPosition(hStdout,{ 40, 1 });

		static char szCmdBuf[128];
		//입력 처리 
		switch (_nFSM) {
		case 0:
			if (TGE::input::g_KeyTable[VK_RETURN]) {
				_nFSM = 1;
				TGE::input::setEditMode();
			}
			break;
		case 1: //동기  모드
			TGE::setCursor(hStdout, 0, 0);
			TGE::setCursor(hStdout, 0, 26);
			printf_s("                                                 ]");
			TGE::setCursor(hStdout, 0, 26);
			printf_s("[cmd >");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			_nFSM = 0;
			TGE::input::setNormalMode();
			break;
		}
		//커멘드 처리..
		{
			char szTokenBuf[8][64];
			if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0) {
				if (!strcmp(szTokenBuf[0], "quit")) {
					_bLoop = false;
				}
			}
			szCmdBuf[0] = 0x00;
		}

		//ai
		//cs2018prj::Apply(&testObj, _dbDeltaTick);
		//objPlayer.m_fpApply(&objPlayer, _dbDeltaTick);
		//objFire.m_fpApply(&objFire, _dbDeltaTick);
		//objAilen.m_fpApply(&objAilen, _dbDeltaTick);
		for (int i = 0; i < nObjectList_index; i++)
		{
			pObjList[i]->m_fpApply(pObjList[i], _dbDeltaTick);
		}

		//랜더링 전처리
		//TGE::clearScreenBuffer(pBakBuffer, 0x20, 0x0007);
		//cs2018prj::Render(&testObj, pBakBuffer);
		TGE::copyScreenBuffer(pBakBuffer, pMapDataBuffer);
		
		//objPlayer.m_fpRender(&objPlayer, pBakBuffer);
		//objFire.m_fpRender(&objFire, pBakBuffer);
		//objAilen.m_fpRender(&objAilen, pBakBuffer);
		for (int i = 0; i < nObjectList_index; i++)
		{
			pObjList[i]->m_fpRender(pObjList[i], pBakBuffer);
		}

		//랜더 (화면 갱신)
		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBakBuffer);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	free(pBakBuffer);
	free(pMapDataBuffer);
	free(sprMiw.m_pSpriteBuf);

	TGE::endTGE();

	return 0;

}