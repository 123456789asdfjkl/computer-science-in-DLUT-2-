#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int LNode;

typedef struct Ploy
{
	float coef;
	int exp;
	struct Ploy *next;
}Polynode,*LinkList;
// 定义多项式线性链表

int LinkList_TailCreate(LinkList &L);				//尾插法建表
int LinkList_ExpInscending(LinkList &L, int len);		//指数升序排序函数
int LinkList_ExpInscendingElementPrint(LinkList &L, int len);	//指数升序输出所有元素
int LinkList_Reverse(LinkList &L);			//就地逆置函数
int LinkList_Cuculate(LinkList &L);				//计算输入的x的值
int LinkList_Add(LinkList &A, LinkList &B);		//两个一元多项式相加
int LinkList_Print(LinkList &L);				//输出函数
int LinkList_MergeSame(LinkList &L);				//合并同类项函数

int LinkList_TailCreate(LinkList &L)//输入每一项系数与指数
{
	LinkList p, s;
	int coef, exp, i, length, len;
	L = (LinkList)malloc(sizeof(int));
	L->next = NULL;
	p = L;
	printf("请输入该一元多项式的项数:");
	scanf("%d", &length);
	for (i = 0; i < length; i++)
	{
		printf("请输入第%d项系数:", i + 1);
		scanf("%d", &coef);
		printf("请输入第%d项指数:", i + 1);
		scanf("%d", &exp);
		while (coef == 0)
		{
			printf("无效项!请重新输入!\n");
			printf("请输入第%d项系数:", i + 1);
			scanf("%d", &coef);
			printf("请输入第%d项指数:", i + 1);
			scanf("%d", &exp);
		}
		s = (LinkList)malloc(sizeof(int));
		s->coef = coef;
		s->exp = exp;
		s->next = NULL;
		p->next = s;
		p = p->next;
	}
	len = LinkList_MergeSame(L);
	length -= len;
	printf("新建的一元多项式为:");
	LinkList_Print(L);
	system("pause");
	return length;
}
 
int LinkList_ExpInscending(LinkList &L, int len)//指数exp升序排列
{
	LinkList p, q, r;
	int i, j, done=1;
	p = L->next;
	if (p == NULL || p->next == NULL)
	{
		printf("无需排列!\n");
		return 0;
	}
	for (i = 1; i <= len - 1 && done; i++)//冒泡排序
	{
		done = 0;
		r = L;
		p = r->next;
		q = p->next;
		for (j = 0; j < len - i; j++)
		{
			if (p->exp > q->exp)
			{
				p->next = q->next;
				q->next = p;
				r->next = q;
				q = p->next;
				r = r->next;
				done = 1;
			}
			else
			{
				r = p; 
				p = q;
				q = q->next;
			}
		}
	}
	printf("指数升序排列后为:");
	LinkList_Print(L);
	system("pause");
	return 1;
}
 
int LinkList_ExpInscendingElementPrint(LinkList &L, int len)//指数升序输出系数与指数
{
	LinkList p,q,r;
	int k = 1, i, j, done = 1;
	p = L->next;
	if (p == NULL)
	{
		printf("Empty List!");
		return 0;
	}
	for (i = 1; i <= len - 1 && done; i++)//冒泡排序
	{
		done = 0;
		r = L;
		p = r->next;
		q = p->next;
		for (j = 0; j < len - i; j++)
		{
			if (p->exp > q->exp)
			{
				p->next = q->next;
				q->next = p;
				r->next = q;
				q = p->next;
				r = r->next;
				done = 1;
			}
			else
			{
				r = p;
				p = q;
				q = q->next;
			}
		}
	}
	printf("指数升序输出所有元素为:\n");
	p = L->next;
	while (p)
	{
		printf("第%d项系数为%d,第%d项指数为%d\n", k, p->coef, k, p->exp);
		p = p->next;
		k++;
	}
	system("pause");
	return 1;
}
 
int LinkList_Reverse(LinkList &L)//就地逆置变为指数降序（利用的头插法） 
{
	LinkList p, q;
	p = L->next;
	L->next = NULL;
	if (p == NULL)
	{
		printf("Empty List!");
		return 0;
	}
	while (p)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
	printf("逆置后为:");
	LinkList_Print(L);
	system("pause");
	return 1;
}
 
int LinkList_Cuculate(LinkList &L)//高效算法：输入自变量x求一元多项式的值
{
	LinkList p, q;
	int sum = 0, result = 0, q_expresult = 1, x;
	printf("请输入自变量x:");
	scanf("%d", &x);
	p = L->next;
	q = L;
	q->exp = 0;
	if (p == NULL)
	{
		printf("Epmty List!");
		return 0;
	}
	while (p)
	{
		result = pow(x, p->exp - q->exp)*q_expresult;//利用前一项已算出的x次幂
		q_expresult = result;
		sum = sum + p->coef*result;
		q = p;
		p = p->next;
	}
	printf("x=%d时,多项式值y=%d\n", x, sum);
	system("pause");
	return sum;
}
 
int LinkList_Add(LinkList &A, LinkList &B)//求两个一元多项式的和多项式
{
	LinkList pa, pb, r, s;
	int len = 0;
	pa = A->next;
	pb = B->next;
	s = A;
	free(B);
	while (pa != NULL && pb != NULL)
	{
		if (pa->exp < pb->exp)
		{
			r = pa;
			pa = pa->next;
			s->next = r;
			s = r;
		}
		else if (pa->exp > pb->exp)
		{
			r = pb;
			pb = pb->next;
			s->next = r;
			s = r;
		}
		else if (pa->exp == pb->exp)
		{
			pa->coef = pa->coef + pb->coef;
			r = pb->next;
			free(pb);
			pb = r;
			if (pa->coef == 0)
			{
				r = pa->next;
				free(pa);
				pa = r;
			}
			else
			{
				r = pa;
				pa = pa->next;
				s->next = r;
				s = r;
			}
		}
	}
	if (pa == NULL)
		s->next = pb;
	if (pb == NULL)
		s->next = pa;
	printf("相加后当前新的一元多项式为:");
	LinkList_Print(A);
	r = A->next;
	while (r)
	{
		len++;
		r = r->next;
	}
	system("pause");
	return len;
}
 
int LinkList_Print(LinkList &L)
{
	LinkList p;
	p = L->next;
	if (p == NULL)
	{
		printf("Epmty List!");
		return 0;
	}
	printf("y = ");
	while (p != NULL)
	{
		if (p->exp == 0)
			printf("%.2f", p->coef);
		else
			printf("%.2fx^%d", p->coef, p->exp);
		p = p->next;
		if (p != NULL)
			printf(" + ");
	}
	printf("\n");
	return 1;
}
 
int LinkList_MergeSame(LinkList &L)
{
	LinkList p, q;
	int len = 0;
	p = L->next;
	if (p == NULL || p->next == NULL)
		return 0;
	while (p->next)
	{
		if (p->exp == p->next->exp)
		{
			q = p->next;
			p->coef += q->coef;
			p->next = q->next;
			free(q);
			len++;
		}
		else
			p = p->next;
	}
	return len;
}

int main()
{
	LinkList A,B;
	int n,number;
	int len[20], i=0;
	int j;
	float x;
	for(j=0;j<20;j++)
	{
		len[j]=0; 
	}
	while(1)
	{
		system("cls");
//		清除上一次内容 
		printf("------------------------------\n");
		printf("\t 1.建立一元多项式\n");
		printf("\t 2.对一元多项式进行指数升序排列\n");
		printf("\t 3.按指数升序输出一元多项式系数与指数\n");
		printf("\t 4.逆置一元多项式\n");
		printf("\t 5.输入x,计算一元多项式的值\n");
		printf("\t 6.求两个一元多项式的和多项式\n");
		printf("\t 7.退出\n");
		printf("请操作\n");
		scanf("%d",&number);
		switch (number)
		{
			case 1: 
			{ 
				system("cls");
				if (len[i] != 0)
				{
					printf("已存在以下一元多项式，请选择需要的操作!\n");
					LinkList_Print(A);
					system("pause");
					break;
				}
				printf("现在建立第1个一元多项式\n");
				len[++i]=LinkList_TailCreate(A); 
				break; 
			}
			case 2: 
			{ 
				if (len[i] == 0)
				{
					printf("没有可操作的表!请先建表!\n");
					system("pause");
					break;
				}
				system("cls");
				LinkList_ExpInscending(A,len[i]); 
				break; 
			}
			case 3: 
			{ 
				if (len[i] == 0)
				{
					printf("没有可操作的表!请先建表!\n");
					system("pause");
					break;
				}
				system("cls");
				LinkList_ExpInscendingElementPrint(A,len[i]); 
				break; 
			}
			case 4: 
			{ 
				if (len[i] == 0)
				{
					printf("没有可操作的表!请先建表!\n");
					system("pause");
					break;
				}
				system("cls");
				LinkList_Reverse(A); 
				break; 
			}
			case 5: 
			{ 
				if (len[i] == 0)
				{
					printf("没有可操作的表!请先建表!\n");
					system("pause");
					break;
				}
				system("cls");
				LinkList_Cuculate(A); 
				break;
			}
			case 6: 
			{ 
				system("cls");
				if (len[i] == 0)
				{
					printf("现在建立第%d个一元多项式\n",i+1);
					len[++i] = LinkList_TailCreate(A);
				}
				printf("第%d个一元多项式",i);
				LinkList_ExpInscending(A, len[i]);
				printf("现在建立第%d个一元多项式\n",i+1);
				len[++i] = LinkList_TailCreate(B);
				printf("第%d个一元多项式",i);
				LinkList_ExpInscending(B, len[i]); 
				len[++i] = LinkList_Add(A, B);
				break; 
			}
			case 7: { exit(0); break; }
		}
		
	}
	 
}
