#pragma once



struct _S_GAMEOBJECT
{
char m_szName[16]; //����ü����
int m_nHp;
};

void CreateObject(_S_GAMEOBJECT **ppObj, const char *pName, int nHp);

void dumpObject(_S_GAMEOBJECT *pObj);

extern int g_dbPi;