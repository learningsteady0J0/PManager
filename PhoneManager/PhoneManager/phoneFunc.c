/* Name : phoneFunc.c  ver 1.1
   content : ��ȭ��ȣ ��Ʈ�� �Լ�
   Implementation : learningsteady0j0

   Last modified 2019/02/04
*/

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData phoneList[LIST_NUM];

// ��	�� : void InputPhoneData(void)
// ��	�� : ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����
// ��	ȯ : void

void InputPhoneData(void)
{
	phoneData data;

	if (numOfData > LIST_NUM)
	{
		puts("�޸� ������ �����մϴ�.");
		return;
	}

	fputs("�̸� �Է�: ", stdout);
	scanf("%s", data.name);
	fputs("��ȭ��ȣ �Է�: ", stdout);
	scanf("%s", data.phoneNum);
	getchar();


	phoneList[numOfData] = data;
	numOfData++;

	puts("�Է��� �Ϸ�Ǿ����ϴ�, �޴��� ���ư����� �ƹ� Ű�� �Է����ּ���.");
	fgets(data.name, sizeof(data.name), stdin);  // �ƹ� Ű �Է�
	
	

}

// ��	�� : void ShowAllData(void)
// ��	�� : ����� ������ ��ü ���
// ��	ȯ : void

void ShowAllData(void)
{
	int i;
	char str[NAME_LEN];

	for (i = 0; i < numOfData; i++)
	{
		ShowPhoneInfo(phoneList[i]);
	}

	puts("����� �Ϸ�Ǿ����ϴ�, �޴��� ���ư����� �ƹ� Ű�� �Է����ּ���.");
	fgets(str, sizeof(str), stdin);  // �ƹ� Ű �Է�
	
}

/* end of file */