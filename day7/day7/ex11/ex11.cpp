// ex11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
#include "stdafx.h"

const char *strpWorldArea[32] = {

	"큰방 한가운데 작은 탁자가 놓여있고 북쪽과 서쪽 동쪽에 문이있다",//0번방
	"북쪽에 출구가 보인다. 그렇지만 무섭게 생긴 개가 지키고있다", //1번방
	"작은 정원 같은 곳이다. 누군가 파티를 했던 흔적이 있다. 서쪽방에 개가 좋아할만한 뼈다귀들이 보인다.", //2번방
	"뼈다귀를 주웠다",//3번방
	"뼈다귀를 주었더니 개는 얌전해졌다. 북쪽출구로 나가보니 모든 문이 망가져 열리지 않았다." //4번방

};

int g_nCurrentPos = 0;//0번방 시작
int g_wayTable[32][4] = { //-1 갈수없는곳 //나머지 숫자는 해당 방의 번호

	{ -1,2,-1,1 },   //0번방 // 선택지
	{ -1,-1,0,4 },  //1번방
	{ 0,3,-1,-1 },  //2번방
	{ 2,-1,-1,-1 }, //3번방
	{ -1,-1,5,-1 }, //4번방

};


int main()



{
	char szCmdBuf[32];
	char ch;



	while (1)
	{
		//printf("명령어 : q : 종료 s : 현재상황출력 m : 동서남북지시\n");
		//gets_s(szCmdBuf, sizeof(szCmdBuf));
		ch = _getch();
		if (ch == 'q') {//(strcmp(szCmdBuf, "quit") == 0) {
			printf("게임을 종료합니다 \n");
			break;
		}

		else if (ch == 's') {//(strcmp(szCmdBuf, "see") == 0) {
			printf("%s \n", strpWorldArea[g_nCurrentPos]);
			printf("현재상황 \n 명령어 \n q : 종료 s : 현재상황출력 m : 동서남북지시\n");

		}
		else if (ch == 'm') {//(strcmp(szCmdBuf, "move") == 0) {
			int nDir;
			printf("방향을 입력하세요 동서남북(0,1,2,3) >"); //방번호x 해당 방에서 할 수 있는 선택지
			scanf_s("%d", &nDir);
			printf("명령어 \n q : 종료 s : 현재상황출력 m : 동서남북지시\n");
			int new_pos = g_wayTable[g_nCurrentPos][nDir];
			if (new_pos == -1)
			{
				printf("갈수없습니다.\n");
			}
			else {
				printf("이동합니다.\n");
				g_nCurrentPos = new_pos;
			}


		}

	}

	return 0;

}

