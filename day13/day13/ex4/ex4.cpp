// ex4.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "../../../engine/duktape/duktape.h"





static duk_ret_t test_print(duk_context *ctx)
{

	printf("hello duktape \n");
	return 0;
}

int main()
{

	duk_context * pMainCtx = duk_create_heap_default(); //스크립트해석기

	duk_eval_string(pMainCtx, "1+2");

	int result = duk_get_int(pMainCtx, -1);

	printf("1+2 = %d \n", result);

	duk_push_c_function(pMainCtx, test_print, 0);

	duk_put_global_string(pMainCtx, "print");

	duk_eval_string_noresult(pMainCtx, "print();");


	duk_destroy_heap(pMainCtx);
	return 0;
}

