#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct ArcNode{
	int vex;//该弧所指向的顶点的位置 
	struct ArcNode *link;//指向下一条弧的指针 
	int *info;//该弧相关信息的指针 
}ArcNode; 
typedef struct VNode{
	char data;
	ArcNode *firstarc;//指向第一条弧时依附该顶点的弧 
}VNode; 
typedef struct{
	VNode arc[MAXSIZE];
	int vexnum;//图的顶点数 
	int arcnum;//图的边数 
	int kind;//图的类型 
}Graphs;
int visited[MAXSIZE];
void CreatGraphs(Graphs &G)//创建有向图或无向图 
{
	int i;
	int j,k;
	ArcNode *p,*q;
	printf("请输入该图的类型（1表示有向图，0表示无向图）\n");
	scanf("%d",&G.kind); 
	printf("请输入顶点数：");
	scanf("%d",&G.vexnum);
	printf("请输入边数：");
	scanf("%d",&G.arcnum);
	printf("请输入顶点：");
	for(i=0;i<G.vexnum;i++)
	{
		getchar();
		scanf("%c",&G.arc[i].data);
		G.arc[i].firstarc=NULL;	
	}
	printf("请输入各边：\n");
	if(G.kind==1)
	{
		for(i=1;i<=G.arcnum;i++)
		{
			printf("请输入第%d条边：",i);
			scanf("%d %d",&j,&k);
			p=(ArcNode*)malloc(sizeof(ArcNode));
			p->vex=k;
			p->link=G.arc[j].firstarc;
			G.arc[j].firstarc=p;		
		}
    }
    else
    {
    	for(i=1;i<=G.arcnum;i++)
		{
			printf("请输入第%d条边：",i);
			scanf("%d %d",&j,&k);
			p=(ArcNode*)malloc(sizeof(ArcNode));
			p->vex=k;
			p->link=G.arc[j].firstarc;
			G.arc[j].firstarc=p;
			q=(ArcNode*)malloc(sizeof(ArcNode));
			q->vex=j;
			q->link=G.arc[k].firstarc;
			G.arc[k].firstarc=q;
					
		}
	}
}
void DFS(Graphs G,int v)//深度优先搜索 
{
	visited[v]=1;
	printf("%c ",G.arc[v].data);
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
void DFS1(Graphs G,int v)//深度优先搜索 
{
	visited[v]=1;
	int w;
	ArcNode *p;
	for(p=G.arc[v].firstarc;p!=NULL;p=p->link)
	{
		w=p->vex;
		if(!visited[w])
		{
			DFS1(G,w);
		}
	}
}
void DFSTravers(Graphs G)//深度优先搜索 
{
	int v;
	for(v=0;v<G.vexnum;++v)
	{
		visited[v]=0;
	}
	for(v=0;v<G.vexnum;++v)
	{
		if(!visited[v])
		{
			DFS(G,v);
		}
	}
	printf("\n"); 
}
void judgeundirected(Graphs G)//判断无向图连通性 
{
	int v;
	for(v=0;v<G.vexnum;++v)
	{
		visited[v]=0;
	}
	DFS1(G,0);
	for(v=0;v<G.vexnum;++v)
	{
		if(!visited[v])
		{
			printf("该无向图不是连通的\n");
			return;
		}
	}
	printf("该无向图是连通的\n");
	
}
void judgedirected(Graphs G)//判断有向图连通性 
{
	int v;
	int i;
	for(i=0;i<G.vexnum;++i)
	{
		for(v=0;v<G.vexnum;++v)
		{
			visited[v]=0;
		}
		DFS1(G,i);
		for(v=0;v<G.vexnum;++v)
		{
			if(!visited[v])
			{
				printf("该有向图不是连通的\n");
				return;
			}
		}
	}
	printf("该有向图是连通的\n");
}
void judge(Graphs G,int i,int j)//判断两节点间是否有路径 
{
	int v;
	for(v=0;v<G.vexnum;++v)
	{
		visited[v]=0;
	}
	DFS1(G,i);
	if(!visited[j])
	{
		printf("%c和%c之间不存在路径\n",G.arc[i].data,G.arc[j].data);
		return;
	}
	printf("%c和%c之间存在路径\n",G.arc[i].data,G.arc[j].data);
}
int main()
{
	Graphs G;
	int i;
	int j;
	CreatGraphs(G);
	DFSTravers(G);
	if(G.kind==0)
	{
		judgedirected(G);
	}
	else
	{
		judgeundirected(G);
	}
	printf("请输入要判断的两个节点：");
	scanf("%d %d",&i,&j);
	judge(G,i,j); 
}
