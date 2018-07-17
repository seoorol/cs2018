// ex13.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <string.h>

int main()
{

	const char *str1 = "apple";
	
	char buf[64];

	strcpy_s(buf, 64, str1);

	printf("%s \n", buf);
	
	printf("%d \n", strnlen_s(buf,sizeof(buf)));

	printf("같은 문자열 일때 : %d \n", strcmp("cat", "cat"));
	printf("다른 문자열 일때 : %d \n", strcmp("cat", "bat")); //알파벳순으로 결과값 출력 max - min = 1
	printf("다른 문자열 일때 : %d \n", strcmp("cat", "dog")); // min - max = -1

	strcat_s(buf, sizeof(buf), "pie"); //buf <= buf+"pie"
	printf("%s \n", buf);


    return 0;
}

