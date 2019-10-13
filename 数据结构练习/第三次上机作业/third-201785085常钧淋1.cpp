#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct CSNode{
	char data;
	struct CSNode *fc,*nb;
}CSNode,*CSTree;
//森林的孩子兄弟表示法

typedef struct
{CSTree data[MAXSIZE];
int top;
}SeqStack;
//栈

typedef struct
{CSTree data[MAXSIZE];
int f,r;
}SeQueue;
//队列

void CreateCSTree(CSTree &T)
{
	char ch;
	scanf("%c",&ch);
    if(ch=='#')
		T=NULL;
	else
	{
		T=(CSNode*)malloc(sizeof(CSNode));
		T->data=ch;
		CreateCSTree(T->fc);
		CreateCSTree(T->nb);
	}
}
//以二叉链表存储的方式创建森林

void InorderTraverse(CSTree T)
{
	SeqStack s;
	CSTree p;
	s.top=-1;
	p=T;
	while(p||(s.top!=-1))
	{
		while(p)
		{
		 if(s.top==MAXSIZE-1)
		   exit(0);
		 s.data[++s.top]=p;
		 p=p->fc;
		}
		if(s.top!=-1)
		{
			p=s.data[s.top--];
			printf("%c",p->data);
			p=p->nb;
		}
	}
	printf("\n");
}
//实现森林的中序遍历

void count(CSTree &T)
{
   CSTree p;
   SeQueue q;
   int count=0;
   q.f=0;
   q.r=0;
   if(!T)
     printf("此森林为空，叶子结点数为%d",count);
   q.data[q.r++]=T;
   while(q.f!=q.r)
   {
	   p=q.data[q.f++];
	   if(!p->fc)
	     count++;
	   else
		   q.data[q.r++]=p->fc;
       if(p->nb)
	    q.data[q.r++]=p->nb;
   }
   printf("此森林的叶子结点数为%2d",count);
   printf("\n");
}
//计算森林中叶子结点的个数

void yOn(CSTree &T)
{
   CSTree p;
   SeQueue q;
   int k=0;
   q.f=0;
   q.r=0;
   if(T==NULL)
   {
	   printf("此二叉树为完全二叉树\n");
       return;
   }
   q.data[q.r++]=T;
   while(k!=1)
   {
	   p=q.data[q.f++];
	   if(p->fc==NULL)
	   {   if(p->nb!=NULL)
		    printf("此二叉树不是完全二叉树\n");
	   else
	        k=1;
	   }
	   else
	   {
		   q.data[q.r++]=p->fc;
		   if(p->nb!=NULL)
			   q.data[q.r++]=p->nb;
		   else
		   k=1;
	   }
   }
   while(q.f!=q.r)
   {
	   p=q.data[q.f++];
	   if((p->fc!=NULL)||(p->nb!=NULL))
	   { 
		  printf("此二叉树不是完全二叉树\n");
	      return;
	   }
   }
    printf("此二叉树为完全二叉树\n");
}
//判断森林对应的二叉树是否为完全二叉树

int main()
{
	CSTree T;
	printf("输入以二叉链表存储的森林:\n");
    CreateCSTree(T);
	InorderTraverse(T);
	count(T);
    yOn(T);
    return 0;
}
