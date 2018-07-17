//TGE skeleton 
#include "stdafx.h"
#include "../../../engine/tge.h"
#include "../../../engine/tge_sprite.h"

#include "gameObject.h"

//#include "gameobject.h"
int main()
{

	HANDLE hStdout = NULL;
	TGE::startTGE(&hStdout);

	CHAR_INFO *pBakBuffer = TGE::CreateScreenBuffer();
	CHAR_INFO *pMapDataBuffer = TGE::CreateScreenBuffer();

	//리소스 로딩 
	TGE::loadBufferBinary(pMapDataBuffer, "../../../pub_res/m.map");

	tge_sprite::S_SPRITE_OBJECT sprMainInWhite;
	tge_sprite::Init(&sprMainInWhite);
	tge_sprite::load(&sprMainInWhite, "../../../pub_res/c.spr");

	tge_sprite::S_SPRITE_OBJECT sprAilen;
	tge_sprite::Init(&sprAilen);
	tge_sprite::load(&sprAilen, "../../../pub_res/a.spr");

	tge_sprite::S_SPRITE_OBJECT sprClaw;
	tge_sprite::Init(&sprClaw);
	tge_sprite::load(&sprClaw, "../../../pub_res/cross.spr");

	tge_sprite::S_SPRITE_OBJECT sprFire;
	tge_sprite::Init(&sprFire);
	tge_sprite::load(&sprFire, "../../../pub_res/f.spr");

	//게임 오브잭트 생성 
	cs2018prj::playerObject::S_GAMEOBJECT playerObj;
	cs2018prj::attackObject_claw::S_GAMEOBJECT ailenClaw;
	cs2018prj::ailenObject::S_GAMEOBJECT ailenObj;
	cs2018prj::ailenObject::S_GAMEOBJECT ailenObj2;
	cs2018prj::ailenObject::S_GAMEOBJECT ailenObj3;
	cs2018prj::ailenObject::S_GAMEOBJECT ailenObj4;
	cs2018prj::ailenObject::S_GAMEOBJECT ailenObj5;
	cs2018prj::attackObject_frameBurster::S_GAMEOBJECT fireObj;

	cs2018prj::playerObject::Init(&playerObj, 10, 10, 5, &sprMainInWhite);
	playerObj.m_translation = irr::core::vector2df(-1, -3);
	playerObj.m_pWepon = &fireObj;


	cs2018prj::ailenObject::Init(&ailenObj, 50, 6, 5, &sprAilen);
	ailenObj.m_translation = irr::core::vector2df(-1, -3);
	ailenObj.m_pTargetObj = &playerObj;
	ailenObj.m_pWepon = &ailenClaw;	

	cs2018prj::ailenObject::Init(&ailenObj2, 50,7, 5, &sprAilen);
	ailenObj.m_translation = irr::core::vector2df(-1, -3);
	ailenObj.m_pTargetObj = &playerObj;
	ailenObj.m_pWepon = &ailenClaw;

	cs2018prj::ailenObject::Init(&ailenObj3, 50, 14, 5, &sprAilen);
	ailenObj3.m_translation = irr::core::vector2df(-1, -3);
	ailenObj3.m_pTargetObj = &playerObj;
	ailenObj3.m_pWepon = &ailenClaw;

	cs2018prj::ailenObject::Init(&ailenObj4, 50, 18, 5, &sprAilen);
	ailenObj4.m_translation = irr::core::vector2df(-1, -3);
	ailenObj4.m_pTargetObj = &playerObj;
	ailenObj4.m_pWepon = &ailenClaw;

	cs2018prj::ailenObject::Init(&ailenObj5, 50, 22, 5, &sprAilen);
	ailenObj5.m_translation = irr::core::vector2df(-1, -3);
	ailenObj5.m_pTargetObj = &playerObj;
	ailenObj5.m_pWepon = &ailenClaw;


	cs2018prj::attackObject_claw::Init(&ailenClaw, 50, 8, 5, &sprClaw);
	ailenClaw.m_translation = irr::core::vector2df(-1, -2);
	ailenClaw.m_pTargetObj = &playerObj;

	cs2018prj::attackObject_frameBurster::Init(&fireObj, 0, 0, 10, &sprFire);
	fireObj.m_translation = irr::core::vector2df(-1, -1);
	fireObj.m_pTargetObj = &ailenObj;

	bool _bLoop = true;
	static int _nFSM = 0;
	UINT64 _oldTick = TGE::util::GetTimeMs64();

	while (_bLoop)
	{
		UINT64 _curTick = TGE::util::GetTimeMs64();
		UINT64 _deltaTick = _curTick - _oldTick;
		_oldTick = _curTick;

		double _dbDeltaTick = (double)(_deltaTick) / 1000.0;

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
			TGE::input::g_KeyTable[VK_RETURN] = 0;
			_oldTick = TGE::util::GetTimeMs64();

			break;
		}
		//커멘드 처리..
		{
			char szTokenBuf[8][64];
			if (TGE::doTokenize(szCmdBuf, szTokenBuf) > 0) {
				if (!strcmp(szTokenBuf[0], "quit")) {
					_bLoop = false;
				}
				else if (!strcmp(szTokenBuf[0], "claw")) {
					ailenClaw.m_nFSM = 10; //wakeup
					ailenClaw.m_posx = atoi(szTokenBuf[1]);
					ailenClaw.m_posy = atoi(szTokenBuf[2]);

				}
				else if (!strcmp(szTokenBuf[0], "fire")) {
					fireObj.m_nFSM = 10; //wakeup
					fireObj.m_posx = playerObj.m_posx;
					fireObj.m_posy = playerObj.m_posy - 2;
					fireObj.m_pTargetObj = &ailenObj;
				}
			}
			szCmdBuf[0] = 0x00;
		}

		//ai
		cs2018prj::playerObject::Apply(&playerObj, _dbDeltaTick);
		cs2018prj::ailenObject::Apply(&ailenObj, _dbDeltaTick);
		cs2018prj::ailenObject::Apply(&ailenObj2, _dbDeltaTick);
		cs2018prj::ailenObject::Apply(&ailenObj3, _dbDeltaTick);
		cs2018prj::ailenObject::Apply(&ailenObj4, _dbDeltaTick);
		cs2018prj::ailenObject::Apply(&ailenObj5, _dbDeltaTick);
		cs2018prj::attackObject_claw::Apply(&ailenClaw, _dbDeltaTick);
		cs2018prj::attackObject_frameBurster::Apply(&fireObj, _dbDeltaTick);

		//랜더링 전처리
		TGE::copyScreenBuffer(pBakBuffer, pMapDataBuffer);
		cs2018prj::playerObject::Render(&playerObj, pBakBuffer);
		cs2018prj::ailenObject::Render(&ailenObj, pBakBuffer);
		cs2018prj::ailenObject::Render(&ailenObj2, pBakBuffer);
		cs2018prj::ailenObject::Render(&ailenObj3, pBakBuffer);
		cs2018prj::ailenObject::Render(&ailenObj4, pBakBuffer);
		cs2018prj::ailenObject::Render(&ailenObj5, pBakBuffer);
		cs2018prj::attackObject_claw::Render(&ailenClaw, pBakBuffer);
		cs2018prj::attackObject_frameBurster::Render(&fireObj, pBakBuffer);

		//랜더 (화면 갱신)
		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBakBuffer);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	free(pBakBuffer);
	free(pMapDataBuffer);

	tge_sprite::Release(&sprMainInWhite);
	tge_sprite::Release(&sprAilen);
	tge_sprite::Release(&sprClaw);
	//free(sprAilen.m_pSpriteBuf);
	//free(sprMainInWhite.m_pSpriteBuf);
	//free(sprClaw.m_pSpriteBuf);

	TGE::endTGE();

	return 0;

}