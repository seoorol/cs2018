// ex4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"


struct profile
{
	char name[20];
	double grade;
	int english;
};

void input_data(profile *pStaff) //구조체에대한 포인터를 넘겨준다
{
		
	for (int i = 0; i < 5; i++)
	{
		//scanf_s("%s %lf %d", &pStaff[i].name,20, &(pStaff[i].grade), &(pStaff[i].english));
		scanf_s("%s %lf %d", &pStaff->name, 20, &(pStaff->grade), &(pStaff->english));
	}
	

}

void elite(profile *pStaff) 
{
	profile *pMax;
	pMax = &(pStaff[0]);
	for (int i = 0; i <5; i++)
	{
		if (pMax->english < pStaff[i].english  ) 
		{
			pMax = &(pStaff[i]);

		}
	
	}
	printf("elite is %s \n", pMax->name);

}



int main()
{
	struct profile new_staff[5]; 
	printf("이름, 학점, 영어점수를 입력하세요\n");


	input_data(new_staff);
	elite(new_staff);

    return 0;
}

