// ex3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	const double pi = 3.14;
	int num = 0;
	const int *pNumReadOnly = NULL;
	num = 5;
	pNumReadOnly = &num;
	
	
	printf("%.2lf %d \n", pi, *pNumReadOnly);
    
	//pNumReadOnly = 7;
	
	num = 7;
	printf("%d \n", num);
	return 0;
}

