// ex4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	int a, b; // a본봉 b보너스
	//a = 150;
	//b = 60;

	printf("본봉 보너스 입력");
	scanf_s("%d %d" , &a,&b);
	int c = a + b; //총지급
	int d = c * 0.09; //세금


	printf("%lf %d \n", c * 0.09, d);
	
	printf("실지급 : %d \n" , c - d);
	

    return 0;
}

/*
int num,num2;
printf("input -> ");
scanf_s("%d %d", &num,&num2);
printf("result : %d , %d\n", num,num2);
*/