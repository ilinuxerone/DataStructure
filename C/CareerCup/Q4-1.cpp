/**********************************************
��Ŀ������
�ж�һ�ö������Ƿ�ƽ�⣬����ƽ�����˼�ǣ�
��������������Ҷ�ӽڵ㵽���ڵ�ľ���֮�����1
Date:2014-04-01
***********************************************/
#include<stdio.h>
#include<stdlib.h>
#define MAX 20  //����Ҷ�ӽڵ���ȵ���������ֵ
int count = 0;   //ȫ�ֱ���������Ҷ�ӽڵ�ĸ���
int Dep[MAX];   //����Ҷ�ӽڵ���ȵ�����
typedef struct BTNode
{
	char data;
	struct BTNode *pLchild;
	struct BTNode *pRchild;
}BTNode, *BTree;

BTree create_tree();
void getDepth(BTree,int);
bool weatherBalance(BTree);

int main()
{
	BTree pTree = create_tree();
	getDepth(pTree,0);
	if(weatherBalance(pTree))
		printf("Balanced\n");
	else
		printf("Not Balanced\n");
	
	return 0;
}

BTree create_tree()
{
	BTree pA = (BTree)malloc(sizeof(BTNode));
	BTree pB = (BTree)malloc(sizeof(BTNode));
	BTree pD = (BTree)malloc(sizeof(BTNode));
	BTree pE = (BTree)malloc(sizeof(BTNode));
	BTree pC = (BTree)malloc(sizeof(BTNode));
	BTree pF = (BTree)malloc(sizeof(BTNode));


	pA->data = 'A';
	pB->data = 'B';
	pD->data = 'D';
	pE->data = 'E';
	pC->data = 'C';
	pF->data = 'F';
	
	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pD;
	pB->pRchild = pE;
	pD->pLchild = pF;
	pD->pRchild = NULL;
	pE->pLchild = pE->pRchild = NULL;
	pC->pLchild = pC->pRchild = NULL;
	pF->pLchild = pF->pRchild = NULL;	
	
	return pA;
}


/*
����ݹ������Ҷ�ӽڵ�����
*/
void getDepth(BTree pTree,int depth)
{
	if(pTree)
	{
		if(pTree->pLchild)
			getDepth(pTree->pLchild,depth+1);

		if(!pTree->pLchild && !pTree->pRchild)
			Dep[count++] = depth;

		if(pTree->pRchild)
			getDepth(pTree->pRchild,depth+1);	
	}
}

/*
�������鱣��ĸ�Ҷ�ӽڵ�����ֵ���жϸ�
*/
bool weatherBalance(BTree pTree)
{
	if(!pTree)
		return true;
	int max = Dep[0];
	int min = Dep[0];
	int i;
	for(i=0;i<count;i++)
	{
		if(max<Dep[i])
			max = Dep[i];
		if(min>Dep[i])
			min = Dep[i];
	}
	if(max-min>1)
		return false;
	else
		return true;
}