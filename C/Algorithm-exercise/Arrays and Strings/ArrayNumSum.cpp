/****************************************************************************************************
��Ŀ������һ���Ѿ�������������������һ�����֣��������в�����������ʹ�����ǵĺ�������������Ǹ����֡�
Ҫ��ʱ�临�Ӷ���O(n)������ж�����ֵĺ͵�����������֣��������һ�Լ��ɡ�
������������1��2��4��7��11��15������15������4+11=15��������4��11��
*****************************************************************************************************/
#include<stdio.h>
#include<stdbool.h>
/*
����������A���ҳ���Ϊsum����������Ԫ�أ�������a��b��
*/
bool FindTwoNumSum(int *A,int len,int sum,int *a,int *b)
{
	if(A==NULL || len<2)
		return false;
	int low = 0;
	int high = len-1;
	while(low<high)
	{
		if(A[low]+A[high] == sum)
		{
			*a = A[low];
			*b = A[high];
			return true;
		}
		else if(A[low]+A[high] < sum)
			low++;
		else
			high--;
	}
	return false;
}

int main()
{
	int n,k;
	static int A[1000000];
	while(scanf("%d %d",&n,&k) != EOF)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%d",A+i);

		int a,b;
		bool can = FindTwoNumSum(A,n,k,&a,&b);
		if(can)
			printf("%d %d\n",a,b);
		else
			printf("-1 -1\n");
	}

	return 0;
}