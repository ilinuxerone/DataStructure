/******************
�ַ���ʵ�ִ������
Author:��ͤ����
Date:2014-05-11
******************/
#include<stdio.h>
#include<string.h>

#define MAX 100

char *BigDataAdd(char *s1,char *s2)
{
	if(s1==NULL || s2==NULL)
		return NULL;

	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int Maxlen = (len1>len2)?len1:len2;
	
	//����Ӧ���ַ�ת��Ϊ��������ʹ���߶��뵽Maxlen����
	//ǰ����ַ�ͨ��memset��ASCIIֵΪ0���ַ��滻��
	//���λ������������θ�λ������λ������Ա����λ1��
	//����s1��s2�൱�ڱ�Ϊ���������飬�����ַ���ASCIIֵ��0-255֮�䣬
	//������ﲻ�ÿ���int���飬ֱ���������char���鼴��
	int i,k;
	for(i=len1-1,k=Maxlen;i>=0;i--,k--)
		s1[k] = s1[i] - '0';
	if(k>=0)
		memset(s1,0,(k+1)*sizeof(char));
	for(i=len2-1,k=Maxlen;i>=0;i--,k--)
		s2[k] = s2[i] - '0';
	if(k>=0)
		memset(s2,0,(k+1)*sizeof(char));

	//����������ӵ�s1��
	for(i=Maxlen;i>=1;i--)
	{
		s1[i] += s2[i];
		if(s1[i]>=10)
		{
			s1[i] -= 10;
			s1[i-1] += 1;
		}
	}
	
	//��s1ת��ΪΪ��Ӻ���ַ���
	if(s1[0] == 0)
	{	//����θ�λû�н�λ
		for(i=1;i<=Maxlen;i++)
			s1[i-1] = s1[i] +'0';
		s1[i-1] = '\0';
	}
	else
	{	//����θ�λ�н�λ
		for(i=0;i<=Maxlen;i++)
			s1[i] = s1[i] +'0';
		s1[i] = '\0';
	}
	return s1;
}

int main()
{
	char s1[MAX];
	char s2[MAX];
	gets(s1);
	gets(s2);
	char *result = BigDataAdd(s1,s2);
	if(result != NULL)
		puts(result);
	else
		printf("Wrong\n");
	return 0;
}