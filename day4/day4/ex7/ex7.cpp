// ex7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	int ary[] = {1,3,4,2,5,6,2,2,3,4,5,6,4,5,3,2,4,9}; //초기화
	int find;
	int ct = 0;
	int j = sizeof(ary) / sizeof(ary[0]);
	
	printf("수 :");
	scanf_s("%d" , &find);

	for (int i = 0; i < j; i++) {
		if (find == ary[i])
		{
			ct++;
		}
	}

	printf("%d 는 %d개 있습니다 \n", find, ct);
		
    return 0;
}

