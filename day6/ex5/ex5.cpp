// ex5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	
	char ch;
	int in;
	double db;

	printf("Ch : %d\n", sizeof(&ch));
	printf("int : %d\n", sizeof(&in));
	printf("db : %d\n ", sizeof(&db));

    return 0;
}

