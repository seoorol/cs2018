// ex9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{
	char word[32];
	int c = 0;
	int cta = 0;
	int size = sizeof(word) / sizeof(word[0]);

	printf("문자입력 : ");
	scanf_s("%s", &word, sizeof(word));
	printf("입력한 문자열 : %s \n", word);

	for (int i = 0; i < size; i++) {
			if (word[i] == 0x00) {
				break;
				}
			if ((word[i] >= 65 && word[i] <= 90) || //대
				(word[i] >= 97 && word[i] <= 122)   //소
				)
			{
				cta++;
		    }
		c++;
	}


	printf("입력만 문자갯수 : %d\n", c);
	printf("입력한 알파벳숫자 : %d\n", cta);

    return 0;
}

