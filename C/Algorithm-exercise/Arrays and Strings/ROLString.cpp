#include<stdio.h>
#include<string.h>

void Swap(char *a,char *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
��ת�ַ����д�start��end���ⲿ��
*/
void ReverseString(char *str,int start,int end)
{
	while(start < end)
	{
		Swap(&str[start],&str[end]);
		start++;
		end--;
	}
}

/*
������kλ��õ����ַ�
*/
void ROLString(char *str,int k)
{
	if(str == NULL || k<=0)
		return;
	
	int len = strlen(str);
	//Ҫ����k����len�����
	k = k%len;
	if(k == 0)
		return;

	ReverseString(str,0,k-1);
	ReverseString(str,k,len-1);
	ReverseString(str,0,len-1);
}

int main()
{
	char str[1010];
	int k;
	while(scanf("%s %d",str,&k) != EOF)
	{
		ROLString(str,k);
		puts(str);
	}
	return 0;
}