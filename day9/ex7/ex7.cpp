 // ex7.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


int main()
{

	FILE *fp;
	char ch;

	fopen_s(&fp,"a.txt", "r");
	if (fp == NULL) 
	{
		printf("파일읽기실패 \n");
	}
	else
	{
		while (1)
		{
			ch = fgetc(fp);
			if (ch == EOF)
			{
				break;
			}
			else
			{
				printf("%c", ch);
			}
		}
		printf("\n");

		/*
		ch = fgetc(fp);
		//ch = fgetc(stdin);
		printf("입력한 문자 : %c \n", ch);

		ch = fgetc(fp);
		//ch = fgetc(stdin);
		printf("입력한 문자 : %c \n", ch);
		fclose(fp);
		*/
	}

    return 0;
}

