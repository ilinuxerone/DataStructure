/****************************************************************
��Ŀ������
��д���룬ʵ�ַ�תһ��C�����ַ����Ĺ��ܡ�
C������˼��"abcd"��Ҫ��5���ַ�����ʾ�����һ���ַ�Ϊ���ַ�'\0'��
Date:2014-03-15
*****************************************************************/
#include<stdio.h>
/*
�������ַ�
*/
void swap(char *a,char *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

/*
��ת�ַ���
*/
void reverse(char *str)
{
	if(!str)
		return;
	char *pLeft = str;
	char *pRight = str;
	while(*pRight != '\0')
		pRight++;
	pRight--;
	while(pLeft < pRight)
		swap(pLeft++,pRight--);
}

int main()
{
	//ע�����ﲻ�ܶ���Ϊ char *str = "thanks"��
	//������������ַ��������������޸ġ�
	char str[] = "thanks";
	reverse(str);
	puts(str);
	return 0;
}
