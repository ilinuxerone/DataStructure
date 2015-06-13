#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

/*
��ӡ�ַ�����ʾ�����֣�Ҫ����ǰ���'0'
*/
void PrintNum(char *num)
{
	int i = 0;
	while(num[i] == '0')
		i++;
	puts(num+i);
}

/*
�ַ�����ʾ������ģ���Լ�1
*/
bool Increment(char *num)
{
	bool isOverflow = false;
	int len = strlen(num);
	int i;

	//�ַ�ת��Ϊ����
	for(i=0;i<len;i++)
		num[i] = num[i] - '0';

	//�����1�Ľ��
	num[len-1]++;
	for(i=len-1;i>=0;i--)
	{
		if(num[i]>=10)
		{	
			if(i == 0)
			{	//��������λ��λ����˵����ӡ����
				isOverflow = true;
				num[i]--;
			}
			else
			{
				num[i] -= 10;
				num[i-1] += 1;
			}
		}
		else
			break;
	}

	//����ת��Ϊ�ַ�
	for(i=0;i<len;i++)
		num[i] = num[i] + '0';	

	return isOverflow;

}

/*
��ӡ��1������nλ��
*/
void PrintToMaxN(int n)
{
	if(n<=0)
		return;

	char *num = (char *)malloc((n+1)*sizeof(char));
	if(num == NULL)
		exit(EXIT_FAILURE);
	//ÿ���ֽڶ���ʼ��Ϊ'0'�ַ�
	memset(num,'0',n*sizeof(char));
	num[n] = '\0';
	while(!Increment(num))
		PrintNum(num);

	free(num);
	num = NULL;
}

int main()
{
	int n;
	scanf("%d",&n);
	PrintToMaxN(n);
	return 0;
}