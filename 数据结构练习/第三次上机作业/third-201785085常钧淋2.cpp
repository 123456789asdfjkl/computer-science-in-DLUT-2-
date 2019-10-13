#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 100
typedef int InfoType;

typedef struct ArcNode{
	int vex;
	struct ArcNode *link;
	InfoType *info;
}ArcNode;

typedef struct VNode{
	char data;
	ArcNode *firstarc;
}VNode;

typedef struct{
	VNode arc[MAXSIZE];
	int vexnum,arcnum;
	int kind;
}Graphs;
int visited[MAXSIZE];

void Create(Graphs &G)
{
	ArcNode *p,*q;
	int i,k,v1,v2;
	printf("请输入顶点数和边数\n");
	scanf("%d %d",&G.vexnum,&G.arcnum);
	printf("请输入顶点值\n");
	for(i=0;i<G.vexnum;i++)
	{	
		scanf("%c",&G.arc[i].data);
		getchar();
        G.arc[i].firstarc=NULL;//初始化指针
	}
	printf("请输入无向图的每一边(vi,vj)\n");
	for(k=0;k<G.arcnum;k++)
	{
		scanf("%d %d",&v1,&v2);
		getchar();
		p=(ArcNode*)malloc(sizeof(ArcNode));
		q=(ArcNode*)malloc(sizeof(ArcNode));
		p->vex=v2;
		q->vex=v1;
		p->link=G.arc[v1].firstarc;
		G.arc[v1].firstarc=p;
		q->link=G.arc[v2].firstarc;
        G.arc[v2].firstarc=q;
	}
}

void DFS(Graphs G,int v)
{
	visited[v]=1;
	int w;
	ArcNode *p;
	for(p=G.arc[v].firstarc;p!=NULL;p=p->link)
	{
		w=p->vex;
		if(!visited[w])
		{
			DFS(G,w);
		}
	}
}

void yOn(Graphs G)
{
	int v;
	for(v=0;v<G.vexnum;++v)
	{
		visited[v]=0;
	}
	DFS(G,0);
	for(v=0;v<G.vexnum;++v)
	{
		if(visited[v]==0)
		{
			printf("不是");
			return;
		}
	} 
	printf("是");
	return;
} 


int main()
{
	Graphs G;
	printf("创建图的邻接表\n");
    Create(G);
	yOn(G);
	return 0;
}
