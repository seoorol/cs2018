// ex4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void sum(int a, int b, int *c)
{
	*c = a + b;
	
}

int main()
{
	int c =0 ;
	sum(1, 2, &c);
	printf("%d \n", c);


    return 0;
}

