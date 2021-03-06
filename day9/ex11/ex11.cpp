// ex11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

struct _S_GAMEOBJECT //구조체 s
{
	char m_szName[32]; // 문자열 sz 
	int m_nHp;
	int m_nAttack;
	int m_nMp;
	int m_nDep;
};

void parparsePlayerInfo(_S_GAMEOBJECT * pObj, char * szBuf)
{
	const char *deli = " ";
	char *_temp;
	char *pToken;
	pToken = strtok_s(szBuf, deli, &_temp);
	puts(pToken);
	pToken = strtok_s(NULL, deli, &_temp); //이름
										   //puts(pToken);
	strcpy_s(pObj->m_szName, sizeof(pObj->m_szName), pToken);
	pToken = strtok_s(NULL, deli, &_temp); //피
										   //puts(pToken);
	pObj->m_nHp = atoi(pToken); //문자열을 숫자로 바꿔줌
	pToken = strtok_s(NULL, deli, &_temp);  //엠피
											//puts(pToken);
	pObj->m_nMp = atoi(pToken);
	pToken = strtok_s(NULL, deli, &_temp); //어택
										   //puts(pToken);
	pObj->m_nAttack = atoi(pToken);
	pToken = strtok_s(NULL, deli, &_temp); //방어
										   //puts(pToken);
	pObj->m_nDep = atoi(pToken);


}
int main()
{

	char szBuf[128];
	_S_GAMEOBJECT player = { 0 };



	while (1)
	{
		printf("명령어 > ");
		gets_s(szBuf, sizeof(szBuf));
		if (strcmp("quit", szBuf) == 0)
		{
			break;
		}
		else if (strcmp("dump", szBuf) == 0)
		{
			printf("%12s %4d %4d %4d %4d \n", player.m_szName, player.m_nHp, player.m_nMp, player.m_nAttack, player.m_nDep);
		}
		else if(!strncmp("edit", szBuf, 4)) //edit 이름 피 어택 엠피 방어
		{
			parparsePlayerInfo(&player, szBuf);
		}
		else if (!strncmp("save", szBuf, 4))
		{
			FILE *savefile = NULL;
			fopen_s(&savefile , "savefile.txt", "w");
			fprintf_s(savefile, "edit %s %d %d %d %d \n",player.m_szName, player.m_nHp, player.m_nMp, player.m_nAttack, player.m_nDep);
			fclose(savefile);
		}
		else if (strcmp("load", szBuf) == 0)
		{
			FILE *savefile = NULL;
			fopen_s(&savefile, "savefile.txt++", "r");
			
			fgets(szBuf, sizeof(szBuf), savefile);
			parparsePlayerInfo(&player, szBuf);

			fclose(savefile);
		}

	}


    return 0;
}

