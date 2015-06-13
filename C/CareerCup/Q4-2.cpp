/**********************************
��Ŀ������
����һ������ͼ������㷨�ж��������Ƿ����·��
Date:2014-04-08
**********************************/
#define NUM 4          //ͼ�ж���ĸ���
bool visited[NUM];   //����ȫ�ֱ����������飬��������ÿ���ڵ�ķ�����Ϣ
/*
���ڽӱ���Ϊͼ�Ĵ洢�ṹ
���ڽӱ��У���һ��һά����洢ͼ�е�ÿ���������Ϣ��
ͬʱΪÿ�����㽨��һ�������������еĽڵ㱣�������ڸö����ϵı߻򻡵���Ϣ
*/
typedef struct node
{	//�����е�ÿ���ڵ㣬���������ڸýڵ��ϵı߻򻡵���Ϣ
	int vertex;          //������ͼ�б�ʾ�û���ָ��Ķ��㣨����ͷ����λ�ã�
				         //������ͼ�б�ʾ�����ڸñ��ϵ���һ�������λ��
	struct node *pNext;  //ָ����һ�������ڸö����ϵĻ����
}Node;
typedef struct head
{	//�����е�ÿ��Ԫ�أ�����ͼ��ÿ������������Ϣ
	char data;          //�����������
	Node *first;        //������ͼ�У�ָ���Ըö���Ϊ��β�ĵ�һ����
						//������ͼ�У�ָ�������ڸö����ϵĵ�һ����
}Head,*Graph;           //��̬�������鱣��ÿ������������Ϣ


//����ͼ��������Ӧ��ͼ
Graph create_graph();

//����ͼ��ָ����Ŷ���ĵ�һ���ڽӵ�
int first_vertex(Graph,int);

//����ͼ��ָ����Žڵ����һ���ڽӵ�
int next_vertex(Graph,int,int);

//DFS����·���Ķ����ַ�
void DFS(Graph, int);

//�ж��������Ƿ���ͨ
bool isArrived(Graph,int,int);

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	Graph Gp = create_graph();

	memset(visited,0,sizeof(visited));
	if(isArrived(Gp,3,2))
		printf("D To C Existed\n");
	else
		printf("D To C Not Existed\n");

	if(isArrived(Gp,1,2))
		printf("B To C Existed\n");
	else
		printf("B To C Not Existed\n");

	if(isArrived(Gp,3,1))
		printf("D To B Existed\n");
	else
		printf("D To B Not Existed\n");

	if(isArrived(Gp,0,3))
		printf("A To D Existed\n");
	else
		printf("A To D Not Existed\n");
	int i;
	//�ͷŵ�Ϊÿ����������������ڴ�
	for(i=0;i<NUM;i++)
	{
		free(Gp[i].first);
		Gp[i].first = 0;  //��ֹ����ָ��Ĳ���
	}

	//�ͷŵ�Ϊ����������������ڴ�
	free(Gp);
	Gp = 0;
	return 0;
}


/*
����ͼ��������Ӧ��ͼ
*/
Graph create_graph()
{
	//Ϊ���涥�������Ϣ���������ռ䣬����������ֵ
	Graph graph = (Graph)malloc(NUM*sizeof(Head));
	int i;
	//�������Ű�������˳���0�������
	for(i=0;i<NUM;i++)
		graph[i].data = 'A' + i;
	
	//Ϊÿ���ڵ��Ӧ�ĵĵ������еĽڵ����ռ�
	Node *p00 = (Node *)malloc(sizeof(Node));
	Node *p20 = (Node *)malloc(sizeof(Node));
	Node *p21 = (Node *)malloc(sizeof(Node));
	Node *p30 = (Node *)malloc(sizeof(Node));

	//Ϊ���������еĽڵ��������Ը�ֵ
	p00->vertex = 1;
	p00->pNext = NULL;
	p20->vertex = 0;
	p20->pNext = p21;
	p21->vertex = 3;
	p21->pNext = NULL;
	p30->vertex = 0;
	p30->pNext = NULL;

	//��������ÿ����������������
	graph[0].first = p00;	
	graph[1].first = NULL;
	graph[2].first = p20;	
	graph[3].first = p30;

	return graph;
}

/*
����ͼGp��pos���㣨���Ϊpos�Ķ��㣩�ĵ�һ���ڽӶ������ţ���������ڣ��򷵻�-1
*/
int first_vertex(Graph Gp,int pos)
{
	if(Gp[pos].first)  //��������ڽӶ��㣬���ص�һ���ڽӶ�������
		return 	Gp[pos].first->vertex;
	else              //��������ڣ��򷵻�-1
		return -1;
}

/*
cur������pos���㣨cur��pos��Ϊ�������ţ�������һ���ڽӶ��㣬
����ͼGp�У�pos����ģ������cur���㣩��һ���ڽӶ�������,��������ڣ��򷵻�-1
*/
int next_vertex(Graph Gp,int pos,int cur)
{
	Node *p = Gp[pos].first; //p��ʼָ�򶥵�ĵ�һ���ڽӵ�
	//ѭ��pos�ڵ��Ӧ������ֱ��pָ�����Ϊcur���ڽӵ�
	while(p->vertex != cur)
		p = p->pNext;

	//������һ���ڵ�����
	if(p->pNext)
		return p->pNext->vertex; 
	else 
		return -1;
}

/*
DFS��������·���Ķ����ַ�
*/
int count = 0;
char BL[NUM];	//�����������·���Ķ����ַ�
void DFS(Graph Gp, int begin)
{
	BL[count++] = Gp[begin].data;
	visited[begin] = true; 

	//ѭ�����ʵ�ǰ�ڵ�������ڽӵ㣨���ýڵ��Ӧ������
	int i;
	for(i=first_vertex(Gp,begin); i>=0; i=next_vertex(Gp,begin,i))
	{
		if(!visited[i])  //������δ�������ڽӽڵ㣬�ݹ����DFS
			  DFS(Gp,i);
	}
} 

/*
�ж����������Ƿ���ͨ
*/
bool isArrived(Graph Gp,int begin,int end)
{
	DFS(Gp,begin);
	int i;
	for(i=0;i<count;i++)
		if(BL[i] == Gp[end].data)
			return true;
	return false;
}

