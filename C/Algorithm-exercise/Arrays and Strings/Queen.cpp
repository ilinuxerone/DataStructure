#include<stdio.h>

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int count = 0;
/*
����з��������İڷ�����ӡ�����еİڷ�������ʲôҲ����ӡ
*/
void CubVertex(int *A,int len,int begin)
{
	if(A==NULL || len!=8)
		return;

	if(begin == len-1)
	{
		int i,j;
		bool can = true;	//�Ƿ��ַ��������İڷ�
		for(i=0;i<len;i++)
			for(j=i+1;j<len;j++)
				if(i-j==A[i]-A[j] || i-j==A[j]-A[i])
				{
					//�������������һ���Խ����ϣ��򲻷���
					can = false;
					break;
				}
		//�з��ϵİڷ����ʹ�ӡ����
		if(can)
		{
			for(i=0;i<len;i++)
				printf("%d ",A[i]);
			printf("\n");
			count++;
		}
		return;
	}


	int i;
	for(i=begin;i<len;i++)
	{
		swap(&A[begin],&A[i]);
		CubVertex(A,len,begin+1);
		swap(&A[begin],&A[i]);
	}
}

int main()
{
	int A[8] = {0,1,2,3,4,5,6,7};
	CubVertex(A,8,0);
	printf("����%d�ְڷ�\n",count);
	return 0;
}
