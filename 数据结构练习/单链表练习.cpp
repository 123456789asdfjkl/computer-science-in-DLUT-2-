#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
int ListInsert(LinkList &L,int i,int e)//向单链表中指定位置插入元素 
{
	LinkList p,s;
	int j;
	p=L;
	j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(!p||j>i-1)
	{
		return -1;
	}
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 0;
}
void CreateList(LinkList &L,int n)//创建单链表 
{
	int i;
	LinkList p;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=0;i<n;i++)
	{
		printf("第%d个元素为:",i+1);
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
		p->next=L->next;
		L->next=p;	
	}	
}
void ListPrint(LinkList &L)//输出单链表中的元素 
{
	LinkList p;
	p=L->next;
	printf("单链表中的元素为：\n");
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void ListSort(LinkList &L,int n)//从大到小排序 
{
	LinkList p,q;
	p=L->next;
	q=p->next;
	int j;
	int i;
	for(i=1;i<=n;i++)
	{
		while(q&&p)
		{
			if(q->data>p->data)
			{
				j=q->data;
				q->data=p->data;
				p->data=j;
			}
			q=q->next;
			p=p->next;
		}
		p=L->next;
		q=p->next;
	}
}
void ListSort1(LinkList &L,int n)//从小到大排序 
{
	LinkList p,q;
	p=L->next;
	q=p->next;
	int j;
	int i;
	for(i=1;i<=n;i++)
	{
		while(q&&p)
		{
			if(q->data<p->data)
			{
				j=q->data;
				q->data=p->data;
				p->data=j;
			}
			q=q->next;
			p=p->next;
		}
		p=L->next;
		q=p->next;
	}
}
void DelectList(LinkList &L,int n)//删除指定位置元素的值 
{
	LinkList p,q;
	int i;
	p=L->next;
	q=L;
	for(i=0;i<n-1;i++) 
	{
		p=p->next;
		q=q->next;
	}
	q->next=p->next;
	free(p);
}
int DelectList1(LinkList &L,int e)
{
	LinkList p,q;
	p=L->next;
	q=L;
	while(p)
	{
		if(p->data==e)
		{
			q->next=p->next;
			free(p);
			return 1;
		}
		p=p->next;
		q=q->next;				
	}
	printf("不存在此元素，删除失败\n");
	return 0;	
} 
int main()
{
	LinkList L;
	int a;
	int n;
	int i;
	int e;
	int flag;
	while(true)
	{ 
		system("cls");
		printf("--------------------------------------\n");
		printf("0---------------------------------退出\n");
		printf("1---------------------------创建单链表\n");
		printf("2-----------------------------插入元素\n");
		printf("3-------------------------从大到小排序\n");
		printf("4-------------------------从小到大排序\n");
		printf("5-----------删除指定位置的元素(按位置)\n");
		printf("6-------------------------删除指定元素\n");
		printf("7---------------------显示单链表的元素\n");
		printf("请选择操作\n"); 
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("请输入单链表的长度：\n");
				scanf("%d",&n); 
				CreateList(L,n);
				ListPrint(L);
				break;
			case 2:
				printf("请输入要插入元素位置:\n");
				scanf("%d",&i);
				printf("请输入要插入元素值：\n");
				scanf("%d",&e);
				ListInsert(L,i,e);
				ListPrint(L);
				break;
			case 3:	
				ListSort(L,n);
				ListPrint(L);
				break;
			case 4:
				ListSort1(L,n);
				ListPrint(L);
				break;
			case 5:
				printf("请输入要删除元素的位置：\n");
				scanf("%d",&i);
				DelectList(L,i);
				ListPrint(L);
				break;
			case 6:
				printf("请输入要删除的元素值：\n");
				scanf("%d",&e);
				flag=DelectList1(L,e);
				if(flag)
				{
					ListPrint(L);
				}
				break;
			case 7:
				ListPrint(L);
				break;
		}
		if(!a)
		{
			break;
		}
		system("pause");
	}
	return 0;	
} 
