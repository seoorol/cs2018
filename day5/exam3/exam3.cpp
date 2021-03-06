// exam3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"
#include <string.h>
// simple REPL 기본형
int main()
{
	char szCmd[32];
	char cBufStack[256];
	int nStackPointer = 0;

	while (1) {
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0) {
			printf_s("프로그램을 종료 합니다.");
			break;
		}
		else if (strcmp("push", szCmd) == 0) { 
			printf_s("데이터를 입력하세요 :");
			char _tmp;
			scanf_s("%c",&_tmp,1);
			scanf_s("%c", &_tmp, 1);
			printf_s("입력값 : %c \n",_tmp);
			cBufStack[nStackPointer] = _tmp;
			nStackPointer++;
		}
		else if (strcmp("pop", szCmd) == 0) {
			nStackPointer--;
			printf_s("성공적으로 팝 했습니다 스택포인터 위치는 (%d) 입니다.\n", nStackPointer);
		}
		else if (strcmp("dump", szCmd) == 0) {
			//cBufStack[nStackPointer] = 0x00;
			//printf_s("%s\n", cBufStack);

			for (int i = 0; i < nStackPointer; i++) {
				printf_s("%c", cBufStack[i]);
			}
			printf_s("\n");
			
		}
		else {
			printf_s("입력 하신 커멘드는 : %s 입니다.\n ", szCmd);
		}
	}

	return 0;
}
