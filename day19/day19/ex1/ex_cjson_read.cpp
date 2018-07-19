#include "stdafx.h"

void ex1()
{
	char szBuf[1024] = { 0 };
	FILE *fp;
	fopen_s(&fp, "test.json", "rt");
	fread_s(szBuf, 1024, 1024, 1, fp);
	puts(szBuf);

	cJSON *pRoot = cJSON_Parse(szBuf);

	cJSON *pName = cJSON_GetObjectItemCaseSensitive(pRoot, "name");
	cJSON *pDistance = cJSON_GetObjectItemCaseSensitive(pRoot, "distance");
	cJSON *pNCode = cJSON_GetObjectItemCaseSensitive(pRoot, "national_code");
	cJSON *pComm = cJSON_GetObjectItemCaseSensitive(pRoot, "comm");
	cJSON *pItem = cJSON_GetObjectItemCaseSensitive(pRoot, "item");
	cJSON *pWepon = cJSON_GetObjectItemCaseSensitive(pItem, "wepon");
	

	cJSON *pEtc = cJSON_GetObjectItemCaseSensitive(pRoot, "etc");
	cJSON *pEtc_0 = cJSON_GetArrayItem(pEtc, 0);
	cJSON *pEtc_1 = cJSON_GetArrayItem(pEtc, 1);


	printf("파싱결과 \n");
	printf("%s,%lf %d %d %s \n", pName->valuestring, pDistance->valuedouble, pNCode->valueint, pComm->valueint
		, pWepon->valuestring);
	printf("공격력 %d \n", cJSON_GetObjectItemCaseSensitive(pItem, "ap")->valueint);
	printf("%d \n ", pEtc_0->valueint);
	printf("%s \n ", pEtc_1->valuestring);


	fclose(fp);
}