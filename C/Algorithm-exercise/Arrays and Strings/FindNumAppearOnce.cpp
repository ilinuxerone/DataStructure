#include<stdio.h>
#include<stdbool.h>

/*
����num�����λ��1��������λ��Ϊ0
*/
int FindFirstBit1(int num)
{
	//�������õ���������num���ұߵ�1��������������λ��ȫ����Ϊ��0
	return num & (-num);
}

/*
�ж�data���ض���λ�Ƿ�Ϊ1��
�����Ҫ�жϵ��ض���λ��resȷ����
res��ֻ��һλΪ1������λ��Ϊ0����FindFirstBit1�������أ�
��data��Ҫ�жϵ�λ����res����Ψһ��1���ڵ�λ
*/
bool IsBit1(int data,int res)
{
	return ((data&res)==0) ? false:true;
}

void FindNumsAppearOnce(int *arr,int len,int *num1,int *num2)
{
	if(arr==NULL || len<2)
		return;

	int i;
	int AllXOR = 0;
	//ȫ�����
	for(i=0;i<len;i++)
		AllXOR ^= arr[i];

	int res = FindFirstBit1(AllXOR);

	*num1 = *num2 = 0;
	for(i=0;i<len;i++)
	{
		if(IsBit1(arr[i],res))
			*num1 ^= arr[i];
		else
			*num2 ^= arr[i];
	}
}

int main()
{
	static int arr[1000000];
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int i;
		for(i=0;i<n;i++)
			scanf("%d",arr+i);

		int num1,num2;
		FindNumsAppearOnce(arr,n,&num1,&num2);
		if(num1 < num2)
			printf("%d %d\n",num1,num2);
		else
			printf("%d %d\n",num2,num1);
	}
	return 0;
}