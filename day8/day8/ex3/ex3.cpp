// ex3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	int ar[3][4];

	printf("%d,%d,\n", ar, &ar+1);
    	

	int *ptr = NULL;
	printf("%d,%d,\n", ptr, &ptr);

	return 0;
}

