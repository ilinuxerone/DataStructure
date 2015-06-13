/****************************************************************************************
��Ŀ������
��֪һ���ַ����������k��λ֮ǰ����0��ʼ�ƣ����ַ���ת�����ַ�����β��������ת����ַ�����
���磬�����ַ�����abcdef���������2��λ��ǰ���ַ���ת��β�����õ���cdefab����
Date:2014-03-19
*****************************************************************************************/

#include<stdio.h>
#include<string.h>

/*
���ַ���str��start��endλ��֮����ַ���ת
*/
void reverseString(char *str,int start,int end)
{
	while(start < end)
	{
		str[start] = str[start] + str[end];
		str[end] = str[start] - str[end];
		str[start] = str[start] - str[end];
		start++;
		end--;
	}
}

/*
�������η�ת
*/
void rotate(char *str,int k)
{
	int len = strlen(str);
	if(k <= 0 || len <= k)
		return ;
	reverseString(str,0,k-1);
	reverseString(str,k,len-1);
	reverseString(str,0,len-1);
}

int main()
{
	char str1[] = "abcdef";
	char str2[] = "abcdefghket";
	rotate(str1,1);
	rotate(str2,4);
	puts(str1);
	puts(str2);
	return 0;
}