#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
ģ������Ƽ�1�����������λҪ��λʱ��˵�����е�λ����1������false��
��char������ģ���int�����ʡ�ռ䣬������봫�����鳤��len��
��������CominationAll�н�Ҫ������ַ�����ȫ����ʼ��Ϊ��'\0',
����ڸú����ڲ���strlen����Ļ�����õ�len=0��
*/
bool Increment(char *BindAdd,int len)
{
	if(BindAdd == NULL)
		return false;

	BindAdd[len-1]++;
	int i;
	for(i=len-1;i>=0;i--)
	{
		if(BindAdd[i] >= 2)
		{
			if(i == 0)
			{
				BindAdd[i]--;
				return false;
			}
			else
			{
				BindAdd[i] -= 2;
				BindAdd[i-1]++;
			}
		}
		else
			break;
	}
	return true;
}

/*
����ַ������������
*/
void CominationAll(char *str)
{
	if(str == NULL)
		return;

	int len = strlen(str);
	char *BindAdd = (char *)malloc(len*sizeof(char));
	if(BindAdd == NULL)
		exit(EXIT_FAILURE);

	memset(BindAdd,0,len*sizeof(char));
	while(Increment(BindAdd,len))
	{
		int i;
		for(i=0;i<len;i++)
		{
			if(BindAdd[i] == 1)
				putchar(str[i]);
		}
		putchar('\n');
	}

	free(BindAdd);
	BindAdd = NULL;
}

int main()
{
	char str[10];
	while(gets(str))
		CominationAll(str);
	return 0;
}