/****************************************************
��Ŀ������
ʵ��һ��ջ��push��pop������min����������ջ����Сֵ����
Ҫ��push��pop��min������ʱ�临�Ӷȶ�ΪO(1)
Date:2014-03-26
*****************************************************/

/*
�������������ģ��ջ
*/
typedef int ElemType;
#define MAX 100  //ջ�����
#include<stdio.h>

/*
��ջ������ָ��Ϊtopʱ����ջA��ѹ������data
*/
bool push(int *A,int &top,ElemType data)
{
	if(top>=MAX-1 || top<-1)
		return false;

	A[++top] = data;
	return true;
}

/*
��ջ������ָ��Ϊtopʱ����ջ
*/
bool pop(int &top)
{
	if(top<0)
		return false;

	top--;
	return true;
}

/*
ջ����ǰ����ָ��Ϊtop��Min����������ҲΪMAX��
��Min����ЧԪ������ջA�е�Ԫ�ظ�����ͬ��
���Ķ�Ӧλ����������ջA��Ӧλ�õ�ջ����һ����Ԫ���е���Сֵ
*/
void minAll(int *A,int *Min,int top)
{
	if(top>MAX-1)
		return ;
	Min[0] = A[0];
	int i;
	for(i=1;i<=top;i++)
	{
		if(Min[i-1] > A[i])
			Min[i] = A[i];
		else
			Min[i] = Min[i-1];
	}
}

/*
����ջ��Ϊtopʱջ��Ԫ�ص���Сֵ
*/
int min(int *Min,int top)
{
	return Min[top];
}

int main()
{
	int A[MAX];
	int top = -1;
	push(A,top,4);
	push(A,top,7);
	push(A,top,2);
	push(A,top,6);
	push(A,top,3);
	push(A,top,8);
	push(A,top,5);
	push(A,top,1);

	int Min[MAX];
	minAll(A,Min,7);
	int i;
	for(i=0;i<=top;i++)
		printf("%d ",Min[i]);
	printf("\n");
	/*
	int min7 = min(Min,7);
	printf("%d\n",min7);
	pop(top);
	int min6 = min(Min,6);
	printf("%d\n",min6);
	*/
	return 0;
}
