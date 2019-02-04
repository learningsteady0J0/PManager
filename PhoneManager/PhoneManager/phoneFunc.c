/* Name : phoneFunc.c  ver 1.4
   content : 전화번호 컨트롤 함수
   Implementation : learningsteady0j0

   Last modified 2019/02/04
*/

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData * phoneList[LIST_NUM];

// 함	수 : void InputPhoneData(void)
// 기	능 : 전화번호 관련 데이터 입력 받아서 저장
// 반	환 : void

void InputPhoneData(void)
{
	phoneData data;
	phoneData * alocPhoneList = (phoneData*)malloc(sizeof(phoneData));
	int i;

	if (numOfData > LIST_NUM)
	{
		puts("메모리 공간이 부족합니다.");
		return;
	}

	fputs("이름 입력: ", stdout);
	gets(data.name);
	fputs("전화번호 입력: ", stdout);
	gets(data.phoneNum);
	
	for (i = 0; i < numOfData; i++)
	{
		if (!strcmp(data.name, phoneList[i]->name) && !strcmp(data.phoneNum, phoneList[i]->phoneNum))
		{
			fputs("이미 입력된 데이터 입니다,  ", stdout);
			free(alocPhoneList);   // 구현할 때 까먹었음.. 꼭 기억할 것. 동적메모리할당할 때 항상 염두해둘것.
			ReturnMenu();
			return;
		}
	}

	*alocPhoneList = data;
	phoneList[numOfData] = alocPhoneList;
	numOfData++;

	fputs("입력이 완료되었습니다, ", stdout);
	ReturnMenu();
}

// 함	수 : void ShowAllData(void)
// 기	능 : 저장된 데이터 전체 출력
// 반	환 : void

void ShowAllData(void)
{
	int i;
	char str[NAME_LEN];

	for (i = 0; i < numOfData; i++)
	{
		ShowPhoneInfoByPtr(phoneList[i]);
	}

	fputs("출력이 완료되었습니다, ", stdout);
	ReturnMenu();
}

// 함	수 : void SearchPhoneData(void)
// 기	능 : 이름을 통한 데이터 검색
// 반	환 : void
void SearchPhoneData(void)
{
	char searchName[NAME_LEN];
	int i;
	int count = 0;  //  찾으면 1, 못 찾으면 0

	fputs("찾는 이름은? ",stdout);
	gets(searchName);

	for (i = 0; i < numOfData; i++)
	{
		if (strcmp(searchName, phoneList[i]->name) == 0)
		{
			ShowPhoneInfoByPtr(phoneList[i]);
			count = 1;
		}
	}

	if (count == 0)
	{
		fputs("데이터 정보가 없습니다,  ", stdout);
		ReturnMenu();
	}

	ReturnMenu();
	return;
	
}

// 함	수 : void DeletePhoneData(void)
// 기	능 : 이름을 참조하여 데이터 삭제
// 반	환 : void
void DeletePhoneData(void)
{
	char delName[NAME_LEN];
	int idxOfMattchingData[LIST_NUM];
	int delIdx;
	int count = 0;
	int i, j ,num;

	fputs("찾는 이름은? ", stdout);
	gets(delName);
	for (i = 0; i < numOfData; i++)
	{
		if (!strcmp(delName, phoneList[i]->name))
		{
			idxOfMattchingData[count++]=i;
		}
	}

	if (count == 0)
	{
		fputs("데이터 정보가 없습니다,  ", stdout);
		ReturnMenu();
		return;
	}
	else if (count == 1)
	{
		delIdx = idxOfMattchingData[0];
	}
	else if (count > 1)
	{
		for (i = 0; i < count; i++)
		{
			printf("NUM. %d\n", i + 1);
			ShowPhoneInfoByPtr(phoneList[idxOfMattchingData[i]]);
		}
		fputs("선택: ",stdout);
		scanf("%d", &num);
		getchar();
		delIdx = idxOfMattchingData[num-1];
	}

	free(phoneList[i]);
	for (j = delIdx; j < numOfData - 1; j++)
	{
		phoneList[j] = phoneList[j + 1];
	}

	numOfData--;
	fputs("데이터 삭제 완료,  ", stdout);
	ReturnMenu();
	return;
}

/* end of file */