/*********************************************************
��Ŀ������
��ջ�����������У��������е���˼��Ԫ�ش�ջ�׵�ջ����������
Date:2014-03-29
**********************************************************/

/**************************************************************************************************************
����Ϊ����ջ���㷨����ջΪ��̬ջ��
�ڸ�ջ�У�pTopָ��Ľڵ��д�Ÿ�ջ��ջ������
pBottomָ��Ľڵ����һ���ڵ��Ÿ�ջ��ջ�����ݣ�pBottomָ��Ľڵ��в������Ч���ݣ�
��������Ŀ����Ϊ���ڽ�����ջ�ͳ�ջʱ�����ջ�Ĳ��������ÿ����������
**************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,*PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;

PSTACK create_stack();
void push_stack(PSTACK,int);
void traverse_stack(PSTACK);
bool pop_stack(PSTACK,int *);
bool is_empty(PSTACK);
void clear_stack(PSTACK);
PSTACK sort_stack(PSTACK);

int main()
{	

	//����һ���յ�ջ��pSָ��ָ���ջ
	PSTACK pS = create_stack();
	push_stack(pS,4);
	push_stack(pS,3);
	push_stack(pS,7);
	push_stack(pS,1);
	push_stack(pS,5);
	push_stack(pS,9);
	push_stack(pS,2);
	push_stack(pS,6);

	printf("Befote Sorted:\n");
	traverse_stack(pS);
	PSTACK pS1 = sort_stack(pS);
	printf("After Sorted:\n");
	traverse_stack(pS1);
	return 0;
}

/*
����һ����ջ,������ָ���ջ��ָ��
*/
PSTACK create_stack()
{
	PSTACK pS = (PSTACK)malloc(sizeof(STACK));
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if(NULL==pS || NULL==pS->pTop)
	{
	   printf("malloc failed");
	   exit(-1);
	}	
	else
	{
	   pS->pBottom = pS->pTop;
	   pS->pBottom->pNext = NULL;
	}
	
	return pS;
}

/*
�жϸ�ջ�Ƿ�Ϊ��
*/
bool is_empty(PSTACK pS)
{
	if(pS->pTop == pS->pBottom)
	   return true;
    else
	   return false;
}

/*
��pSָ��ָ���ջ��ѹ������val
*/
void push_stack(PSTACK pS,int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(NULL==pNew)
	{
	   printf("malloc failed");
	   exit(-1);
	}	
	else
	{
	   pNew->data = val;
	   pNew->pNext = pS->pTop;
	   pS->pTop = pNew;
	}	
	return ;
}

/*
��ջ���Ƴ����ݣ������Ƴ������ݱ�����pDataָ����ָ���λ��
*/
bool pop_stack(PSTACK pS,int *pData)
{
	if(is_empty(pS))
	   return false;
	else
	{
	   PNODE p = pS->pTop;
	   *pData = p->data;
	   pS->pTop = p->pNext;
	   free(p);
	   p = NULL;
	   return true;
	}
}

/*
����ջ������ջ����ջ�����ջ�е�����
*/
void traverse_stack(PSTACK pS)
{
	PNODE pCurrent = pS->pTop; 
	while(pCurrent != pS->pBottom)
       {
	   printf("%d ",pCurrent->data);
	   pCurrent = pCurrent->pNext;
	}
	printf("\n");
	return ;
}

/*
���ջ�������仹ԭΪ��ջ
*/
void clear_stack(PSTACK pS)
{
	if(is_empty(pS))
	   return ;
	else
	{
	   PNODE p = pS->pTop;
	   PNODE r = NULL;
	   while(p != pS->pBottom)
	   {
			r = p->pNext;
			free(p);
			p = r;
	   }
	   pS->pTop = pS->pBottom;
   	}
}

/*
��ջ����ģ������������
*/
PSTACK sort_stack(PSTACK pS)
{
	PSTACK pS1 = create_stack();

	while(!is_empty(pS))
	{
		int pop_pSData;
		pop_stack(pS,&pop_pSData);
		while(!is_empty(pS1) && pop_pSData<pS1->pTop->data)
		{
			int pop_pS1Data;
			pop_stack(pS1,&pop_pS1Data);
			push_stack(pS,pop_pS1Data);
		}
		push_stack(pS1,pop_pSData);
	}
	return pS1;
}
