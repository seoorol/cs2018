// ex1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ft, mile, f;
	
	printf("\t \t \t 피트, 마일를 입력하세요. ");
	scanf_s("%d %d %d", &ft, &mile, &f);
	printf("\n");
	printf("===============================================\n");
	printf("|                   보고서                    |\n");
	printf("===============================================\n");
	printf("\t %d 피트는%lf cm 입니다.  \n ", ft, ft * 30.48);
	printf("\t %d 마일는 %lf km 입니다.  \n ", mile, mile * 1.609344);
	printf("\t %d 섭씨는 %lf 화씨 입니다.  \n ", f, f * 33.8);

		return 0;
}


//\n \t \r \b \a

