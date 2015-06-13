#include<stdio.h>
#include<stdlib.h>
typedef struct BTNode
{
	int data;
	struct BTNode *pLchild;
	struct BTNode *pRchild;
}BTNode, *BTree;

/*
���ݸ����ĵ�������ݹ鴴���߶���С�Ķ�������
��ΪҪ�޸�ָ����ڵ��ָ���ָ�����Ҫ����pTree��ָ�룬��BTNode�Ķ���ָ��
*/
void createBTree(BTree *ppTree,int *A,int start,int end)
{
	if(start <= end)
	{
		int mid = (start + end)/2;
		*ppTree = (BTree)malloc(sizeof(BTNode));
		if(*ppTree == NULL)
		{
			printf("malloc faild");
			exit(EXIT_FAILURE);
		}
		(*ppTree)->data = A[mid];
		(*ppTree)->pLchild = NULL;
		(*ppTree)->pRchild = NULL;
		createBTree(&(*ppTree)->pLchild,A,start,mid-1);
		createBTree(&(*ppTree)->pRchild,A,mid+1,end);
	}
}

/*
�����������������ֵ
*/
int max(int a,int b)
{
	return a>b?a:b;
}

/*
������������
*/
int height(BTree pTree)
{
	if(pTree == NULL)
		return 0;
	else
		return max(height(pTree->pLchild),height(pTree->pRchild)) + 1;
}

/*
��������ĵݹ�ʵ��
*/
void in_traverse(BTree pTree)
{
	if(pTree)
	{
		if(pTree->pLchild)
			in_traverse(pTree->pLchild);
		printf("%d ",pTree->data);
		if(pTree->pRchild)
			in_traverse(pTree->pRchild);	
	}
}

int main()
{
	int A[] = {0,1,2,3,4,5,6,7};
	int len = 8;
	BTree pTree;
	createBTree(&pTree,A,0,len-1);
	printf("the height of this tree is %d\n",height(pTree));
	printf("���������Ľ��Ϊ��\n");
	in_traverse(pTree);
	printf("\n");
	return 0;
}