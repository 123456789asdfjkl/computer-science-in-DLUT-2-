#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
	char data;
	struct BiTNode *lc,*rc;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T)//创建二叉树 
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
void exchange(BiTree T)//递归算法交换所有结点的左右孩子 
{
	BiTree p; 
	if(T->lc||T->rc)
	{
		p=T->lc;
		T->lc=T->rc;
		T->rc=p;
		if(T->lc)
		{
			exchange(T->lc);
		}
		if(T->rc)
		{
			exchange(T->rc);
		}
	}
}
void xxbl(BiTree &T)//递归法二叉树先序遍历 
{
	if(T)
	{
		printf("%c",T->data);
		xxbl(T->lc);
		xxbl(T->rc);
	}
}
void zxbl(BiTree &T)//递归法二叉树中序遍历 
{
		if(T)
	{
		zxbl(T->lc);
		printf("%c",T->data);
		zxbl(T->rc);
	}
}
int main()
{
	BiTree T;
	printf("请按先序遍历输入一二叉树："); 
	CreateBiTree(T);
	printf("交换前先序遍历的结果为："); 
	xxbl(T);
	printf("\n");
	printf("交换前中序遍历的结果为:");
	zxbl(T);
	printf("\n"); 
	exchange(T);
	printf("交换后先序遍历的结果为:");
	xxbl(T);
	printf("\n");
	printf("交换后中序遍历的结果为:");
	zxbl(T);
	printf("\n");	
} 
