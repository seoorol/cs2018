// ex6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int a, b;
	int min;

	scanf_s("%d %d", &a, &b);
	(a > b) ? printf("a가 커요\n") : printf("b가 커요\n");
	
	//printf("%d %d", a, b);
    return 0;
}

