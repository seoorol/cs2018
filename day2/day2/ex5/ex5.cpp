// ex5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	
	double fuse; //사용량
	double ftotal; //총사용량
	
	printf("사용량입력");
	scanf_s("%lf", &fuse);
	
	int a; //기본요금
	double b; //k당요금
	a = 660;
	b = 88.5;
	ftotal = a + fuse * b;
	double t; 
	t = ftotal * 0.09;
	
	printf("요금 : %lf \n" , ftotal - t);
	
    



    return 0;
}

/*
int a, b; // a본봉 b보너스
//a = 150;
//b = 60;

printf("본봉 보너스 입력");
scanf_s("%d %d" , &a,&b);
int c = a + b; //총지급
int d = c * 0.09; //세금


printf("%lf %d \n", c * 0.09, d);

printf("실지급 : %d \n" , c - d);


return 0;*/