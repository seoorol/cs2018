// ex8.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
// 오류

#include "stdafx.h"


int main()
{

	FILE *fp;
	char ch;

	fopen_s(&fp, "b.txt", "w");
	if (fp = NULL)
	{
		printf("파일개방실패.\n");
		return 1;
	}
	printf("데이터를 입력하세요\n");
	
	while (1)
	{
		ch = getchar();
		if (ch == EOF) break;
		fputc(ch, fp);
	}

	fclose(fp);
	return 0;
}

