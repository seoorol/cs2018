// ex9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


void dump(char **buf)
{
	for (int i = 0; buf[i] != 0; i++) {
		printf("%s \n", buf[i]);

	}


}

int main()
{

	char szCmdBuf[32];
	char *strBuf[100] = { NULL };

	while (1)
	{
		printf_s("명령어 >");
		gets_s(szCmdBuf, sizeof(szCmdBuf));
		if (strcmp(szCmdBuf, "quit") == 0) {
			int i = 0;
			for (int i = 0; strBuf[i] != 0; i++) {
				free(strBuf[i]);
				strBuf[i] = NULL;
			}
			break;
		}
		else if (strcmp(szCmdBuf, "add") == 0) {
			printf("문자열을 입력하세요 : ");
			gets_s(szCmdBuf, 32);

			int i = 0;
			for (int i = 0; strBuf[i] != 0; i++) {}

			strBuf[i] = (char*)malloc(strlen(szCmdBuf) + 1); //공간확보
			strcpy_s(strBuf[i], strlen(szCmdBuf) + 1, szCmdBuf);
		}
		else if (strcmp(szCmdBuf, "dump") == 0) {
			dump(strBuf);
			
		}
		else if (strcmp(szCmdBuf, "del") == 0) {
						
		}

		
	}
	return 0;
}




