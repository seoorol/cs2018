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
	TGE::loadBufferBinary(pMapDataBuffer, "../../../pub_res/2.map");

	tge_sprite::S_SPRITE_OBJECT sprMainInWhite;
	tge_sprite::Init(&sprMainInWhite);
	tge_sprite::load(&sprMainInWhite, "../../../pub_res/sa.spr");


	tge_sprite::S_SPRITE_OBJECT sprmap;
	tge_sprite::Init(&sprmap);
	tge_sprite::load(&sprmap, "../../../pub_res/trap.spr");

	tge_sprite::S_SPRITE_OBJECT sprmap1;
	tge_sprite::Init(&sprmap1);
	tge_sprite::load(&sprmap1, "../../../pub_res/trap.spr");

	tge_sprite::S_SPRITE_OBJECT sprAilen;
	tge_sprite::Init(&sprAilen);
	tge_sprite::load(&sprAilen, "../../../pub_res/d.spr");

	tge_sprite::S_SPRITE_OBJECT sprAilen1;
	tge_sprite::Init(&sprAilen1);
	tge_sprite::load(&sprAilen1, "../../../pub_res/dog.spr");

	tge_sprite::S_SPRITE_OBJECT sprAilen2;
	tge_sprite::Init(&sprAilen2);
	tge_sprite::load(&sprAilen2, "../../../pub_res/d2.spr");

	tge_sprite::S_SPRITE_OBJECT sprAilen3;
	tge_sprite::Init(&sprAilen3);
	tge_sprite::load(&sprAilen3, "../../../pub_res/face.spr");

	tge_sprite::S_SPRITE_OBJECT sprClaw;
	tge_sprite::Init(&sprClaw);
	tge_sprite::load(&sprClaw, "../../../pub_res/over.spr");

	tge_sprite::S_SPRITE_OBJECT sprFire;
	tge_sprite::Init(&sprFire);
	tge_sprite::load(&sprFire, "../../../pub_res/f.spr");

	tge_sprite::S_SPRITE_OBJECT sprpoison;
	tge_sprite::Init(&sprpoison);
	tge_sprite::load(&sprpoison, "../../../pub_res/poison.spr");

	//게임 오브잭트 생성 
	cs2018prj::playerObject::S_GAMEOBJECT playerObj;
	cs2018prj::attackObject_claw::S_GAMEOBJECT ailenClaw;

	cs2018prj::ailenObject::S_GAMEOBJECT ailenObjs[5];
	cs2018prj::mapObject::S_GAMEOBJECT mapObjs[5];
	/*
	cs2018prj::ailenObject::S_GAMEOBJECT ailenObj;
	cs2018prj::ailenObject::S_GAMEOBJECT ailenObj2;
	cs2018prj::ailenObject::S_GAMEOBJECT ailenObj3;
	cs2018prj::ailenObject::S_GAMEOBJECT ailenObj4;	
	*/




	cs2018prj::attackObject_frameBurster::S_GAMEOBJECT fireObj;
	cs2018prj::attackObject_poison::S_GAMEOBJECT poisonObj;

	cs2018prj::playerObject::Init(&playerObj, 3, 4, 10, &sprMainInWhite);
	playerObj.m_translation = irr::core::vector2df(-1, -3);
	playerObj.m_pWepon = &fireObj, &poisonObj;

	cs2018prj::mapObject::Init(&mapObjs[0], 2, 13, 4, &sprmap);
	mapObjs[0].m_translation = irr::core::vector2df(0, 0);
	

	cs2018prj::mapObject::Init(&mapObjs[1], 72, 2, 3, &sprmap1);
	mapObjs[1].m_translation = irr::core::vector2df(0, 0);
	
	cs2018prj::ailenObject::Init(&ailenObjs[0], 30, 2, 10, &sprAilen);
	ailenObjs[0].m_translation = irr::core::vector2df(-1, -1);
	ailenObjs[0].m_pTargetObj = &playerObj;
	ailenObjs[0].m_pWepon = &ailenClaw;

	cs2018prj::ailenObject::Init(&ailenObjs[1], 20,8, 9, &sprAilen1);
	ailenObjs[1].m_translation = irr::core::vector2df(-1, -1);
	ailenObjs[1].m_pTargetObj = &playerObj;
	ailenObjs[1].m_pWepon = &ailenClaw;

	cs2018prj::ailenObject::Init(&ailenObjs[2], 10, 14, 20, &sprAilen2);
	ailenObjs[2].m_translation = irr::core::vector2df(-1, -1);
	ailenObjs[2].m_pTargetObj = &playerObj;
	ailenObjs[2].m_pWepon = &ailenClaw;

	cs2018prj::ailenObject::Init(&ailenObjs[3], 9, 20, 9, &sprAilen3);
	ailenObjs[3].m_translation = irr::core::vector2df(-1, -1);
	ailenObjs[3].m_pTargetObj = &playerObj;
	ailenObjs[3].m_pWepon = &ailenClaw;


	cs2018prj::attackObject_claw::Init(&ailenClaw, 50, 8, 5, &sprClaw);
	ailenClaw.m_translation = irr::core::vector2df(-1, -2);
	ailenClaw.m_pTargetObj = &playerObj;

	cs2018prj::attackObject_frameBurster::Init(&fireObj, 0, 0, 10, &sprFire);
	fireObj.m_translation = irr::core::vector2df(-1, -1);
	fireObj.m_pTargetObj = ailenObjs;// , &ailenObj2, &ailenObj3, &ailenObj4;

	cs2018prj::attackObject_poison::Init(&poisonObj, 0, 0, 10, &sprpoison);
	poisonObj.m_translation = irr::core::vector2df(-1, -1);
	poisonObj.m_pTargetObj = ailenObjs;// , &ailenObj2, &ailenObj3, &ailenObj4;

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
					fireObj.m_pTargetObj = &ailenObjs;
					fireObj.m_pTargetObj = &mapObjs;
				}
				else if (!strcmp(szTokenBuf[0], "poison")) {
					poisonObj.m_nFSM = 10; //wakeup
					poisonObj.m_posx = playerObj.m_posx;
					poisonObj.m_posy = playerObj.m_posy - 2;
					poisonObj.m_pTargetObj = &playerObj;
				}
				else if (!strcmp(szTokenBuf[0], "changemap")) {
					TGE::loadBufferBinary(pMapDataBuffer, "../../../pub_res/1.map");
				}
			}
			szCmdBuf[0] = 0x00;
		}

		//ai
		cs2018prj::playerObject::Apply(&playerObj, _dbDeltaTick);
		cs2018prj::ailenObject::Apply(&ailenObjs[0], _dbDeltaTick);
		cs2018prj::ailenObject::Apply(&ailenObjs[1], _dbDeltaTick);
		cs2018prj::ailenObject::Apply(&ailenObjs[2], _dbDeltaTick);
		cs2018prj::ailenObject::Apply(&ailenObjs[3], _dbDeltaTick);		
		cs2018prj::attackObject_claw::Apply(&ailenClaw, _dbDeltaTick);
		cs2018prj::attackObject_frameBurster::Apply(&fireObj, _dbDeltaTick);
		cs2018prj::attackObject_poison::Apply(&poisonObj, _dbDeltaTick);
		cs2018prj::mapObject::Apply(&mapObjs[0], _dbDeltaTick);
		cs2018prj::mapObject::Apply(&mapObjs[1], _dbDeltaTick);

		//랜더링 전처리
		TGE::copyScreenBuffer(pBakBuffer, pMapDataBuffer);
		cs2018prj::playerObject::Render(&playerObj, pBakBuffer);
		cs2018prj::ailenObject::Render(&ailenObjs[0], pBakBuffer);
		cs2018prj::ailenObject::Render(&ailenObjs[1], pBakBuffer);
		cs2018prj::ailenObject::Render(&ailenObjs[2], pBakBuffer);
		cs2018prj::ailenObject::Render(&ailenObjs[3], pBakBuffer);
		cs2018prj::attackObject_claw::Render(&ailenClaw, pBakBuffer);
		cs2018prj::attackObject_frameBurster::Render(&fireObj, pBakBuffer);
		cs2018prj::attackObject_poison::Render(&poisonObj, pBakBuffer);
		cs2018prj::mapObject::Render(&mapObjs[0], pBakBuffer);
		cs2018prj::mapObject::Render(&mapObjs[1], pBakBuffer);

		//랜더 (화면 갱신)
		TGE::copyScreenBuffer(TGE::g_chiBuffer, pBakBuffer);
		TGE::updateBuffer(hStdout, TGE::g_chiBuffer);
	}

	free(pBakBuffer);
	free(pMapDataBuffer);

	tge_sprite::Release(&sprMainInWhite);
	tge_sprite::Release(&sprAilen);
	tge_sprite::Release(&sprClaw);
	tge_sprite::Release(&sprFire);
	tge_sprite::Release(&sprpoison);
	tge_sprite::Release(&sprmap);
	//free(sprAilen.m_pSpriteBuf);
	//free(sprMainInWhite.m_pSpriteBuf);
	//free(sprClaw.m_pSpriteBuf);
	
	TGE::endTGE();

	return 0;

}