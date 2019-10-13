#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct CSNode{
	char data;
	struct CSNode *fc,*nb;
}CSNode,*CSTree;
typedef struct{
	CSTree a[MAXSIZE];
	int top;
}SeqStack;
typedef struct{
	CSTree c[MAXSIZE];
	int f,r;
}SeqQueue;
void CreateCSTree(CSTree &T)//创建二叉树表示法的树和森林 （采用先序遍历） 
{
	char a;
	scanf("%c",&a);
	if(a=='#')
	{
		T=NULL;
	}
	else
	{
		if(!(T=(CSTree)malloc(sizeof(CSNode))))
		{
			exit(-2);
		}
		T->data=a;
		CreateCSTree(T->fc);
		CreateCSTree(T->nb);		
	}	 
}
void xgbl(CSTree T)//先根遍历树和森林 
{
	CSTree p;
	SeqStack s;
	s.top=-1;
	p=T;
	while(p)
	{
		while(p)
		{
			printf("%c ",p->data);
			if(p->nb)
			{
				if(s.top==MAXSIZE-1)
				{
					exit(-2);
				}
				s.a[++s.top]=p->nb;
			}
			p=p->fc;
		}
		if(s.top!=-1)
		{
			p=s.a[s.top--];
		}
	}
	printf("\n");
}
void hgbl(CSTree T)//后根遍历树和森林 
{
	CSTree p;
	p=T;
	SeqStack s;
	s.top=-1;
	while(p||s.top!=-1)
	{
		while(p)
		{
			if(s.top==MAXSIZE-1)
			{
				exit(-2);
			}
			else
			{
				s.a[++s.top]=p;
				p=p->fc;
			}
		}
		if(s.top!=-1)
		{
			p=s.a[s.top--];
			printf("%c ",p->data);
			p=p->nb;
		}
	}
	printf("\n");
}
void ccbl(CSTree T)//层次遍历树和森林 
{
	CSTree p;
	p=T;
	SeqQueue q;
	q.r=q.f=0;
	while(p)
	{
		while(p)
		{
			printf("%c ",p->data);
			if(p->fc)
			{
				if((q.r+1)%MAXSIZE!=q.f)
				{
					q.c[q.r]=p->fc;
					q.r=(q.r+1)%MAXSIZE;
				}
				else
				{
					exit(-2);
				}
			}
			p=p->nb;
		}
		if(q.f!=q.r)
		{
			p=q.c[q.f];
			q.f=(q.f+1)%MAXSIZE;
		}
	}
	printf("\n");
}
int main()
{
	CSTree T;
	printf("请按先根遍历输入一二叉树表示法构成的森林：\n"); 
	CreateCSTree(T);
	printf("该森林的先根遍历结果为：\n");
	xgbl(T);
	printf("该森林的后根遍历结果为：\n");
	hgbl(T);
	printf("该森林的层次遍历结果为：\n");
	ccbl(T);
}
