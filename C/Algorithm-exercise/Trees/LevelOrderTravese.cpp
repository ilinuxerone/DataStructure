#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
�������Ĵ洢�ṹ
*/
typedef struct BTNode
{
	int data;
	int rchild;
	int lchild;
}BTNode;

/*
���еĴ洢�ṹ
*/
typedef struct Node
{
	BTNode data;
	struct Node *pNext;
}NODE,*PNODE;

typedef struct Queue
{
	PNODE front;  //��ͷָ��
	PNODE rear;   //��βָ��
}QUEUE,*PQUEUE;


/*
����һ���ն��У���ͷָ��Ͷ�βָ�붼ָ��ͷ��㣬
ͷ����в�������ݣ�ֻ���ָ��
*/
PQUEUE create_queue()
{
	PQUEUE pS = (PQUEUE)malloc(sizeof(QUEUE));
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
void en_queue(PQUEUE pS, BTNode e)
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
bool de_queue(PQUEUE pS,BTNode *pData)
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
�������������
*/
void LevelTraverse(BTNode *pTree,int index,int *LevTraverse,int n)
{
	if(pTree == NULL)
		return;
	if(index == -1)
		return;

	BTNode pBTNode;
	PQUEUE pS = create_queue();
	en_queue(pS, pTree[0]);
	int i = 0;
	while(!is_empty(pS) && i<n)
	{
		de_queue(pS,&pBTNode);
		//ͬ�����Ȱ�Ԫ�ذ����������˳�򱣴�����
		LevTraverse[i++] = pBTNode.data;
		if(pBTNode.lchild != -1)
			en_queue(pS, pTree[pBTNode.lchild]);
		if(pBTNode.rchild != -1)
			en_queue(pS, pTree[pBTNode.rchild]);
	}

	destroy_queue(pS);
}


int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		//������pTree���ڵ��ֵ
		BTNode *pTree = NULL;
		if(n>0)
		{
			pTree = (BTNode *)malloc(n*sizeof(BTNode));
			if(pTree == NULL)
				exit(EXIT_FAILURE);
			int i,data;
			//����n���ڵ��data
			for(i=0;i<n;i++)
			{
				scanf("%d",&data);
				pTree[i].data = data;
				pTree[i].rchild = -1;
				pTree[i].lchild = -1;
			}

			//����n�нڵ����ӹ�ϵ
			for(i=0;i<n;i++)
			{
				char ci;
				//�����е�������Ϊ�������������еĻ��з�
				//���ﲻ����fflush(stdin)��gcc��֧�֣���ֻ��һЩ�������Լӵģ�
				//������ˣ�����ϵͳ�ᱨRE��
				while(getchar() != '\n')
					continue;
				scanf("%c",&ci);
				if(ci == 'z')
					continue;
				else if(ci == 'l')
				{
					int lindex;
					scanf("%d",&lindex);
					pTree[i].lchild = lindex-1;
				}
				else if(ci == 'r')
				{
					int rindex;
					scanf("%d",&rindex);
					pTree[i].rchild = rindex-1;
				}
				else if(ci == 'd')
				{
					int lindex,rindex;
					scanf("%d",&lindex);
					scanf("%d",&rindex);
					pTree[i].lchild = lindex-1;
					pTree[i].rchild = rindex-1;
				}
			}
		}
		
		
		//�Ƚ�������Ԫ�����α��浽preTraverse������
		int *LevTraverse = (int *)malloc(n*sizeof(int));
		if(LevTraverse == NULL)
			exit(EXIT_FAILURE);
		LevelTraverse(pTree,0,LevTraverse,n);
		int i;
		for(i=0;i<n;i++)
		{
			//ʹ������ϲ���ϵͳҪ��ĸ�ʽ
			if(i == n-1)
				printf("%d\n",LevTraverse[i]);
			else
				printf("%d ",LevTraverse[i]);	
		}

		free(LevTraverse);
		LevTraverse = NULL;

		free(pTree);
		pTree = NULL;
	}
	return 0;
}