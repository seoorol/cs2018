// ex2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	printf(" \x41 \n ");

	printf("☎ \n");

	printf("부호 : %d, 부호없음 : %u \n", -1, -1);

	printf("10 : %d, 8 : %o, 16 : %x  \n", 16, 16, 16);

	printf(" %x  \n", '□'); //16진수
	
	printf("pi : %lf ,%le \n", 3.1415926, 3.1415926);

	double _val = 0.0000001;

	printf("pi : %lf ,%le \n", _val, _val);
	
	printf("%c %s \n", 'H', "Hello");
	
	//나눗셈
	int a , b;
	printf("두 정수를 입력하세요 : \n");
	scanf_s("%d %d" , &a, &b);
	printf("나눗셈 연삭식은 %d / %d = %lf 입니다. \n ",  a, b , (double)a/b );
	
	//아스키코드
	int c;
	printf(" A = \n");
	scanf_s(" %d", &c);
	printf(" A = %c \n" , c);
	
	return 0;
}

