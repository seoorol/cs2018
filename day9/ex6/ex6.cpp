// ex6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


enum seaseon{spring=1000 ,summer,fall,winter,rat=2000,cow,tiger,rabit,dragon,snake};

typedef int _BYTE32;


int main()
{
	 _BYTE32 myVal = 100;

	printf("%d \n", myVal);
	
	printf("%d %d %d %d\n", spring, summer, fall, winter);
	printf("%d %d %d %d %d %d\n", rat, cow, tiger, rabit, dragon, snake);


	
    return 0;
}

