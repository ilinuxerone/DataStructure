#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	int index;	//�ڵ��ţ���1��ʼ���㣩
	int pNext;
	int pSibling;	//����ָ��
}Node;

/*������ʵ�ַǳ���*/
void CloneList(Node *pHead,Node *pClone,int len)
{
	if(pHead == NULL)
		return;
	int i;
	for(i=1;i<len;i++)
	{
		pClone[i].data = pHead[i].data;
		pClone[i].index = pHead[i].index;
		pClone[i].pNext = pHead[i].pNext;
		pClone[i].pSibling = pHead[i].pSibling;
	}
}



int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		Node *pHead = NULL;
		if(n>0)
		{
			//����n+1���ڵ�ռ䣬�ճ�����һ���������ڵ��žʹ�1��ʼ
			pHead = (Node *)malloc((n+1)*sizeof(Node));
			if(pHead == NULL)
				exit(EXIT_FAILURE);
			int i,data;
			for(i=1;i<n+1;i++)
			{
				scanf("%d",&data);
				pHead[i].data = data;
				pHead[i].index = i;
				if(i == n)
					pHead[i].pNext = 0;
				else
					pHead[i].pNext = i+1;
				pHead[i].pSibling = 0;
			}

			int ti;
			for(i=1;i<n+1;i++)
			{
				scanf("%d",&ti);
				pHead[i].pSibling = ti;
			}
		}

		Node *pClone = (Node *)malloc((n+1)*sizeof(Node));
		if(pClone == NULL)
			exit(EXIT_FAILURE);
		CloneList(pHead,pClone,n+1);

		int i;
		for(i=1;i<n+1;i++)
		{
			printf("%d ",pClone[i].data);
			if(pClone[i].pSibling != 0)
				printf("%d\n",pClone[pClone[i].pSibling].data);
			else
				printf("%d\n",pClone[i].pSibling);
		}

		free(pHead);
		pHead = NULL;
		free(pClone);
		pClone = NULL;
	}
	return 0;
}
