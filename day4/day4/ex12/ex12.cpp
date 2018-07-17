// ex12.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
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
	
	printf("문자열크기 : %d \n" ,leg);
	int nFSM = 0; // 0-> normal, 1 = star
	for (int i = 0; i < leg; i++) {
		
		if(nFSM == 0){
			if (word[i] == '@') nFSM = 1;
			printf("%c", word[i]);
		}
		else if (nFSM == 1) {
			if (word[i] == '@') nFSM = 0;
			printf("*");
			if (word[i] == '@') 
				printf("%c", word[i]);
			//if (word[i] == '@') 
				//printf("%c", word[i]);
		}
				
	}
	printf("\n");
	return 0;
}

