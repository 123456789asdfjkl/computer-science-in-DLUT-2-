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
void qppx(SqList &L)
{
	int i; 
	int j;
	int t;
	int count=1;
	for(i=1;(i<=L.length)&&(count>0);i++)
	{
		count=0;
		for(j=1;j<=L.length-i;j++)
		{
			if(L.r[j].key>L.r[j+1].key)
			{
				t=L.r[j].key;
				L.r[j].key=L.r[j+1].key;
				L.r[j+1].key=t;
				count++;
			}
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
	qppx(L);
	Print(L);
	return 0;
}
