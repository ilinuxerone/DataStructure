#include<stdio.h>

/*
ŷ������㷨��շת��������Լ��
*/
int MaxYue1(int a,int b)
{
	//��շת���֮ǰ��ȷ��a��b��
	if(a<b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	//շת����������Լ��
	while(b!=0)
	{
		int temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

/*
շת����������Լ��
*/
int MaxYue2(int a,int b)
{
	if(a<b)
		return MaxYue2(b,a);
	if(b==0)
		return a;
	else
		return MaxYue2(b,a-b);
}


/*
�Ľ�շת�����
*/
int MaxYue3(int a,int b)
{
	if(a<b)
		return MaxYue3(b,a);
	if(b==0)
		return a;
	else
	{
		if((a&1)==0)	//aΪż��
		{
			if((b&1)==0) //bҲΪż��
				return (MaxYue3(a>>1,b>>1)<<1);
			else		//bΪ����
				return MaxYue3(a>>1,b);
		}
		else	//aΪ����
		{
			if((b&1)==0) //bΪż��
				return MaxYue3(a,b>>1);
			else		//bҲΪ����
				return MaxYue3(b,a-b);
		}
	}
}


int main()
{
	int a = 10021000;
	int b = 1202000;
	printf("%d\n",MaxYue3(a,b));
	return 0;
}
