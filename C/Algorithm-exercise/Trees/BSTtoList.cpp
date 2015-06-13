#include<stdio.h>
#include<stdlib.h>

typedef struct BSTNode
{
	int data;
	struct BSTNode *left;
	struct BSTNode *right;
}BSTNode,*BSTree;

/*
������ĿҪ��ĸ�ʽ��������������
*/
void CreateBST(BSTree *pRoot)
{
	int data;
	scanf("%d",&data);
	if(data == 0)
		pRoot = NULL;
	else
	{
		*pRoot = (BSTree)malloc(sizeof(BSTNode));
		if(*pRoot == NULL)
			exit(EXIT_FAILURE);
		(*pRoot)->data = data;
		(*pRoot)->left = NULL;
		(*pRoot)->right = NULL;
		CreateBST(&((*pRoot)->left));
		CreateBST(&((*pRoot)->right));
	}
}

/*
������������ķ�ʽ��������ת��Ϊ˫������
*pLasָ��˫����������һ���ڵ�
*/
void ConvertNode(BSTree pRoot,BSTree *pLast)
{
	if(pRoot == NULL)
		return;
	
	//��ת��������
	if(pRoot->left != NULL)
		ConvertNode(pRoot->left,pLast);

	//��˫����������һ���ڵ�����ڵ�������һ��
	pRoot->left = *pLast;
	if(*pLast != NULL)
		(*pLast)->right = pRoot;
	*pLast = pRoot;

	//ת��������
	if(pRoot->right != NULL)
		ConvertNode(pRoot->right,pLast);
}

/*
����˫�������ͷ���
*/
BSTree Convert(BSTree pRoot)
{
	if(pRoot == NULL)
		return NULL;
	if(pRoot->left==NULL && pRoot->right==NULL)
		return pRoot;

	BSTree pLast = NULL;
	ConvertNode(pRoot,&pLast);
	
	//����ͷ���
	BSTree pHead = pLast;
	while(pHead->left != NULL)
		pHead = pHead->left;

	return pHead;
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
			BSTree pRoot = NULL;
			CreateBST(&pRoot);
			BSTree pHead = Convert(pRoot);
			while(pHead != NULL)
			{
				printf("%d ",pHead->data);
				pHead = pHead->right;
			}

			printf("\n");
			free(pRoot);
			pRoot = NULL;
		}
	}
	return 0;
}