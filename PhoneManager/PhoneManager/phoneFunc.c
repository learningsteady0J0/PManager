/* Name : phoneFunc.c  ver 1.2
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
	gets(data.name);
	fputs("��ȭ��ȣ �Է�: ", stdout);
	gets(data.phoneNum);
	
	phoneList[numOfData] = data;
	numOfData++;

	fputs("�Է��� �Ϸ�Ǿ����ϴ�, ", stdout);
	ReturnMenu();
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

	fputs("����� �Ϸ�Ǿ����ϴ�, ", stdout);
	ReturnMenu();
}

// ��	�� : void SearchPhoneData(void)
// ��	�� : �̸��� ���� ������ �˻�
// ��	ȯ : void
void SearchPhoneData(void)
{
	char name[NAME_LEN];
	int i;

	fputs("ã�� �̸���? ",stdout);
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

	fputs("������ ������ �����ϴ�,  ",stdout);
	ReturnMenu();
}

// ��	�� : void DeletePhoneData(void)
// ��	�� : �̸��� �����Ͽ� ������ ����
// ��	ȯ : void
void DeletePhoneData(void)
{
	char name[NAME_LEN];
	int i,j;

	fputs("ã�� �̸���? ", stdout);
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
			fputs("������ ���� �Ϸ�,  ", stdout);
			ReturnMenu();
			return;
		}
	}

	fputs("������ ������ �����ϴ�,  ", stdout);
	ReturnMenu();
}

/* end of file */