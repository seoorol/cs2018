// ex6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	int num[4][3] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int num2[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	int i, j;

	{
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 4; j++) {

				printf("%4d", num[j][i]);
			}
			printf("\n");
		}
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			
			printf("%4d", num2[i*4+j]);
		}
		printf("\n");
	}

    return 0;
}

