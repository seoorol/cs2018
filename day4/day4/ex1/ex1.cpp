// ex1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int sum(int a, int b)
{
	return a + b;
}
void __b()
{
	printf("it is b\n");
}

void __a()
{
	printf("it is a\n");
}

int main()
{
	int c = sum(2, 3);
	printf("%d\n", c);
	__a();
	__b();
    return 0;
}

