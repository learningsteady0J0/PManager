/* Name : screenOut.c   ver 1.0
   content : �ܼ� ����� ���� �Լ� ����
   Implementation : learningsteady0j0

   Last modified 2019/02/04
*/

#include "common.h"
#include "phoneData.h"

// ��	�� : void ShowMenu(void)
// ��	�� : ������ ���� �޴� ���
// ��	ȯ : void

void ShowMenu(void)
{
	system("cls");  //stdlib.h

	printf("������������������ �޴� ������������������\n");
	printf(" 1. ��ȭ��ȣ �Է� \n");
	printf(" 2. ��ü ���� ��� \n");
	printf(" 3. ���� \n");
	printf("������������������������������������������������\n");
	printf("����>> ");
}

// ��	�� : void ShowPhoneInfo (phoneData phone)
// ��	�� : �̸��� ��ȭ��ȣ ���� ���
// ��	ȯ : void

void ShowPhoneInfo(phoneData phone)
{
	printf("������������������������������������������������\n");
	printf("�� �� �̸� : %s \n", phone.name);
	printf("�� �� ��ȭ��ȣ : %s \n", phone.phoneNum);
	printf("������������������������������������������������\n\n");
}

/* end of file */