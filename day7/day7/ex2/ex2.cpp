// ex2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
//자동변수

int main()
{
	int a = 1;
	{
		int a = 2;
		printf("%d \n", a);
	}
	{
		int a = 3;
		printf("%d \n", a);
	}

	printf("%d \n", a);

    return 0;
}

