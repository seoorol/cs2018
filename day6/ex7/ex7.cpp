// ex7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[5] = { 1,2,3,4,5 };

	int *ap = ary;

	

	printf("%d \n", ary[2]);
	printf("%d \n", ap[2]);
	
	ary[0] = 6;
	//ary = ap + 2;
		printf("%d \n", *(ary + 0));
	

    return 0;
}

