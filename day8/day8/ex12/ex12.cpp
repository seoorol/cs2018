// ex12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <malloc.h>
#include <string.h>

int main()
{

	const char *szMsg = "hello world";
	char *pTemp;  

	pTemp = (char *)malloc(7);
	strcpy_s(pTemp, strlen(szMsg) +1, szMsg);  

	memcpy(pTemp, szMsg+4, 7); //선택한 갯수만 출력
	pTemp[6] = 0x00;
	printf("%s \n", pTemp);

    return 0;
}

