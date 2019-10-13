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
void xxbl(BiTree &T)//递归法二叉树先序遍历求前缀表达式即波兰式 
{
	if(T)
	{
		printf("%c",T->data);
		xxbl(T->lc);
		xxbl(T->rc);
	}
}
void zxbl(BiTree &T)//递归法二叉树中序遍历求中缀表达式 
{
		if(T)
	{
		zxbl(T->lc);
		printf("%c",T->data);
		zxbl(T->rc);
	}
}
void hxbl(BiTree &T)//递归法二叉树后序遍历求后缀表达式即逆波兰式 
{
		if(T)
	{
		hxbl(T->lc);
		hxbl(T->rc);
		printf("%c",T->data);
	}
}
int main()
{
	BiTree T;
	printf("请输入前缀缀表达式：\n");
	CreateBiTree(T);
	printf("该表达式的波兰式:\n");
	xxbl(T);
	printf("\n");
	printf("该表达式的中缀表达式:\n");
	zxbl(T);
	printf("\n");
	printf("该表达式的逆波兰式:\n");
	hxbl(T);
	printf("\n");
	return 0;
}
