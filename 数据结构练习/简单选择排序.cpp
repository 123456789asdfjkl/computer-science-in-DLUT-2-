#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct {
	int key;//记录数据信息 
}RedType;
typedef struct {
	RedType r[MAXSIZE+1];//存取顺序表元素 
	int length;//顺序表的长度 
}SqList;
void Insert(SqList &L)// 创建顺序表 
{
	int i;
	printf("请输入顺序表的长度：");
	scanf("%d",&L.length);
	for(i=1;i<=L.length;i++)
	{
		printf("请输入第%d个元素",i);
		scanf("%d",&L.r[i].key);	
	} 
}
void SelectSort(SqList &L)
{
	int i,j;
	int k;
	int a;
	for(i=1;i<=L.length;i++)
	{
		k=i;
		for(j=i;j<=L.length;j++)
		{
			if(L.r[k].key>L.r[j].key)
			{
				k=j;
			}
		}
		if(k!=i)
		{
			a=L.r[k].key;
			L.r[k].key=L.r[i].key;
			L.r[i].key=a;
		}
	}
} 
void Print(SqList &L)//打印顺序表 
{
	int i;
	printf("表中元素为：") ;
	for(i=1;i<=L.length;i++)
	{
		printf("%d ",L.r[i].key);	
	}
	printf("\n"); 
}
int main()
{
	SqList L;
	Insert(L);
	Print(L);
	SelectSort(L);
	Print(L);
	return 0;
 } 
