// ex3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	//int a, b, c, d, e;
	int ages[5];
	int tot;
	double aver;

	tot = 0;

	printf("나이입력\n");
	scanf_s("%d %d %d %d %d", &ages[0], &ages[1], &ages[2], &ages[3], &ages[4]);
	
	//tot = ages[0] + ages[1] + ages[2] + ages[3] + ages[4];

	for (int i = 0; i < 5; i++) { 
		tot += ages[i];
	}
	

	aver = (double)tot / 5;

		printf("평균 : %lf \n", aver);




    return 0;
}

