// ex4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "gameobject.h"


/*
struct _S_GAMEOBJECT
{
	char m_szName[16]; //구조체선언
	int m_nHp;
};

void CreateObject(_S_GAMEOBJECT **ppObj, const char *pName, int nHp);

void dumpObject(_S_GAMEOBJECT *pObj);
*/

int main()
{
	_S_GAMEOBJECT *pPlayerObj = NULL;
	CreateObject(&pPlayerObj, "angel", 100);
	dumpObject(pPlayerObj);
	free(pPlayerObj);
	

	printf("%lf \n", g_dbPi);
    return 0;
}

