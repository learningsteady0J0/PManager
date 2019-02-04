/* Name : main.c  ver 1.4
   content : main �Լ�
   Implementation : learningsteady0j0

   Last modified 2019/02/04
*/

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT };

// ��	�� : int main (void)
// ��	�� : ����� ���� ó��
// ��	ȯ : ���� ���� �� 0

int main(void)
{
	int inputMenu;

	LoadDataFromFileInStruct();
	while (1)
	{	
		inputMenu = 0; // �ι�°�� �޴�ȣ��� a�� �ٸ� ���ڸ� �Է��ص� �������� �ٲ��� �ʴ� ���� �ذ���.
		ShowMenu();
		fputs("�����ϼ��� : ", stdout);
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
			puts("�̿��� �ּż� �����մϴ�.");
			StoreDataToFileInStruct();
			break;
		}
	}
	return 0;
}

/* end of file */