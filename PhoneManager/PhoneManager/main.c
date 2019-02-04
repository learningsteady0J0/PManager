/* Name : main.c  ver 1.4
   content : main 함수
   Implementation : learningsteady0j0

   Last modified 2019/02/04
*/

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT };

// 함	수 : int main (void)
// 기	능 : 사용자 선택 처리
// 반	환 : 정상 종료 시 0

int main(void)
{
	int inputMenu;

	LoadDataFromFileInStruct();
	while (1)
	{	
		inputMenu = 0; // 두번째로 메뉴호출시 a나 다른 문자를 입력해도 정수값이 바뀌지 않는 문제 해결방안.
		ShowMenu();
		fputs("선택하세요 : ", stdout);
		scanf("%d", &inputMenu);
		getchar();

		switch (inputMenu)
		{
		case INPUT:
			InputPhoneData();
			break;
		case SHOWALL:
			ShowAllData();
			break;
		case SEARCH:
			SearchPhoneData();
			break;
		case DELETE:
			DeletePhoneData();
			break;

		case CHANGE:
			ChangePhoneData();
			break;
		}
		if (inputMenu == QUIT)
		{
			puts("이용해 주셔서 감사합니다.");
			StoreDataToFileInStruct();
			break;
		}
	}
	return 0;
}

/* end of file */