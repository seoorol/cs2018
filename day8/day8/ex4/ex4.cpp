// ex4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

const char pro[5][80];



	

		
	int main()
	{
		char szaBut[5][80];

		for (int i = 0; i < 5; i++) {
			gets_s(szaBut[i], 80);
		}

		for (int i = 0; i < 5; i++) {
			printf("%s\n", szaBut[i]);
				
		}
	

	

    return 0;

}

