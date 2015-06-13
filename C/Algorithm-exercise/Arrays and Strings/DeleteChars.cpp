#include<stdio.h>
#include<string.h>
#define MAX 256

void DeleteChars(char *str1,char *str2)
{
	if(str1==NULL || str2==NULL)
		return;

	bool hashtable[MAX];
	memset(hashtable,0,sizeof(hashtable));

	//��str2���ַ���Ӧ��hashtable�����е�λ���ϵ�ֵ��Ϊture
	while(*str2 != '\0')
	{
		//ASCIIֵ��128-255֮��ĵ��ַ���
		//��char���棬ת��Ϊint��,��-128--1֮��
		int index;
		if(*str2 >= 0)
			index = *str2;
		else
			index = *str2 + 256;

		hashtable[index] = true;
		++str2;
	}

	char *pFast = str1;
	char *pSlow = str1;
	while(*pFast != '\0')
	{
		int index;
		if(*pFast >= 0)
			index = *pFast;
		else
			index = *pFast + 256;

		//�����Ƿ�����Ҫɾ�����ַ���pFast�����ƣ�
		//ֻ��û����Ҫɾ�����ַ�ʱ��pSlow�ź���
		if(!hashtable[index])
			*pSlow++ = *pFast;	
		++pFast;
	}
	*pSlow = '\0';
}

int main()
{

	char str1[] = "They are students";
	char str2[] = "Tt";
	DeleteChars(str1,str2);
	puts(str1);
	return 0;
}