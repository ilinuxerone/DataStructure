/***********************************************
��Ŀ������
�Ƴ��ַ������ظ����ַ�����abcadc�Ƴ����Ϊabcd��
���Զ��ⶨ��һ���������������������⿪��һ������,
��Ϊ���㷨д��������
Date:2014-03-16
************************************************/
#define MAX 26
#include<stdio.h>
#include<string.h>

void remove(char *str)
{
	int len = strlen(str);
	if(len < 2)
		return ;
	int i,j;
	int p = 0;	//p�ĳ�ֵ��i��ȣ���Ϊ0
	for(i=0;i<len;i++)
	{
		//������ַ���Ϊ'\0'������������ַ��Ƚ�
		if(str[i])
		{
			//�����ǰ�ַ���Ϊ'\0'ʱ��pһֱ��i��ȣ�
			//�����ǰ�ַ�Ϊ'\0'����p��С��i���Ӷ��ú�����ַ������ǰ��'\0'�ַ���λ��
			str[p++] = str[i];
			//ÿ���ַ����������ַ��Ƚϣ�
			//��������ظ��ַ����򽫺�����ظ��ַ���'\0'����
			for(j=i+1;j<len;j++)
				if(str[i] == str[j])
					str[j] = '\0';
		}
	}
	str[p] = '\0';
}

/*
���ٳ�Ϊ26��bool����ķ���
*/
void remove1(char *str)
{
	int len = strlen(str);
	if(len < 2)
		return ;
	int i;
	int p = 0;
	bool A[MAX];
	memset(A,0,sizeof(A));
	for(i=0;i<len;i++)
	{
		int index = str[i] - 'a';
		if(!A[index])
		{
			str[p++] = str[i];
			A[index] = true;
		}
	}
	str[p] = '\0';
}

int main()
{
	char str1[] = "abcdfbdk";	//����ַ���
	char str2[] = "abababab";	//�ظ��ַ��������
	char str3[] = "aaaabbbb";	//�ظ��ַ���������
	char str4[] = "aaaaaaaa";   //ȫ���ظ��ַ�
	char str5[] = "abcdefgh";   //û���ظ��ַ�
	char str6[] = "";			//���ַ���

	remove1(str1);
	remove1(str2);
	remove1(str3);
	remove1(str4);
	remove1(str5);
	remove1(str6);

	puts(str1);
	puts(str2);
	puts(str3);
	puts(str4);
	puts(str5);
	puts(str6);

	return 0;
}