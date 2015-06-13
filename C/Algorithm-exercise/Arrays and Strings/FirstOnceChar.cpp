#include<stdio.h>
#include<string.h>

/*
���ص�һ������һ�ε��ַ�
*/
char FirstOnceChar(char *str)
{
	if(str == NULL)
		return '\0';

	int hashtable[256];
	memset(hashtable,0,sizeof(hashtable));
	char *pCur = str;
	while(*pCur != '\0')
	{
		if(*pCur>=0)
			hashtable[*(pCur++)]++;
		else
			hashtable[*(pCur++)+256]++;
	}

	while(*str != '\0')
	{
		int index;
		if(*str>=0)
			index = *str;
		else
			index = *str+256;

		if(hashtable[index] == 1)
			return *str;
		else
			str++;
	}
	return '\0';
}

/*
���ص�һ������һ�ε��ַ����±�
*/
int IndexOfFirstOnceChar(char *str)
{
	if(str == NULL)
		return -1;

	int len = strlen(str);
	int hashtable[256];
	memset(hashtable,0,sizeof(hashtable));
	int i;
	for(i=0;i<len;i++)
	{
		if(str[i]>=0)
			hashtable[str[i]]++;
		else
			hashtable[str[i]+256]++;
	}

	for(i=0;i<len;i++)
	{
		int index;
		if(str[i]>=0)
			index = str[i];
		else
			index = str[i]+256;

		if(hashtable[index] == 1)
			return i;
	}
	return -1;
}

int main()
{
	char str[10010];
	while(gets(str) != NULL)
		printf("%d\n",IndexOfFirstOnceChar(str));
	return 0;
}