// ex6.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	int ary[5] = { 10,20,30,40,50 };
	int *ap; //포인터변수
	ap = ary;

	for (int i = 0; i < 5; i++) {
		//printf("%d \n", ary[i]);
		//printf("%d \n", &ary[0]+i); //주소값출력
		//printf("%d \n", *(&ary[0] + i));
		//printf("%d \n", *(ary + i));
		printf("%d \n", *(ap + i));
	}

	ap = &ary[2];
	for (int i = 0; i < 3; i++) {
		printf("%d \n", *(ap+i));
	}

    return 0;
}

