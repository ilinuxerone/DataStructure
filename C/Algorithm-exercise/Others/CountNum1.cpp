#include<stdio.h>

/*
�ֱ�ͳ��num��λ��1���ֵĴ�����
��ӵõ�1���ֵ��ܴ���
*/
long long CountNum1(long long num)
{
	if(num <= 0)
		return 0;

	long long count = 0;	//ͳ��1���ֵĴ���
	long long current;    //��ǰλ
	long long base = 1;	//��ǰλ�Ļ�
	long long remain = 0;	//��ǰλΪ1ʱ������λʣ����������������Ĳ��֣���1���ֵĴ���
	while(num)
	{
		current = num%10;
		num = num/10;

		if(current > 1)
			 count += (num+1)*base;
		else if(current == 1)
			count += num*base + (remain+1);
		else
			count += num*base;
	
		//��һλҪ�õ��Ļ���ʣ�಻��������ֵ
		remain += current*base; 
		base *= 10;
	}

	return count;
}

int main()
{
	long long a,b;
	//a,b�Ĵ�С����
	while(scanf("%lld %lld",&a,&b) != EOF)
	{
		long long result;
		if(a > b)
			result = CountNum1(a) - CountNum1(b-1);
		else
			result = CountNum1(b) - CountNum1(a-1);

		printf("%lld\n",result);
	}
	return 0;
}