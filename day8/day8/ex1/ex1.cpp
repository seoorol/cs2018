// ex1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	
	int *ip;
	int **ipp;
	int val = 3;
	ip = &val;
	printf("%d , %d , %d \n", (int)&ip,(int)ip,*ip);
	
    return 0;
}

