/* Name : phoneFunc.c  ver 1.1
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
	scanf("%s", data.name);
	fputs("전화번호 입력: ", stdout);
	scanf("%s", data.phoneNum);
	getchar();


	phoneList[numOfData] = data;
	numOfData++;

	puts("입력이 완료되었습니다, 메뉴로 돌아가려면 아무 키를 입력해주세요.");
	fgets(data.name, sizeof(data.name), stdin);  // 아무 키 입력
	
	

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

	puts("출력이 완료되었습니다, 메뉴로 돌아가려면 아무 키를 입력해주세요.");
	fgets(str, sizeof(str), stdin);  // 아무 키 입력
	
}

/* end of file */