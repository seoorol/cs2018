// ex1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	int num;
	int *ptr;
	num = 3;
	ptr = &num; //주소연산자

	printf("%d %d \n" , num, &num);

	printf("%d %d \n", *ptr , ptr);

	*ptr = 5;
	printf("%d %d \n", *ptr, ptr);
	printf("%d %d \n", num, &num);

	int address;
	
	
	
	scanf_s("%d", &address); //주소입력
	printf("%d %d \n", address , *((int *)address)); //주소의내용보기 / 포인터기본형
	





    return 0;
}

