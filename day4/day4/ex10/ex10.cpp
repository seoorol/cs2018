// ex10.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

//별표만들기
int main()
{
	char word[32];

	printf("문자입력 : ");
	scanf_s("%s", word, sizeof(word));
	printf("입력한 문자열 : %s \n", word);

	int size = sizeof(word) / sizeof(word[0]);

	for (int i = 0; i < size; i++) {
		if (word[i] == 0x00) break;
		if ((word[i] >= 65 && word[i] <= 90) || //대
			(word[i] >= 97 && word[i] <= 122)	//소
			)   

		{
			word[i] = ('*');
		}

	}

	printf("%s \n", word);



    return 0;
}

