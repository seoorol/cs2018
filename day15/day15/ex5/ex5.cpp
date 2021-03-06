// ex5.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <Windows.h>

UINT64 GetTimeMs64()
{
	FILETIME ft;
	LARGE_INTEGER li;

	GetSystemTimeAsFileTime(&ft);
	li.LowPart = ft.dwLowDateTime;
	li.HighPart = ft.dwHighDateTime;

	UINT64 ret_value = li.QuadPart;
	ret_value -= 116444736000000000LL;
	ret_value /= 10000;

	return ret_value;

}

int main()
{
	UINT64 start_tick = GetTimeMs64();
	Sleep(500);
	UINT64 end_tick = GetTimeMs64();

	printf_s("%d", end_tick - start_tick);

	return 0;
}