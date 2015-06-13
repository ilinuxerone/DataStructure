/*
�������������ģ��ջ
*/
typedef int ElemType;
#define MAX 100000  //ջ�����
#include<stdio.h>
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
ջ����ǰ����ָ��Ϊtop��Min����������ҲΪMAX��
��Min����ЧԪ������ջA�е�Ԫ�ظ�����ͬ��
���Ķ�Ӧλ����������ջA��Ӧλ�õ�ջ����һ����Ԫ���е���Сֵ
*/
void minAll(int *A,int *Min)
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
int min(int *Min)
{
	return Min[top];
}

int main()
{

	int n;
	int A[MAX];
	int Min[MAX];

	while(scanf("%d",&n) != EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
			char ci;
			while(getchar() != '\n')
				continue;
			scanf("%c",&ci);
			if(ci == 's')
			{
				ElemType k;
				scanf("%d",&k);
				push(A,k);
			}
			if(ci == 'o')
			{
				pop();
			}
			
			minAll(A,Min);
			if(top<0)
				printf("NULL\n");
			else
				printf("%d\n",min(Min));
		}
	}
	return 0;
}
