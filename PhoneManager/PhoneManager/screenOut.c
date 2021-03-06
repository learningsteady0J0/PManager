/* Name : screenOut.c   ver 1.3
   content : 콘솔 출력을 위한 함수 정의
   Implementation : learningsteady0j0

   Last modified 2019/02/04
*/

#include "common.h"
#include "phoneData.h"


// 함	수 : void ShowMenu(void)
// 기	능 : 선택을 위한 메뉴 출력
// 반	환 : void

void ShowMenu(void)
{
	system("cls");  //stdlib.h

	printf("━━━━━━━━━ 메뉴 ━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf(" 1. 전화번호 입력           저장된 수:%d\n",numOfData);
	printf(" 2. 전체 정보 출력 \n");
	printf(" 3. 전화번호 검색 \n");
	printf(" 4. 전화번호 삭제 \n");
	printf(" 5. 전화번호 변경 \n");
	printf(" 6. 종료 \n");
	printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("선택>> ");
}

// 함	수 : void ShowPhoneInfo (phoneData phone)
// 기	능 : 이름과 전화번호 정보 출력
// 반	환 : void

void ShowPhoneInfo(phoneData phone)
{
	printf("━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("┃ ● 이름 : %s \n", phone.name);
	printf("┃ ● 전화번호 : %s \n", phone.phoneNum);
	printf("━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
}

// 함	수 : void ShowPhoneInfoByPtr(phoneData * phone)
// 기	능 : 포인터를 통한 이름과 전화번호 정보 출력
// 반	환 : void

void ShowPhoneInfoByPtr(phoneData * phone)
{
	printf("━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("┃ ● 이름 : %s \n", phone->name);
	printf("┃ ● 전화번호 : %s \n", phone->phoneNum);
	printf("━━━━━━━━━━━━━━━━━━━━━━━━\n\n");
}

void ReturnMenu(void)
{

	puts("메뉴로 돌아가려면 아무 키를 입력해주세요...");
	getchar();  // 아무 키 입력
}
/* end of file */