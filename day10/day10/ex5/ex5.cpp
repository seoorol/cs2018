// ex5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


void outputdec2Bin(int nDec)
{

	unsigned int a = 0x8000000;
	
	for (int i = 0; i < 32; i++)
	{
		if (nDec&a)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		a = a << 1;

	}



}

int main()
{

	char a =1 ;
	char b = 2;
	char c = 4;
	char d = 8;
	

	char e = a | b | c | d;
	printf("%d %x \n", e, e);

	

	e = 9;
	for (int i = 0; i < 4; i++)
	{
		if (e&a)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		a = a << 1;

	}

	char _e = b ^ c;

	printf("%d \n", _e);

	char k = 1;
	for (int i = 0; i < 5; i++) {
		k = k ^ 1;
		printf_s("%d \n", k);
	}
	
	outputdec2Bin(968);

    return 0;

}

