// ex11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char *fruit = (char *)"strawberry";
	char fruit2[] = "strawbetty";
	const char *fruit = "strawberry";
	


	printf("%s \n", fruit);

	printf("%s \n", fruit+2);
	printf("%s \n", &fruit[2]);

	fruit2[3] = 'O';

	printf("%s \n", fruit2);

	


    return 0;
}

