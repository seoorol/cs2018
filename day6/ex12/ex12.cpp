// ex12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void user_strcpy(char *des, const char*src)
{
	while (*src != '\0') {
		*des = *src;
		src++; des++;
	}
	*des = 0x00;
}

int main()
{

	char str[80];
	user_strcpy(str, "strawberry");
	//str = "strawberry";

	printf("%s \n", str);

    return 0;
}

