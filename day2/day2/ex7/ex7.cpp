// ex7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	
	char string[5] = "한글";
	//string[5];
	//string = "한글";
		
	printf("%s \n", string);

	scanf_s("%s", string);
	printf("%s \n", string);
    return 0;
}

