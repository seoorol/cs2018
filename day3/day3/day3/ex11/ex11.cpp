// ex11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	/*int i = 0;
	while (i < 10) {


		printf("%d\n. " , i);
	i++;
	}
	*/

	int i;
	int j;

	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) {
			printf("%d * %d = %d \n", i, j, i*j);
		}
	}

    return 0;
}

