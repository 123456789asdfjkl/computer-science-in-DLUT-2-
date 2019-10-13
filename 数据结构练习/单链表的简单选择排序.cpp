#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkedList;
void CreateList(LinkedList &L,int n)//创建单链表 
{
	int i;
	LinkedList p;
	L=(LinkedList)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=0;i<n;i++)
	{
		printf("第%d个元素为:",i+1);
		p=(LinkedList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;	
	}	
}
void SortList(LinkedList &L)//单链表简单选择排序 
{
	LinkedList p,q,t;
	int a;
	for(p=L->next;p;p=p->next)
	{
		t=p;
		for(q=p->next;q;q=q->next)
		{	
			if(t->data>q->data)
			{
				t=q;	
			}	
		}
		if(p->data!=t->data)
		{
			a=t->data;
			t->data=p->data;
			p->data=a;	
		}	
	} 
}
void PrintList(LinkedList &L)//打印结果 
{
	LinkedList p;
	p=L->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;	
	} 
	printf("\n");
}
int main()
{
	int n;
	LinkedList L;
	printf("请输入单链表的长度：");
	scanf("%d",&n);
	CreateList(L,n);
	PrintList(L);
	SortList(L);
	printf("排序的结果为\n"); 
	PrintList(L);	
} 
