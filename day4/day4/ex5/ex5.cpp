// ex5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

void printArray(int nums[])
{
	for (int i = 0; i < 5; i++) {
		printf("%d", nums[i]);
	}
		printf("\n");
	

}
int main()
{

	int nums[5];
	int i = 0;
	int _nums[] = { 3,4,5,6,7 };

	for(int i = 0; i < 5; i++); {
		scanf_s("%d", &nums[i]);
	
	}
	printArray(nums);
	printArray(_nums);

	return 0;
}

