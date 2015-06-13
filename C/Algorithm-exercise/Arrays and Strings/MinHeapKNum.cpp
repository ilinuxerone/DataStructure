#include<stdio.h>
#include<stdlib.h>

/*
arr[start+1...end]����С���ѵĶ��壬
��arr[start]���뵽С����arr[start+1...end]�У�
����arr[start]��λ�ã�ʹarr[start...end]Ҳ��ΪС����
ע�����������0��ʼ������ţ�Ҳ���Ƕ���ѵĸ��ڵ����Ϊ0��
������Ϊi�������ӽڵ����ŷֱ�Ϊ2i+1��2i+2
*/
void HeapAdjustDown(int *arr,int start,int end)
{
	int temp = arr[start];	//���浱ǰ�ڵ�
	int i = 2*start+1;		//�ýڵ�������������е�λ�����
	while(i<=end)
	{
		//�ҳ����Һ�������С���Ǹ�
		if(i+1<=end && arr[i+1]<arr[i])  
			i++;
		//������϶ѵĶ��壬���õ���λ��
		if(arr[i]>=temp)	
			break;
		//��С���ӽڵ������ƶ����滻���丸�ڵ�
		arr[start] = arr[i];
		start = i;
		i = 2*start+1;
	}
	arr[start] = temp;
}

/*
�õ���С��k������������arr�е������k��λ��
*/
void MinHeapKNum(int *arr,int len,int k)
{
	if(arr==NULL || len<1 || k<1 || k>len)
		return;

	int i;
	//�����齨��ΪС����
	//��һ����Ҷ�ӽڵ��λ�����Ϊ(len-1)/2
	for(i=(len-1)/2;i>=0;i--)
		HeapAdjustDown(arr,i,len-1);
	//���ж�����
	for(i=len-1;i>=len-k;i--)
	{
		//�Ѷ�Ԫ�غ����һ��Ԫ�ؽ���λ�ã�
		//��������һ��λ�ñ��������С������
		//ÿ��ѭ�����ν���С����ֵ�ڷŽ���ǰ��һ��λ�ã�
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		//��arr[0...i-1]���µ���ΪС����
		HeapAdjustDown(arr,0,i-1);
	}
}


int main()
{
	int n,k;
	while(scanf("%d %d",&n,&k) != EOF)
	{
		int *A = (int *)malloc(sizeof(int)*n);
		if(A == NULL)
			exit(EXIT_FAILURE);

		int i;
		for(i=0;i<n;i++)
			scanf("%d",A+i);

		MinHeapKNum(A,n,k);
		for(i=n-1;i>=n-k;i--)
		{
			//����Ҫ��ĸ�ʽ���
			if(i == n-k)
				printf("%d\n",A[i]);
			else
				printf("%d ",A[i]);
		}
	}
	return 0;
}