/* Name : phoneFunc.c  ver 1.4
   content : ��ȭ��ȣ ��Ʈ�� �Լ�
   Implementation : learningsteady0j0

   Last modified 2019/02/04
*/

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM 100

int numOfData = 0;
phoneData * phoneList[LIST_NUM];

// ��	�� : void InputPhoneData(void)
// ��	�� : ��ȭ��ȣ ���� ������ �Է� �޾Ƽ� ����
// ��	ȯ : void

void InputPhoneData(void)
{
	phoneData data;
	phoneData * alocPhoneList = (phoneData*)malloc(sizeof(phoneData));
	int i;

	if (numOfData > LIST_NUM)
	{
		puts("�޸� ������ �����մϴ�.");
		return;
	}

	fputs("�̸� �Է�: ", stdout);
	gets(data.name);
	fputs("��ȭ��ȣ �Է�: ", stdout);
	gets(data.phoneNum);
	
	for (i = 0; i < numOfData; i++)
	{
		if (!strcmp(data.name, phoneList[i]->name) && !strcmp(data.phoneNum, phoneList[i]->phoneNum))
		{
			fputs("�̹� �Էµ� ������ �Դϴ�,  ", stdout);
			free(alocPhoneList);   // ������ �� ��Ծ���.. �� ����� ��. �����޸��Ҵ��� �� �׻� �����صѰ�.
			ReturnMenu();
			return;
		}
	}

	*alocPhoneList = data;
	phoneList[numOfData] = alocPhoneList;
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
		ShowPhoneInfoByPtr(phoneList[i]);
	}

	fputs("����� �Ϸ�Ǿ����ϴ�, ", stdout);
	ReturnMenu();
}

// ��	�� : void SearchPhoneData(void)
// ��	�� : �̸��� ���� ������ �˻�
// ��	ȯ : void
void SearchPhoneData(void)
{
	char searchName[NAME_LEN];
	int i;
	int count = 0;  //  ã���� 1, �� ã���� 0

	fputs("ã�� �̸���? ",stdout);
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
		fputs("������ ������ �����ϴ�,  ", stdout);
		ReturnMenu();
	}

	ReturnMenu();
	return;
	
}

// ��	�� : void DeletePhoneData(void)
// ��	�� : �̸��� �����Ͽ� ������ ����
// ��	ȯ : void
void DeletePhoneData(void)
{
	char delName[NAME_LEN];
	int idxOfMattchingData[LIST_NUM];
	int delIdx;
	int count = 0;
	int i, j ,num;

	fputs("ã�� �̸���? ", stdout);
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
		fputs("������ ������ �����ϴ�,  ", stdout);
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
		fputs("����: ",stdout);
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
	fputs("������ ���� �Ϸ�,  ", stdout);
	ReturnMenu();
	return;
}

/* end of file */