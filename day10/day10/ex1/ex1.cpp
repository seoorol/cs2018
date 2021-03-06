// ex1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "gameobject.h"

void CreateObject(_S_GAMEOBJECT **ppObj, const char *pName, int nHp) //문자열 const
{
	*ppObj = (_S_GAMEOBJECT *)malloc(sizeof(_S_GAMEOBJECT));
	(*ppObj)->m_nHp = nHp;
	strcpy_s((*ppObj)->m_szName, sizeof((*ppObj)->m_szName), pName);

}

void dumpObject(_S_GAMEOBJECT *pObj)
{
	printf("%16s %4d\n", pObj->m_szName, pObj->m_nHp);

}

int main()
{

	_S_GAMEOBJECT *pPlayerObj = NULL;

	CreateObject(&pPlayerObj,"noname",100);
	dumpObject(pPlayerObj);

	free(pPlayerObj);

    return 0;
}

