// ex4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void count()
{
	static int  a = 0;
	printf("%d \n" , a++);
}

void Dcount()
{
	static int  a = 100;
	printf("%d \n", a--);
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
		else {
			printf("%s는 처리할수없는 명령어입니다\n", szCmdBuf);
		}

		
	}
	printf("프로그램을 종료합니다!\n");

    return 0;
}

