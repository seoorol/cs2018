// ex5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int g_nCounter = 0;

void count()
{
	printf("%d \n", g_nCounter++);
}

void Dcount()
{
	printf("%d \n", g_nCounter--);
}

void reset()
{
	printf("%d \n", g_nCounter = 0);
}

int main()
{

	printf("명령어 >");
	
	char szCmdBuf[32];

	while (1)
	{
		gets_s(szCmdBuf, sizeof(szCmdBuf));
		if (strcmp(szCmdBuf, "quit") == 0) {
			break;
		}
		else if (strcmp(szCmdBuf, "count") == 0) {
			printf("count는");
			count();
		}
		else if (strcmp(szCmdBuf, "Dcount") == 0) {
			printf("Dcount는");
			Dcount();
		}
		else if (strcmp(szCmdBuf, "reset") == 0) {
			printf("reset 값 ");
			reset();
		}
		else {
			printf("%s는 처리할수없는 명령어입니다\n", szCmdBuf);
		}


	}
	printf("프로그램을 종료합니다!\n");

	return 0;
}

