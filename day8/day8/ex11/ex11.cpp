// ex11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//문자열 끊어내는함수

#include "stdafx.h"
#include <string.h>


int main()
{

char strMsg[] = "move east and move north set 3,4";
	char *pTemp = NULL;
	const char *pszDelimitor = " ,";


		char *pToken = strtok_s((char *)strMsg, " ," , &pTemp);
		
		while (pToken)
		{
			
			pToken = strtok_s(NULL, pszDelimitor, &pTemp);
			if (pToken == NULL) break;
			printf("%s \n", pToken);
		}

    return 0;
}

