#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*pNode;

/*
��ת�������ط�ת���ͷ���
*/
pNode ReverseList(pNode pHead)
{
	if(pHead == NULL)
		return NULL;
	if(pHead->next == NULL)
		return pHead;

	pNode pCur = pHead;
	pNode pPre = NULL;
	while(pCur != NULL)
	{
		pNode pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	return pPre;
}

/*
�ݹ�ʵ�ַ�ת�������ط�ת���ͷ���
*/
pNode ReverseListRecursivly(pNode pPre,pNode pCur)
{
	if(pCur == NULL)
		return NULL;
	if(pCur->next == NULL)
	{
		pCur->next = pPre;
		return pCur;
	}

	pNode pNext = pCur->next;
	pCur->next = pPre;
	pNode pNewHead = ReverseListRecursivly(pCur,pNext);
	return pNewHead;
}

pNode ReverseList2(pNode pHead)
{
	return ReverseListRecursivly(NULL,pHead);
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		pNode pHead = NULL;
		if(n > 0)
		{
			int i,data;
			scanf("%d",&data);
			pHead =(pNode)malloc(sizeof(Node));
			if(pHead == NULL)
				exit(EXIT_FAILURE);
			pHead->data = data;
			pHead->next = NULL;

			pNode pCur = pHead;
			for(i=0;i<n-1;i++)
			{
				scanf("%d",&data);
				pNode pNew =(pNode)malloc(sizeof(Node));
				if(pNew == NULL)
					exit(EXIT_FAILURE);
				pNew->data = data;
				pNew->next = NULL;
				pCur->next = pNew;
				pCur = pCur->next;
			}
		}

		pNode pNewHead = ReverseList2(pHead);
		if(pNewHead == NULL)
			printf("NULL\n");
		else
		{
			pNode pCur = pNewHead;
			while(pCur != NULL)
			{
				//������ҪʱҪע������ĸ�ʽ
				if(pCur->next == NULL)
					printf("%d\n",pCur->data);
				else
					printf("%d ",pCur->data);
				pCur = pCur->next;
			}
		}
	}
	return 0;
}