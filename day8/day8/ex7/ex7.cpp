// ex7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
// 수업자료참고

#include "stdafx.h"
#include<malloc.h>

int main()
{
	int *ip = NULL;

	ip = (int *)malloc(sizeof(int));
	if (ip != NULL) {
		printf("메모리 할당 성공 \n");
	}
	else {
		printf("메모리부족");
	}
	*ip = 1;

	printf("d%\n", *ip);

    return 0;
}

