// ex1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char ch;
	printf("getchar 로 입력 :");
	ch = getchar();
	putchar(ch);

	//printf("getch 로 입력 \n");
	//ch = _getch();
	//putchar(ch);

	printf("추가적인 스트림 : \n");
	ch = getchar();
	putchar(ch);
	

    return 0;
}

