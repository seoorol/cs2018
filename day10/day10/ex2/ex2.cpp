// ex2.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#define _PI 3.141592
const double __PI = 3.141592;
#define SUM(x,y) x+y

#define _MY_TEST

int main()
{

	printf("%lf \n", _PI);
	printf("%lf \n", __PI);
	printf("%lf %d %lf \n", _PI, SUM(3, 4), SUM(3.4,6.5));

#ifdef _MY_TEST
	printf("hello define\n");
#elif _MY_TEST2
	printf("hello test2 define\n"); //속성> or 명령줄추가옵션에 /D "_MY_TEST2
#else
	printf("hello not define\n");

#endif
	
	return 0;
}

