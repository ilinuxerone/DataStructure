/****************************************************
��Ŀ������
��һ������ʵ������ջ
Date:2014-03-27
*****************************************************/
typedef int ElemType;
#define MAX 100  //����ջ�������
#include<stdio.h>

typedef struct node
{
	ElemType data;
	int next;	//ָ���ջ����һ��Ԫ��,���û����һ��Ԫ�أ�����nextΪ-1
}node;


/*
�ڸ�ջ��������ָ��Ϊtopʱ����ջA��ѹ������data
count������¼�������Ԫ������ջ��ջ��λ��
*/
bool push(node *A,int &count,int &top,ElemType data)
{
	if(count>=MAX-1 || count<-1 || top>count || top<-1)
		return false;

	count++;
	A[count].data = data;
	A[count].next = top;
	top = count; 
	return true;
}

/*
�ڸ�ջ������ָ��Ϊtopʱ����ջ
count������¼�������Ԫ������ջ��ջ��λ��
*/
bool pop(node *A,int &count,int &top)
{
	if(top<0 || top>count)
		return false;
	if(top == count)
		count--;
	A[top].data = -10;  //����Ϊ�˱��ڹ۲�pop������������ջ���λ�õ�Ԫ���趨Ϊ-10
	top = A[top].next;
	return true;
}


int main()
{
	int top1 = -1;
	int top2 = -1;
	int top3 = -1;
	int count = -1;
	node A[MAX];
	push(A,count,top1,1);
	push(A,count,top2,2);
	push(A,count,top3,3);
	push(A,count,top1,4);
	push(A,count,top3,5);
	push(A,count,top3,6);
	push(A,count,top2,7);
	push(A,count,top1,8);
	int i;
	printf("After pushed:\n");
	for(i=0;i<8;i++)
		printf("A[%d].data = %d,A[%d].next = %d\n",i,A[i].data,i,A[i].next);

	pop(A,count,top3);
	pop(A,count,top2);
	pop(A,count,top1);
	printf("After popd:\n");
	for(i=0;i<8;i++)
		printf("A[%d].data = %d,A[%d].next = %d\n",i,A[i].data,i,A[i].next);
	return 0;
}