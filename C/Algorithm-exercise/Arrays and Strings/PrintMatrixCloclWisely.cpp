#include<stdio.h>
#include<stdlib.h>

/*
˳ʱ���ӡһȦ
*/
void PrintMatrixCirclely(int **num,int m,int n,int start)
{
	int endX = n-start-1;
	int endY = m-start-1;

	int i;
	//�����Ҵ�ӡ��
	for(i=start;i<=endX;i++)
		printf("%d ",num[start][i]);

	//���ϵ��´�ӡ��
	if(start < endY)
	{
		for(i=start+1;i<=endY;i++)
			printf("%d ",num[i][endX]);
	}

	//���������ӡ��
	if(start<endX && start<endY)
	{
		for(i=endX-1;i>=start;i--)
			printf("%d ",num[endY][i]);
	}

	//���µ��ϴ�ӡ��
	if(start<endX && start<endY-1)
	{
		for(i=endY-1;i>=start+1;i--)
		{
			printf("%d ",num[i][start]);
		}
	}
}

/*
˳ʱ���ӡ����
*/
void PrintMatrixClockwisely(int **num,int m,int n)
{
	if(num==NULL || m<=0 || n<=0)
		return;
	int start = 0;
	while(m>2*start && n>2*start)
	{
		PrintMatrixCirclely(num,m,n,start);
		start++;
	}
}

int main()
{
	int m,n;
	while(scanf("%d %d",&m,&n) != EOF)
	{
		int **num = (int **)malloc(m*sizeof(int *));
		if(num == NULL)
			exit(EXIT_FAILURE);
		int i;
		for(i=0;i<m;i++)
		{
			num[i] = (int *)malloc(n*sizeof(int));
			if(num[i] == NULL)
				exit(EXIT_FAILURE);
		}

		int j;
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&num[i][j]);

		PrintMatrixClockwisely(num,m,n);
		printf("\n");

		for(i=0;i<m;i++)
		{
			free(num[i]);
			num[i] = NULL;
		}
		free(num);
		num = NULL;		
	}
	return 0;
}