/* Name : phoneFunc.c  ver 1.2
   content : 전화번호 컨트롤 함수
   Implementation : learningsteady0j0

   Last modified 2019/02/04
*/

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData phoneList[LIST_NUM];

// 함	수 : void InputPhoneData(void)
// 기	능 : 전화번호 관련 데이터 입력 받아서 저장
// 반	환 : void

void InputPhoneData(void)
{
	phoneData data;

	if (numOfData > LIST_NUM)
	{
		puts("메모리 공간이 부족합니다.");
		return;
	}

	fputs("이름 입력: ", stdout);
	gets(data.name);
	fputs("전화번호 입력: ", stdout);
	gets(data.phoneNum);
	
	phoneList[numOfData] = data;
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
		ShowPhoneInfo(phoneList[i]);
	}

	fputs("출력이 완료되었습니다, ", stdout);
	ReturnMenu();
}

// 함	수 : void SearchPhoneData(void)
// 기	능 : 이름을 통한 데이터 검색
// 반	환 : void
void SearchPhoneData(void)
{
	char name[NAME_LEN];
	int i;

	fputs("찾는 이름은? ",stdout);
	gets(name);

	for (i = 0; i < numOfData; i++)
	{
		if (strcmp(name, phoneList[i].name) == 0)
		{
			ShowPhoneInfo(phoneList[i]);
			ReturnMenu();
			return;
		}
	}

	fputs("데이터 정보가 없습니다,  ",stdout);
	ReturnMenu();
}

// 함	수 : void DeletePhoneData(void)
// 기	능 : 이름을 참조하여 데이터 삭제
// 반	환 : void
void DeletePhoneData(void)
{
	char name[NAME_LEN];
	int i,j;

	fputs("찾는 이름은? ", stdout);
	gets(name);
	for (i = 0; i < numOfData; i++)
	{
		if (strcmp(name, phoneList[i].name) == 0)
		{
			for (j = i; j < numOfData; j++)
			{
				phoneList[j] = phoneList[j + 1];
			}
			numOfData--;
			fputs("데이터 삭제 완료,  ", stdout);
			ReturnMenu();
			return;
		}
	}

	fputs("데이터 정보가 없습니다,  ", stdout);
	ReturnMenu();
}

/* end of file */