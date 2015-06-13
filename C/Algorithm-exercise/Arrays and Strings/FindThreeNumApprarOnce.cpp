#include<stdio.h>

/*
ͨ��ɨ��ÿһλ�����ҳ�һ��ֻ����һ�ε���
*/
int FindOneNumAppearOnce(int *arr,int len)
{
	int count1 = 0;	//ĳһλ��1�ĸ���
	int count0 = 0; //ĳһλ��0�ĸ���
	int temp1 = 0;	//ĳһλΪ1�������������Ľ��
	int temp0 = 0;	//ĳһλΪ0�������������Ľ��

	int i,j;
	for(i=0;i<8*sizeof(int);i++)	//ѭ������ÿһλ�������ĸ�����
	{
		count1 = count0 = temp1 = temp0 = 0;//ÿ�μ�����һλʱ����
		for(j=0;j<len;j++)
		{	
			//ÿ��������һλ���м���
			if(arr[j] & (1<<i))	//��λΪ1ʱ
			{
				temp1 ^= arr[j];
				count1++;
			}
			else
			{
				temp0 ^= arr[j];
				count0++;
			}
		}

		if(temp1 & 1)	//ĳλ����������1
		{
			if(temp0 == 0)	//��ʱ3����ͬ���ĸ�λ��Ϊ1
				continue;
			else			//��ʱ3����ͬ���ĸ�λ��1��1��2��0
				return temp1;
		}
		else	//ĳλ����ż����1
		{
			if(temp1 == 0)	//��ʱ3����ͬ���ĸ�λ��Ϊ0
				continue;
			else			//��ʱ3����ͬ���ĸ�λ��1��0��2��1
				return temp0;
		}
	}
}

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

void FindTwoNumsAppearOnce(int *arr,int len,int *num1,int *num2)
{

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

/*
��������int����
*/
void Swap(int *a,int *b)
{
	if(*a != *b)
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}

/*
�ҳ�������ֻ����һ�ε�����
*/
void FindThreeNumsAppearOnce(int *arr,int len,int *num1,int *num2,int *num3)
{
	if(arr==NULL || len<3)
		return;

	*num1 = FindOneNumAppearOnce(arr,len);

	//�ҵ���һ���ҳ������֣��������һ��Ԫ�ؽ��������ڽ�����ʣ�µ���������
	int i;
	for(i=0;i<len;i++)
		if(*num1 == arr[i])
			break;
	Swap(&arr[i],&arr[len-1]);

	FindTwoNumsAppearOnce(arr,len-1,num2,num3);
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

		int num1,num2,num3;
		FindThreeNumsAppearOnce(arr,n,&num1,&num2,&num3);
		printf("%d %d %d\n",num1,num2,num3);
	}
	return 0;
}