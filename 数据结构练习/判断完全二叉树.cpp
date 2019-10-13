#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct BiTNode{
	char data;
	struct BiTNode *lc,*rc;
}BiTNode ,*BiTree;
typedef struct{
	BiTree b[MAXSIZE];
	int f;
	int r;
}SeqQueue;//创建队列 
void CreateBiTree(BiTree &T)//创建二叉树 （采用先序遍历） 
{
	char a;
	scanf("%c",&a);
	if(a=='#')
	{
		T=NULL;
	}
	else
	{
		if(!(T=(BiTree)malloc(sizeof(BiTNode))))
		{
			exit(-2);
		}
		T->data=a;
		CreateBiTree(T->lc);
		CreateBiTree(T->rc);		
	}	 
}
void judge(BiTree &T)//判断是否为完全二叉树 
{
	BiTree p;
	SeqQueue q;
	p=T;
	q.r=q.f=0;
	q.b[q.r++]=p;
	while(p&&q.f!=q.r)
	{
		if(p->lc&&p->rc)
		{
			q.b[q.r++]=p->lc;
			q.b[q.r++]=p->rc;
		}
		if(p->rc&&!p->lc)
		{
			printf("该二叉树不是完全二叉树\n");
			return;
		}
		if((p->lc&&!p->rc)||(!p->lc&&!p->rc))
		{
			while(q.f!=q.r-1)
			{
				if(q.b[++q.f]->lc||q.b[++q.f]->rc)
				{
					printf("该二叉树不是完全二叉树\n");
					return;
				}
			}
			printf("该二叉树是完全二叉树\n");
			return;
		}
		p=q.b[++q.f]; 
	}
	printf("该二叉树是完全二叉树\n");
	return;
	
}
int main()
{
	BiTree T;
	CreateBiTree(T);
	judge(T);	
} 
