// ex4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	int nKor, nEng, nMath;
	
	printf("국어 영어 수학 점수를 차례로 입력하세요");
    scanf_s("%d %d %d", &nKor, &nEng, &nMath);
	
	printf(":---------:--------:--------:--------:--------:----------:\n");
	printf(":%6s %8s %8s %8s %8s %10s \n" , "이름" , "국어", "영어", "수학", "총점", "평균" );
	printf(":---------:--------:--------:--------:--------:----------:\n");
	printf(":%-10s %7d %8d %8d %8d %10.2lf \n", "SEO", nKor , nEng , nMath , nKor+nEng+nMath , (double)(nKor + nEng + nMath)/3);
	printf(":---------:--------:--------:--------:--------:----------:\n");
    return 0;
}

