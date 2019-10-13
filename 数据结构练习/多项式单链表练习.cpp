#include<stdio.h>
#include<stdlib.h>
typedef struct Poly{
	int coef;
	int exep;
	struct Poly *next;
}Polynode,*LinkedList;
int LinkedList_creat(LinkedList &L)//创建多项式单链表 
{
	LinkedList p;
	int n;
	int i;
	L=(LinkedList)malloc(sizeof(Polynode));
	L->next=NULL;
	printf("请输入要创建的单链表长度：");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		p=(LinkedList)malloc(sizeof(Polynode));
		printf("请输入第%d个元素的系数和指数：",i);
		scanf("%d %d",&p->coef,&p->exep);
		p->next=L->next;
		L->next=p;
	}
	return n;
	
}
void LinkedList_print(LinkedList &L,int n)//打印多项式单链表 
{
	LinkedList p;
	p=L->next;
	int i;
	for(i=1;i<n;i++)
	{
		if(p->exep!=0)
		{
			printf("%dx^%d+",p->coef,p->exep);
		}
		else
		{
			printf("%d+",p->coef);
		}
		p=p->next;
	}
	printf("%dx^%d\n",p->coef,p->exep);
}
void LinkedList_sort(LinkedList &L,int n)//多项式单链表按指数升序做冒泡排序 
{
	LinkedList p,p1,p2;
	int i;
	int j;
	int done=1;
	p=L;
	p1=L->next;
	p2=p1->next;
	for(i=1;i<=n&&done;i++)
	{
		p=L;
		p1=L->next;
		p2=p1->next;
		done=0;
		for(j=1;j<n-i+1;j++)
		{
			if(p1->exep>p2->exep)
			{
				p1->next=p2->next;
				p->next=p2;
				p2->next=p1;
				done=1;
				p=p2;
				p2=p1->next;
			}
			else
			{
				p=p->next;
				p1=p->next;
				p2=p1->next;
			}
			
		}
	}
	printf("排完序的结果为:\n");
	LinkedList_print(L,n);
		
} 
void LinkedList_derivation(LinkedList &L,int n)//多项式求导 
{
	LinkedList p;
	LinkedList p1;
	LinkedList p2;
	LinkedList p3;
	int i;
	p=L->next;
	p1=(LinkedList)malloc(sizeof(Polynode));
	p1->next=NULL;
	p2=p1;
	for(i=1;i<=n;i++)
	{
		p3=(LinkedList)malloc(sizeof(Polynode));
		p3->coef=p->coef*p->exep;
		p3->exep=p->exep-1;
		p3->next=NULL;
		p2->next=p3;
		p2=p3;
		p=p->next;
	}
	printf("求导后的结果为:\n");
	LinkedList_print(p1,n);
}
int main()
{
	LinkedList L;
	int k;
	k=LinkedList_creat(L);
	LinkedList_print(L,k);
	LinkedList_sort(L,k);
	LinkedList_derivation(L,k);
	return 0;
}
