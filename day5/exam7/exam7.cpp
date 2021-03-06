// exam7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>
// simple REPL 기본형

char cTileMap[64] = {
	1,1,1,1,1,1,1,1,//0
	1,0,0,0,0,0,0,1,//1
	1,0,0,0,0,0,0,1,//2
	1,0,0,0,0,0,0,1,//3
	1,1,1,0,0,0,0,1,//4
	1,0,0,0,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

//플레이어 오브잭트 
int g_nPlayerPosX,g_nPlayerPosY;

int main()
{
	g_nPlayerPosX = 3;
	g_nPlayerPosY = 3;

	char szCmd[32];
	while (1) {
		printf_s("명령어 >");
		scanf_s("%s", &szCmd, sizeof(szCmd));

		if (strcmp("quit", szCmd) == 0) {
			printf_s("프로그램을 종료 합니다.");
			break;
		}
		else if (strcmp("move", szCmd) == 0) {
			{char _; scanf_s("%c", &_, 1);} //clear console buffer
			printf_s("방향을 입력하세요 : ");
			char _;
			scanf_s("%c", &_, 1);
			if (_ == 'n') {
				g_nPlayerPosY--;
			}
			else if (_ == 'e') {
				g_nPlayerPosX++;
			}
			else if (_ == 'w') {
				g_nPlayerPosX--;
			}
			else if (_ == 's') {
				g_nPlayerPosY++;
			}
			printf_s("플레이어가 %c쪽으로 이동했습니다.\n", _);
		}
		else if (strcmp("dump", szCmd) == 0) {
			
			//cTileMap[g_nPlayerPosX + g_nPlayerPosY * 8] = 9;
			char _tempBuf[64];

			for (int i = 0; i < 64; i++) {
				_tempBuf[i] = cTileMap[i];
			}
			//플레이어 출력
			_tempBuf[g_nPlayerPosX + g_nPlayerPosY * 8] = 9;

			for (int y = 0; y < 8; y++)
			{
				for (int x = 0; x < 8; x++)
				{
					printf_s("%d", _tempBuf[x + y * 8]);
				}
				printf_s("\n");
			}
		}
		else {
			printf_s("입력 하신 커멘드는 : %s 입니다.\n ", szCmd);
		}
	}

	return 0;
}