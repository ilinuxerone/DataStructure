/****************************
��Ŀ������������ģ��һ��ջ
****************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}NODE,*PNODE;

typedef struct Queue
{
	PNODE front;  //��ͷָ��
	PNODE rear;   //��βָ��
}QUEUE,*PQUEUE;

PQUEUE create_queue();
bool is_empty(PQUEUE);
void en_queue(PQUEUE, int);
bool de_queue(PQUEUE,int *);
void destroy_queue(PQUEUE);
void traverse_queue(PQUEUE);
int length(PQUEUE);
void push(PQUEUE,PQUEUE,int);
bool pop(PQUEUE,PQUEUE,int *);

int main()
{
	int pData;         //����������ӵ�Ԫ��ֵ

	//�������в�������Ӳ���
	PQUEUE pS1 = create_queue();
	PQUEUE pS2 = create_queue();
	push(pS1,pS2,4);
	push(pS1,pS2,5);
	printf("the length of pS1: %d\n",length(pS1));
	printf("the length of pS2: %d\n",length(pS2));
	if(pop(pS1,pS2,&pData))
		printf("%d is pop out\n",pData);
	else
		printf("Stack is empty,can not pop\n");
	printf("the length of pS1: %d\n",length(pS1));
	printf("the length of pS2: %d\n",length(pS2));
	push(pS1,pS2,6);
	printf("the length of pS1: %d\n",length(pS1));
	printf("the length of pS2: %d\n",length(pS2));
	push(pS1,pS2,7);
	printf("the length of pS1: %d\n",length(pS1));
	printf("the length of pS2: %d\n",length(pS2));
	if(pop(pS1,pS2,&pData))
		printf("%d is pop out\n",pData);
	else
		printf("Stack is empty,can not pop\n");
	printf("the length of pS1: %d\n",length(pS1));
	printf("the length of pS2: %d\n",length(pS2));	
	if(pop(pS1,pS2,&pData))
		printf("%d is pop out\n",pData);
	else
		printf("Stack is empty,can not pop\n");
	printf("the length of pS1: %d\n",length(pS1));
	printf("the length of pS2: %d\n",length(pS2));
	if(pop(pS1,pS2,&pData))
		printf("%d is pop out\n",pData);
	else
		printf("Stack is empty,can not pop\n");
	printf("the length of pS1: %d\n",length(pS1));
	printf("the length of pS2: %d\n",length(pS2));
	if(pop(pS1,pS2,&pData))
		printf("%d is pop out\n",pData);
	else
		printf("Stack is empty,can not pop\n");

	return 0;
}

/*
����һ���ն��У���ͷָ��Ͷ�βָ�붼ָ��ͷ��㣬
ͷ����в�������ݣ�ֻ���ָ��
*/
PQUEUE create_queue()
{
	PQUEUE pS = (PQUEUE)malloc(sizeof(Queue));
	pS->front = (PNODE)malloc(sizeof(NODE));
	if(!pS || !pS->front)
	{
		printf("pS or front malloc failed!!");
		exit(-1);
	}
	else
	{
		pS->rear = pS->front;
		pS->front->pNext = NULL;
	}
	return pS;
}

/*
�ж϶����Ƿ�Ϊ��
*/
bool is_empty(PQUEUE pS)
{
	if(pS->front == pS->rear)
		return true;
	else
		return false;
}

/*
���Ӻ������Ӷ�β���ӣ���ͷָ�뱣�ֲ���
*/
void en_queue(PQUEUE pS, int e)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if(!pNew)
	{
		printf("pNew malloc failed");
		exit(-1);
	}
	else
	{
		pNew->data = e;
		pNew->pNext = NULL;
		pS->rear->pNext = pNew;
		pS->rear = pNew;
	}
	return;
}

/*
���Ӻ������Ӷ�ͷ���ӣ���βָ�뱣�ֲ��䣬�������һ��Ԫ�س���ʱ��
��Ҫ�Զ�βָ�����¸�ֵ��ʹ��ָ��ͷ���
*/
bool de_queue(PQUEUE pS,int *pData)
{
	if(is_empty(pS))
		return false;
	else
	{
		PNODE p = pS->front->pNext;
		*pData = p->data;
		pS->front->pNext = p->pNext;

		//�����Ƕ���ͷԪ�س��ӵ����������һ������£�ɾ����ͷԪ��ʱ
		//�����޸�ͷ����е�ָ�룬�������������һ��Ԫ�ر�ɾ��ʱ��
		//����βָ��Ҳ��ʧ�ˣ������Զ�βָ�����¸�ֵ��ָ��ͷ��㣩��
		if(pS->rear == p)         
			pS->rear = pS->front;
		free(p);
	}
	return true;
}

/*
�������У��Ӷ�ͷ���β����������е�Ԫ��
*/
void traverse_queue(PQUEUE pS)
{
	if(is_empty(pS))
		printf("there is no data in the queue!\n");
	else
	{	
		PNODE pCurrent = pS->front->pNext; 
		printf("Now datas int the queue are:\n");
		while(pCurrent)
		{
			printf("%d ",pCurrent->data);
			pCurrent = pCurrent->pNext;
		}
		printf("\n");
	}
	return;
}

/*
����еĳ���
*/
int length(PQUEUE pS)
{
	int count = 0;
	PNODE pCurrent = pS->front->pNext; 
	while(pCurrent)
	{
		count++;
		pCurrent = pCurrent->pNext;
	}
	return count;
}

/*
���ٶ���,ͷ���Ҳ������,���Ҳ��pS�ڵ����٣�������ָ��Ϊ�գ����ⴹֱָ��Ĳ���
*/
void destroy_queue(PQUEUE pS)
{
	if(is_empty(pS))
		return;
	else
	{
		while(pS->front)
		{
			pS->rear = pS->front->pNext;
			free(pS->front);
			pS->front = pS->rear;
		}
	}
	free(pS);
	pS = 0;
	return;
}

/*
����������ģ����ջ����
*/
void push(PQUEUE pS1,PQUEUE pS2,int val)
{
	if(is_empty(pS2))
		en_queue(pS1, val);
	else
		en_queue(pS2, val);
}

/*
����������ģ���ջ����
*/
bool pop(PQUEUE pS1,PQUEUE pS2,int *pData)
{
	if(is_empty(pS1) && is_empty(pS2))
		return false;

	int DelData;
	if(!is_empty(pS2))
	{
		int len = length(pS2);
		while(len-- > 1)
		{
			de_queue(pS2,&DelData);
			en_queue(pS1,DelData);
		}
		//�����е����һ��Ԫ�س��ӣ���Ϊ��ջԪ��
		de_queue(pS2,pData);
		return true;
	}
	if(!is_empty(pS1))
	{
		int len = length(pS1);
		while(len-- > 1)
		{
			de_queue(pS1,&DelData);
			en_queue(pS2,DelData);
		}
		//�����е����һ��Ԫ�س��ӣ���Ϊ��ջԪ��
		de_queue(pS1,pData);
		return true;
	}
}