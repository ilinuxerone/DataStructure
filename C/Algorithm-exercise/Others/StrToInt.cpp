#include<stdio.h>
#include<stdbool.h>
bool IsValid;

long StrToIInt(const char *str)
{
	//�Ƿ�����
	if(str == NULL)
	{
		IsValid = false;
		return 0;
	}

	//�Ƿ�Ϊ����
	bool IsMinus = false;

	//����ǰ��Ŀհ��ַ�
	while(*str == ' ')
		str++;

	//��һ���ǿհ��ַ�Ϊ+��
	if(*str == '+')
		str++;
	//��һ���ǿհ��ַ�Ϊ-��
	else if(*str == '-')
	{
		str++;
		IsMinus = true;
	}

	//���ֻ�����˿հ��ַ�������λ������ʲô��û���룬ҲΪ�Ƿ�����
	if(*str == '\0')
	{
		IsValid = false;
		return 0;
	}


	//�������������Ϸ�����ת��Ϊ����
	long num = 0;	//ת��Ϊ������Ľ��
	//��������ʹ����234asd������Ҳ�ж�Ϊ�Ϸ����룬�õ��Ľ��Ϊ234
	while(*str != '\0')
	{
		//���벻��0-9֮�䣬���ڷǷ�����
		if(*str<'0' || *str>'9')
		{
			IsValid = false;
			return 0;
		}
		//�Բ���������λ�ĺϷ��������ת��
		num = 10*num + (*str - '0');
		str++;
	}
	
	//���ݷ���λת������
	num = IsMinus ? (-1*num) : num;
	//�ж��Ƿ������int�ķ�Χ
	if(num>0X7FFFFFFF || num<(signed int)0X80000000)
	{
		IsValid = false;
		return 0;
	}

	//����û�з��أ���˵���Ϸ���û�з������
	return num;
}

int main()
{
	static char str[100000000];
	while(gets(str) != NULL)
	{
		IsValid = true;
		long result = StrToIInt(str);
		if(IsValid)
			printf("%ld\n",result);
		else
			printf("My God\n");
	}
	return 0;
}