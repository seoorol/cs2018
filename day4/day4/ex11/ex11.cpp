// ex11.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[32];


	printf("문자입력 : ");
	scanf_s("%s", &word, sizeof(word));
	printf("입력한 문자열 : %s \n", word);
	int size = sizeof(word) / sizeof(word[0]);
	int leg = 0;



	for (int i = 0; i < size; i++) {
		if (word[i] == 0x00) break;
		leg++;
	}

	printf("문자열크기 : %d \n", leg);

	for (int i = 0; i < leg/2; i++){
		char _temp;
		_temp = word[i];
		word[i] = word[(leg - i) - i];
		word[(leg - i) - i] = _temp;
		}

	printf("결과 :%d \n", word);
	
	return 0;
}


