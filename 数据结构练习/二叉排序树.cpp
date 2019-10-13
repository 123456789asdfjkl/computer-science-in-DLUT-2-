#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct 
{
	BiTree data[MAX];
	int top;
}SeqStack;
void CreatBiTree(BiTree &T)//创建二叉树，采用先序遍历 
{
	int ch;
	scanf("%d",&ch);
	if(ch==0)
	{
		T=NULL;
	}
	else
	{
		if(!(T=(BiTree)malloc(sizeof(BiTree))))
		{
			exit(-2);
		}
		T->data=ch;
		CreatBiTree(T->lchild);
		CreatBiTree(T->rchild);
	}
}
int IsBalance(BiTree &T)//判断二叉树是否为二叉排序树 
{	
	SeqStack S;
	BiTree p;
	S.top=-1;
	int k=0;
	int flag=1; 
	p=T;
	while(p||S.top!=-1)
	{
		while(p)
		{
			if(S.top==MAX-1)
			{
				exit(0);
			}
			S.data[++S.top]=p;
			p=p->lchild;
		}
		if(S.top!=-1)
		{
			p=S.data[S.top--];
			if(k<p->data)
			{
				k=p->data;
			}
			else
			{
				printf("不是二叉排序树\n"); 
				flag=0;
				return 0;
			}
			p=p->rchild;
		}
	}
	if(flag)
	{
		printf("是二叉排序树\n");
		return 1;
	}
}
void isexist(BiTree &T,int k)//判断是否存在值为k的节点 
{
	BiTree p;
	p=T;
	int flag=0;
	while(p)
	{
		if(k==p->data)
		{
			printf("存在\n");
			flag=1;
			return;
		}
		if(k>p->data)
		{
			p=p->rchild;
		}
		if(k<p->data)
		{
			p=p->lchild;
		}
	}
	if(!flag)
	{
		printf("不存在\n");
	}
	
}
int main()
{
	BiTree T;
	int k,l;
	CreatBiTree(T);
	l=IsBalance(T);
	if(l)
	{
	
		scanf("%d",&k);
		isexist(T,k);
	}
	return 0;
} 
