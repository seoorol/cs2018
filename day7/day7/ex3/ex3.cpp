// ex3.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//
//호출시 카운트함수
#include "stdafx.h"

void count()
{
	int a = 0;
	a++;
	printf("%d \n", a);  

}

void count2()
{
	static int a = 0;  //메모리공간에 확보 static 정적메모리공간
	a++;
	printf("%d \n",a );

}

void count3(int *a)
{
	(*a)++; //주소값
	printf("%d \n", *a); 
}

int main()
{

	count();
	count();


	count2();
	count2();
	
	int a = 0;
	count3(&a);
	count3(&a);
	

    return 0;
}

