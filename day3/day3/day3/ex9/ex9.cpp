// ex9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int nHeight = 0;
	int ndays = 0;
	
	
	do {
		printf("%d 일째 %d cm 등판완료 \n", ndays, nHeight);
		nHeight = nHeight + 55;
		ndays = ndays + 1;
	} while (nHeight < 300);

	nHeight = 0;

	while (nHeight < 300) {
		printf("%d 일째 %d cm 등판완료 \n", ndays, nHeight);
		nHeight = nHeight + 55;
		ndays = ndays + 1;
	}

	printf("끝");

    return 0;
}

