// ex6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	/*printf("%d \n", 10 > 20);
	printf("%d \n", 10 < 20);


	int num;
	scanf_s("%d", &num);

	if (num < 0) {
		num = num * -1;
	}
     
	printf("absolute => %d \n", num);
	*/
	int a;
	printf("나이를 입력하세요 : \n") ;
	scanf_s("%d \n", &a);
	if (a <= 6 || a >= 70) {
		printf("무료\n");
	}
	else{
		printf("3000원입니다\n");
	}
		
	
	return 0;
	
}

