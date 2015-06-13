/*
�������������ģ��ջ
*/
typedef int ElemType;
#define MAX 100000 //ջ�����
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int top = -1;
/*
��ջ������ָ��Ϊtopʱ����ջA��ѹ������data
*/
bool push(int *A,ElemType data)
{
	if(top>=MAX-1 || top<-1)
		return false;

	A[++top] = data;
	return true;
}

/*
��ջ������ָ��Ϊtopʱ����ջ
*/
bool pop()
{
	if(top<0)
		return false;

	top--;
	return true;
}

/*
�ж�popList�Ƿ���pushList�ĵ�������
*/
bool IsPopOrder(int *pushList,int *popList,int len,int *stack)
{
	if(popList==NULL || pushList==NULL || len<1)
		return false;

	int i;
	int pushIndex = 0;
	for(i=0;i<len;i++)
	{
		while(top==-1 || stack[top] != popList[i])
		{
			//���û��Ԫ�ؿ���push�ˣ���˵��������
			if(pushIndex == len)
				return false;
			push(stack,pushList[pushIndex++]);
		}
		pop();
	}
	return true;
}

int main()
{
	int n;
	int stack[MAX]; //����ջ
	while(scanf("%d",&n) != EOF)
	{
		int *pushList = (int *)malloc(n*sizeof(int));
		if(pushList == NULL)
			exit(EXIT_FAILURE);
		int i;
		for(i=0;i<n;i++)
			scanf("%d",pushList+i);

		int *popList = (int *)malloc(n*sizeof(int));
		if(popList == NULL)
			exit(EXIT_FAILURE);
		for(i=0;i<n;i++)
			scanf("%d",popList+i);

		if(IsPopOrder(pushList,popList,n,stack))
			printf("Yes\n");
		else
			printf("No\n");

		free(pushList);
		pushList = NULL;
		free(popList);
		popList = NULL;
	}
	return 0;
}