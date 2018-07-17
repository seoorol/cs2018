// ex5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void foo()
{
	printf("i'm foo\n");
}

void bar()
{
	printf("i'm bar\n");
}

int main()
{

	void(*fp)(); //반환값,인자값이 없는 포인터
	fp = foo;
	fp();

	fp = bar;
	fp();

    return 0;
}

