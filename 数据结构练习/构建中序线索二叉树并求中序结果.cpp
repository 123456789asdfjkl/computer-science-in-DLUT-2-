#include<stdio.h>
#include<stdlib.h>
typedef enum{
	Link,Thread
}PointerTag;
typedef struct BiThrNode{
	char data;
	struct BiThrNode *lc,*rc;
	PointerTag LTag,RTag;
}BiThrNode,*BiThrTree;
void InThreading(BiThrTree p);
BiThrTree pre;
void CreateBiThrTree(BiThrTree &T)//创建二叉树 
{
	char a;
	scanf("%c",&a);
	if(a=='#')
	{
		T=NULL;
	}
	else
	{
		if(!(T=(BiThrTree)malloc(sizeof(BiThrNode))))
		{
			exit(-2);
		}
		T->data=a;
		CreateBiThrTree(T->lc);
		CreateBiThrTree(T->rc);		
	}	 
}
void InorderThreading(BiThrTree &Thrt,BiThrTree T)
{
	Thrt=(BiThrTree)malloc(sizeof(BiThrNode));
	if(!Thrt)
	{
		exit(-2);	
	}
	Thrt->LTag=Link;
	Thrt->RTag=Thread;
	Thrt->rc=Thrt;
	if(!T)
	{
		Thrt->lc=Thrt;	
	}
	else
	{
		Thrt->lc=T;
		Thrt->LTag=Link;
		pre=Thrt;
		InThreading(T);
		pre->rc=Thrt;
		pre->RTag=Thread;
		Thrt->rc=pre;	
	}	
} 
void InThreading(BiThrTree p)
{
	if(p)
	{
		InThreading(p->lc);
		if(p->lc)
		{
			p->LTag=Link;
		}
		if(p->rc)
		{
			p->RTag=Link;
		}
		if(!p->lc)
		{
			p->LTag=Thread;
			p->lc=pre;
		}
		if(!pre->rc)
		{
			pre->RTag=Thread;
			pre->rc=p;
		}
		pre=p;
		InThreading(p->rc);
	}
}
BiThrTree FirstNode(BiThrTree T)
{
	BiThrTree p;
	p=T;
	while(p->LTag==Link)
	{
		p=p->lc;
	}
	return p;
}
BiThrTree Succ(BiThrTree p)
{
	if(p->RTag==Thread)
	{
		return p->rc;
	}
	else
	{
		p=p->rc;
		while(p->LTag==Link)
		{
			p=p->lc;	
		}
		return p; 
	} 
}
void PrintBiThrTree(BiThrTree Thrt,BiThrTree T)
{
	BiThrTree p;
	for(p=FirstNode(T);p&&p!=Thrt;p=Succ(p))
	{
		printf("%c ",p->data);
	}
	printf("\n");
}
int main()
{
	BiThrTree Thrt,T;
	printf("请先序遍历输入一二叉树：\n");
	CreateBiThrTree(T);
	InorderThreading(Thrt,T);
	printf("该二叉树的中序遍历结果为：\n"); 
	PrintBiThrTree(Thrt,T);
}
