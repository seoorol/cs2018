// ex10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int i;
	i = 0;
	while (i <= 100) {
		printf("%d\n", i);
		//i = i++;
		//i = i + 1;
		i += 5; //증감
	}

	i = 0;
	while (i <= 50)
	{
		printf("-");
		i++;
	}

	printf("\n");

	i = 100;
	while (i >= 0) {
		printf("%d \n", i);
		i = i--;
	}

	i = 0;
	while (i <= 100) {
		if ((i % 2) == 0) {
			printf("짝 %d \n", i);
		}
		else {
			printf("홀 %d \n", i);
		}
		i++;
	}
	
	int sum;
	i = 0;
	sum = 0;

	while (i <= 100) {
		if ((i%3) == 0) {
			printf("배수 : %d \n", i);
			sum += i;
			
			printf("합 : %d  \n", sum);
		}
		
		i++;
		
	}

    return 0;
}

