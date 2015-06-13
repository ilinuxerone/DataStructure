#include<stdio.h>

bool flag;
long long MaxProduct(int *arr,int len)
{
	if(arr==NULL || len<1)
	{ 
		flag = false;
		return 0;
	}

	int minus = 0;	//��������
	int plus = 0;	//��������
	int zero = 0;	//0�ĸ���
	int minAbsMinus = (signed int)0x80000000;	//����ֵ��С�ĸ�����,�ȳ�ʼ��Ϊ��С��int����
	int maxAbsMinus = -1;						//����ֵ���ĸ��������ȳ�ʼ��Ϊ���ĸ�����
	int minPlus = 0x7FFFFFFF;					//��С�����������ȳ�ʼ��Ϊ����int����

	int i;
	for(i=0;i<len;i++)
	{
		if(arr[i] == 0)
			zero++;
		else if(arr[i] < 0)
			minus++;
		else
			plus++;

		if(arr[i]<0 && arr[i]>minAbsMinus)
			minAbsMinus = arr[i];
		if(arr[i]<0 && arr[i]<maxAbsMinus)
			maxAbsMinus = arr[i];
		if(arr[i]>0 && arr[i]<minPlus)
			minPlus = arr[i];	
	}

	int outNum;		//������˻�����
	long long result = 1;	//n-1���������˻�

	//0�ĸ�������1���������ʱ����n-1�����ĳ˻���Ϊ0��
	if(zero > 1)
		return 0;
	//�����һ��0������Ҫ�����������ĸ���������
	if(zero == 1)
	{
		//��������ĸ���Ϊż������
		//��ȥ��0���n-1�����ĳ˻�Ϊ������Ϊ���ֵ
		if((minus&1) == 0)
			outNum = 0;
		//��������ĸ���Ϊ��������
		//��ȥ��0���n-1�����ĳ˻�Ϊ����������ֵӦ��Ϊ0��
		//ȥ����һ����0Ԫ�ؼ���
		else	
			return 0;
	}
	//���û��0������Ҫ�����������ĸ���������
	else
	{
		//�����������Ϊ����������ȥ��һ��������ʣ�µ�n-1��Ԫ�صĳ˻�Ϊ����
		//��ʱȥ������ֵ��С�ĸ�����ʣ�µ�n-1�����ĳ˻������
		if((minus&1) != 0)
			outNum = minAbsMinus;
		//�����������Ϊż��������ʱ��Ҫ�����������
		//��������������û����
		else
		{
			//���������û����������n-1�������ĳ˻��϶�Ϊ������
			//ȥ������ֵ���ĸ�������ɵ�n-1�������˻������ֵ
			if(plus == 0)
					outNum = maxAbsMinus;
			//�������������������ȥ����С����������ɵ�n-1�����˻����ֵ
			else
				outNum = minPlus;
		}
	}

	//����˻�
	for(i=0;i<len;i++)
	{
		if(arr[i] != outNum)
			result *= arr[i];
	}
	
	return result;
}


int main()
{
	int arr[6] = {-3,-7,-1,-2,-6,-4};
	flag = true;
	if(flag)
		printf("%lld\n",MaxProduct(arr,6));
	return 0;
}
