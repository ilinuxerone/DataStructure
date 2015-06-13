#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BTNode
{
	int data;
	int rchild;
	int lchild;
}BTNode;

/*
�ж�pTree2�Ƿ�����pTree1�й�ͬ�ĸ��ڵ��pTree1����
*/
bool isSubTree(BTNode *pTree1,int index1,BTNode *pTree2,int index2)
{
	//ǰ����if��䲻�ܵߵ�����Ȼ��pTree1��pTree2��ͬʱ��������Ϊfalse
	if(index2 == -1)
		return true;
	if(index1 == -1)
		return false;
	if(pTree1[index1].data != pTree2[index2].data)
		return false;
	else
		return isSubTree(pTree1,pTree1[index1].lchild,pTree2,pTree2[index2].lchild) &&
			   isSubTree(pTree1,pTree1[index1].rchild,pTree2,pTree2[index2].rchild);
}

/*
�ж�pTree1�Ƿ����pTree2
*/
bool isContainTree(BTNode *pTree1,int index1,BTNode *pTree2,int index2)
{
	if(pTree1==NULL || pTree2==NULL)
		return false;
	if(index1==-1 || index2==-1)
		return false;

	bool result = false;
	if(pTree1[index1].data == pTree2[index2].data)
		result = isSubTree(pTree1,index1,pTree2,index2);

	//���pTree1[index1].lchildΪ-1���´εݹ�ʱ��ͨ��index1==-1���жϷ���false��
	//������ﲻ��Ҫ�ټ���pTree1[index1].lchild!=-1���ж�����
	if(!result)
		result = isContainTree(pTree1,pTree1[index1].lchild,pTree2,index2);
	if(!result)
		result = isContainTree(pTree1,pTree1[index1].rchild,pTree2,index2);

	return result;
}

int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m) != EOF)
	{
		//������pTree1���ڵ��ֵ
		BTNode *pTree1 = NULL;
		if(n>0)
		{
			pTree1 = (BTNode *)malloc(n*sizeof(BTNode));
			if(pTree1 == NULL)
				exit(EXIT_FAILURE);
			int i,data;
			//����n���ڵ��data
			for(i=0;i<n;i++)
			{
				scanf("%d",&data);
				pTree1[i].data = data;
				pTree1[i].rchild = -1;
				pTree1[i].lchild = -1;
			}

			//����n�нڵ����ӹ�ϵ
			for(i=0;i<n;i++)
			{
				int ki;
				scanf("%d",&ki);
				if(ki == 0)
					continue;
				else if(ki == 1)
				{
					int lindex;
					scanf("%d",&lindex);
					pTree1[i].lchild = lindex-1;
				}
				else
				{
					int lindex,rindex;
					scanf("%d",&lindex);
					scanf("%d",&rindex);
					pTree1[i].lchild = lindex-1;
					pTree1[i].rchild = rindex-1;
				}
			}
		}

		//������pTree2���ڵ��ֵ
		BTNode *pTree2 = NULL;
		if(m>0)
		{
			pTree2 = (BTNode *)malloc(m*sizeof(BTNode));
			if(pTree2 == NULL)
				exit(EXIT_FAILURE);
			int i,data;
			//����n���ڵ��data
			for(i=0;i<m;i++)
			{
				scanf("%d",&data);
				pTree2[i].data = data;
				pTree2[i].rchild = -1;
				pTree2[i].lchild = -1;
			}

			//����n�нڵ����ӹ�ϵ
			for(i=0;i<m;i++)
			{
				int ki;
				scanf("%d",&ki);
				if(ki == 0)
					continue;
				else if(ki == 1)
				{
					int lindex;
					scanf("%d",&lindex);
					pTree2[i].lchild = lindex-1;
				}
				else
				{
					int lindex,rindex;
					scanf("%d",&lindex);
					scanf("%d",&rindex);
					pTree2[i].lchild = lindex-1;
					pTree2[i].rchild = rindex-1;
				}
			}
		}

		if(isContainTree(pTree1,0,pTree2,0))
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
