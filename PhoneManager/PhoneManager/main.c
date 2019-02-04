/* Name : main.c  ver 1.0
   content : main �Լ�
   Implementation : learningsteady0j0

   Last modified 2019/02/04
*/

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum { INPUT = 1, SHOWALL, QUIT };

// ��	�� : int main (void)
// ��	�� : ����� ���� ó��
// ��	ȯ : ���� ���� �� 0

int main(void)
{
	int inputMenu;

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
		}

		if (inputMenu == QUIT)
		{
			puts("�̿��� �ּż� �����մϴ�.");
			break;
		}
	}
	return 0;
}

/* end of file */