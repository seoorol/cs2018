// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	int i[5];
	int max;
	int j;
	int min;

	printf("숫자를 입력하세요\n");
	scanf_s("%d %d %d %d %d", &i[0], &i[1], &i[2], &i[3], &i[4]);
	
	max = i[0];
	min = i[0];

	for (j = 1; j < 5; j++) {
		if (max < i[j]) {
			max = i[j];
		}
		if (min > i[j]) {
			min = i[j];
		}
		//printf("%d \n", i[j]);
	}
	printf("가장 큰 값은  : %d입니다.\n", max);
	printf("가장 작은값은 : %d입니다.\n", min);
	
	    return 0;
}

