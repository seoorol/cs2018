// ex8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "malloc.h"

int main()
{

	int *pa;
	pa = (int *)malloc(5* sizeof(int));

	for (int i = 0; i < 5; i++) {
		//scanf_s("%d", pa[i]);
		scanf_s("%d", (pa + i));
	}

	for (int i = 0; i < 5; i++) {
		//printf("%5d", *(pa + i));
		printf("%5d", pa[i]);
	}

	printf("\n");

    return 0;
}

