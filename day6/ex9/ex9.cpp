// ex9.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

double ary_prn(double *min, int L) {

	double _m = 99999;
	for (int i = 0; i < L; i++) {
		if (_m > min[i]) {
			_m = min[i];
		}
		
	}
	return _m;
}

double ary_prnM(double *max, int L) {
	double _max = -99999;

	for (int i = 0; i < L; i++) {
		if (_max < max[i]) {
			(_max = max[i]);
		}

	}
	return _max;
}

	
int main()
{
	double ary[] = { 1.5, 20.1, 16.4 , 2.3 , 3.5 , 60.5 , 10.1 , 0.4 };
	

	printf("최소값 : %.2lf \n", ary_prn(ary, sizeof(ary)/sizeof(double)) );
	
	printf("최대값 : %.2lf \n ", ary_prnM(ary, sizeof(ary) / sizeof(double)) );

    return 0;
}

