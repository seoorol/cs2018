// ex2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void str_prn(const char **ptr_ary, int count) //다중포인터
{
	

	for (int i = 0; i < count; i++) {
		printf("%s\n", ptr_ary[i]);
	}
}


int main()
{
	const char *ptr_ary[] = { "eagle", "tiger", "lion", "squirrel" };

	int count;
	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);

	str_prn(ptr_ary, count);

	

    return 0;
}

