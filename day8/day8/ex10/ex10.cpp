// ex10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main(int argc, char **argv)
{
	printf("인자수는 : %d\n", argc);

	for (int i = 0; i < argc; i++) {
		
		printf("%s \n", argv[i]);
	}

    return 0;
}

