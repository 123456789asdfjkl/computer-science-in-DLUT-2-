#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int LNode;

typedef struct Ploy
{
	float coef;
	int expn;
	struct Ploy *next;
}Polynode,*LinkedList;
// 定义多项式线性链表

void Creat(LinkedList L)
{
	L=(LinkedList) malloc(sizeof(LNode));
	L->next=NULL;
} 
// 创建带表头的空单链表 

void ListInput(LinkedList L) 
{
	int n,i;
	LinkedList p,q;
	L=(LinkedList) malloc(sizeof(LNode));
	L->next=NULL;
	q=L->next;
	printf("Input the length of ploy:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		LinkedList p=(LinkedList)malloc (sizeof(LNode));
		printf("please input the coef of ploy:\n");
		scanf("%f",&p->coef);
		printf("please input the expn of ploy:\n");
		scanf("%d",&p->expn);
		q->next=p;
		q=p;
	}
	q->next=NULL;
	
}
// 建立带表头的单链表存放一元多项式

void ListOutput(LinkedList L)
{ 
	LinkedList p;
	p=L->next;
	do
	{
	 	printf("系数为%.2f,值为%d",p->coef,p->expn);
		p=p->next;
	}while(p!=NULL);
	
} 
// 输出一元多项式所有数据元素 

void Reverse(LinkedList L)
{
	LinkedList p,q;
	p=L->next;
	L->next=NULL;
	while(p)
	{
		q=p;
		p=p->next;
		q=L->next;
		L->next=q;	
	} 
	printf("原地逆置的结果：");
	ListOutput(L);
}
// 实现一元多项式的就地逆置

void calculate(LinkedList L,int x)
{
	float sum=0;
	float y;
	int i;
	while(L!=NULL)
	{
		for(i=1;i<=L->expn;i++)
		{
			y=1*x;
		}
		sum+=y*L->coef;
	}
	printf("结果为%f",sum);
} 
// 计算给定自变量多项式的值

 void add(LinkedList La,LinkedList Lb)
{
	LinkedList Lc,pc,pa,pb,ptr;
	float x;
	Creat(Lc);
	pc=Lc;
	pa=La->next;
	pb=Lb->next;
	while(pa!=NULL&&pb!=NULL)
	{
		if(pa->expn<pb->expn)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else if(pa->expn>pb->expn)
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
		else
		{
			x=pa->coef+pb->coef;
			if(x<=1e-6)
			{
				ptr=pa;
				pa=pa->next;
				free(ptr);
				ptr=pb;
				pb=pb->next;
				free(ptr);
			}
			else
			{
				pc=pa->next;
				pa->coef=x;
				pc=pa;
				pa=pa->next;
				ptr=pb;
				pb=pb->next;
				free(pb);
			}
		}
	} 
	if(pa==NULL)
	{
		pc->next=pb;
	}
	else
	{
		pc->next=pa;
	}
	ListOutput(Lc);
	
} 
//	将两个一元多项式合并成一个多项式 

void main()
{
	LinkedList L,L1;
	int n,number;
	float x;
	do
	{
		system("cls");
//		清除上一次内容 
		printf("------------------------------\n");
		printf("建立一元多项式单链表---------1\n");
		printf("显示一元多项式单链表---------2\n");
		printf("就地逆置---------------------3\n");
		printf("求值-------------------------4\n");
		printf("合并两个多项式---------------5\n");
		printf("退出-------------------------0\n");
		printf("请操作\n");
		scanf("%d",&number);
		switch (number)
		{
			case 1:
				ListInput(L) ;
				break;
			case 2:
				printf("请先创建一元多项式单链表");
				ListInput(L) ;
				ListOutput(L);
				break;
			case 3:
				printf("请先创建一元多项式单链表");
				ListInput(L) ;
				Reverse(L);
				break;
			case 4:
				printf("请先创建一元多项式单链表");
				ListInput(L) ;
				printf("请输入自变量的值：");
				scanf("%f",&x);
				calculate(L,x);
				break;
			case 5:
				printf("请先创建一元多项式单链表");
				ListInput(L) ;
				ListInput(L1);
				add(L,L1);
				break; 
		} 
	}while(number!=0);
	 
}

































