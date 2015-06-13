#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool flag = true;

//��base������absExp����
double PowerAbs(double base,unsigned int absExp)
{
	//�ݹ��˳�������
	if(absExp == 0)
		return 1.0;
	if(absExp == 1)
		return base;
	
	//�ݹ���η�
	double result = PowerAbs(base,absExp>>1);
		result *= result;
	//�ж���ż��
	if(absExp&1 == 1)
		result *= base;

	return result; 
}

//��base��exp�η�
double Power(double base,int exp)
{
	//����Ϊ0��ָ��Ϊ���������
	if(fabs(base-0.0)<0.0000001 && exp<=0)
	{
		flag = false;
		return 0.0;
	}

	unsigned int absExp = (unsigned int)abs(exp);
	double result = PowerAbs(base,absExp);
	if(exp<0)
		result = 1.0/result;

	return result;
}

int main()
{
	int n,exp;
	double base;
	while(scanf("%d",&n) != EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
			//ÿ�ζ�Ҫ�Ƚ�flag��Ϊtrue
			flag = true;
			scanf("%lf %d",&base,&exp);
			double result = Power(base,exp);
			if(flag)
				printf("%.2ef\n",result);
			else
				printf("INF\n");
		}
	}
	return 0;
}