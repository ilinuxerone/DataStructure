#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
bool IsExisted;

void Swap(int *a,int *b)
{
	if(*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}

}

/*
�㷨���۰���ŵ�Partition����
*/
int Partition(int *A,int low,int high)
{
	if(A==NULL || low<0 || high<0 || low>=high)
		return -1;
	
	int small = low-1;
	int j;
	for(j=low;j<high;j++)
	{
		if(A[j] <= A[high])
		{
			++small;
			if(j != small)
				Swap(&A[j],&A[small]);
		}
	}
	++small;
	Swap(&A[small],&A[high]);
	return small;
}

int Random_Partition(int *A,int low,int high)
{
	//�����������
	srand((unsigned)time(0));
	int index = low + rand()%(high-low+1);
	Swap(&A[index],&A[high]);
	return Partition(A,low,high);
}


/*
�жϹؼ���key������A�г��ֵĴ����Ƿ񳬹�һ��
*/
bool IsMoreThanHalf(int *A,int len,int key)
{
	int times = 0;
	int i;
	for(i=0;i<len;i++)
		if(A[i] == key)
			times++;
	if(2*times <= len)
		return false;
	else
		return true;
}
 
/*
��������A�г��ִ�������һ�������
����Partition������ʵ��
*/
int MoreThanHalf(int *A,int len)
{
	if(A==NULL || len<1)
	{
		IsExisted = false;
		return -1;
	}

	int low = 0;
	int high = len-1;
	int mid = len>>1;
	int index = Random_Partition(A,low,high);
	while(index != mid)
	{
		if(index > mid)
			index = Random_Partition(A,low,index-1);
		else
			index = Random_Partition(A,index+1,high);
	}

	int key = A[mid];
	if(!IsMoreThanHalf(A,len,key))
	{
		IsExisted = false;
		return -1;
	}
	return key;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int *A = (int *)malloc(sizeof(int)*n);
		if(A == NULL)
			exit(EXIT_FAILURE);

		int i;
		for(i=0;i<n;i++)
			scanf("%d",A+i);

		IsExisted = true;
		int key = MoreThanHalf(A,n);
		if(IsExisted)
			printf("%d\n",key);
		else
			printf("-1\n");
	}
	return 0;
}