/* Name : screenout.h  ver 1.1
   content : �ܼ� ����� ���� �Լ� ����
   Implementation : learningsteady0j0

   Last modified 2019/02/04
*/

#ifndef __SCREENOUT_H__
#define __SCREENOUT_H__

#include "phoneData.h"

void ShowMenu(void);
void ShowPhoneInfo(phoneData phone);
void ReturnMenu(void);
void ShowPhoneInfoByPtr(phoneData * phone);

#endif

/* end of file*/
