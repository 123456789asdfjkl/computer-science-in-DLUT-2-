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
void InsertSort(SqList &L)//直接插入排序 
{
	int i;
	int j;
	for(i=2;i<=L.length;i++)
	{
		if(L.r[i].key<L.r[i-1].key)
		{
			L.r[0].key=L.r[i].key;
			L.r[i].key=L.r[i-1].key;
			for(j=i-2;L.r[0].key<L.r[j].key;j--)
			{
				L.r[j+1].key=L.r[j].key;
			}
			L.r[j+1].key=L.r[0].key;
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
	printf("----------------------------\n");
	printf("排序后的结果为:\n"); 
	InsertSort(L);
	Print(L);
	return 0;	
} 
