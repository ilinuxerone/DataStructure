#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool flag;

int MaxSubSum(int *arr,int len,int *indexBegin,int *indexEnd)
{
	if(arr==NULL || len<1)
	{
		flag = false;
		return -1;
	}

	int i;
	int MaxSum;
	int CurSum;
	int CurBegin; //��ǰ��CurSum�Ŀ�ʼ��������
	int CurEnd;	 //��ǰ��CurSum�Ľ�����������
	for(i=0;i<len;i++)
	{
		if(i == 0)
		{
			//���õ�һ��Ԫ�س�ʼ��
			*indexBegin = 0;
			*indexEnd = 0;
			CurBegin = 0;
			CurEnd = 0;
			MaxSum = arr[i];
			CurSum = arr[i];
		}
		else
		{
			//ǰ��ĺ�С��0������ǰ��ĺͣ��ӵ�ǰԪ�����¿�ʼ����
			if(CurSum < 0)
			{
				CurSum = arr[i];
				CurBegin = i;
				CurEnd = i;
			}
			else
			{
				CurSum += arr[i];
				CurEnd = i;
			}
			if(CurSum > MaxSum)
			{
				MaxSum = CurSum;
				//�����ǰ�ʹ���ǰ����ֵ����ͣ�
				//���滻�����͵Ŀ�ʼ�����ͽ�������
				*indexBegin = CurBegin;
				*indexEnd = CurEnd;
			}
		}
	}
	return MaxSum;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		int *arr = (int *)malloc(sizeof(int)*n);
		if(arr == NULL)
			exit(EXIT_FAILURE);

		int i;
		for(i=0;i<n;i++)
			scanf("%d",arr+i);

		flag = true;
		int indexBegin,indexEnd;
		int result = MaxSubSum(arr,n,&indexBegin,&indexEnd);	
		if(flag)
		{
			printf("%d ",result);
			printf("%d ",indexBegin);
			printf("%d\n",indexEnd);
		}

		free(arr);
		arr = NULL;
	}
	return 0;
}