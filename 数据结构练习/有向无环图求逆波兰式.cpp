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
	int flag;//顶点的入度 
}VNode; 
typedef struct{
	VNode arc[MAXSIZE];
	int vexnum;//图的顶点数 
	int arcnum;//图的边数 
	int kind;//图的类型 
}Graphs;
typedef struct{
	int num[MAXSIZE];
	int top;
}SeqStack;
int visited[MAXSIZE];
void CreatGraphs(Graphs &G)
{
	int i;
	int j,k;
	ArcNode *p;
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
		G.arc[i].flag=0;	
	}
	printf("请输入各边：\n");
	for(i=1;i<=G.arcnum;i++)
	{
		printf("请输入第%d条边：",i);
		scanf("%d %d",&j,&k);
		p=(ArcNode*)malloc(sizeof(ArcNode));
		p->vex=k;
		p->link=G.arc[j].firstarc;
		G.arc[j].firstarc=p;
		G.arc[k].flag++;		
	} 
}
void DFS(Graphs G,int v)//深度优先搜索 
{
	visited[v]=1;
	printf("%c %d",G.arc[v].data,G.arc[v].flag);
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
void DFSTravers(Graphs G)
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
}
void BFS(Graphs G,int v)//广度优先搜索 
{
	int w;
	ArcNode *p;
	int k;
	int q[MAXSIZE];
	int f=0;
	int r=0;
	visited[v]=1;
	printf("%c",G.arc[v].data);
	q[r++]=v;
	while(f!=r)
	{
		w=q[f++];
		for(p=G.arc[w].firstarc;p!=NULL;p=p->link)
		{
			k=p->vex;
			if(!visited[k])
			{
				visited[k]=1;
				printf("%c",G.arc[k].data);
				if(r==MAXSIZE)
				{
					exit(-2);
				}
				else
				{
					q[r++]=k;
				}
			}
		}
	}
}
void BFSTraverse(Graphs G)
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
			BFS(G,v);
		}
	}
}
void travel(Graphs G)
{
	int i;
	int count=0;
	int num=0;
	int w;
	int a;
	int b; 
	ArcNode *p;
	SeqStack S;
	S.top=-1;
	while(count!=G.vexnum)
	{
		for(i=0;i<G.vexnum;i++)
		{
			if(G.arc[i].flag==0&&(G.arc[i].data=='+'||G.arc[i].data=='-'||G.arc[i].data=='*'||G.arc[i].data=='/'))
			{
				S.top++;
				S.num[S.top]=i;
				G.arc[i].flag=-1;
				for(p=G.arc[i].firstarc;p!=NULL;p=p->link)
				{
					w=p->vex;
					G.arc[w].flag--;
				}
				break;
			}
		}
		count++;
	}
	while(S.top!=-1)
	{
		a=S.num[S.top--];
		for(p=G.arc[a].firstarc;p!=NULL;p=p->link)
		{
			w=p->vex;
			if((G.arc[w].data<='Z'&&G.arc[w].data>='A')||(G.arc[w].data<='z'&&G.arc[w].data>='a'))
				printf("%c",G.arc[w].data);
		}
		printf("%c",G.arc[a].data);
	}
}
int main()
{
	Graphs G;
	CreatGraphs(G);
	DFSTravers(G);
	printf("\n");
	BFSTraverse(G);
	printf("\n");
	travel(G);
	return 0;
}
