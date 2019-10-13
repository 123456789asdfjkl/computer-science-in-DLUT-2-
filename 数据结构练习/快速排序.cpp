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
int Partition(SqList &L,int low,int high)//一次快排 
{
	int pivotkey;
	L.r[0]=L.r[low];
	pivotkey=L.r[low].key;
	while(low<high)
	{
		while(low<high&&L.r[high].key>=pivotkey)
		{
			--high;			
		}
		L.r[low]=L.r[high];
		while(low<high&&L.r[low].key<=pivotkey)
		{
			++low;
		} 
		L.r[high]=L.r[low];
	}
	L.r[low]=L.r[0];
	return low;
	
}
void QSort(SqList &L,int low,int high)//比较函数 
{
	int pivotloc;
	if(low<high)
	{
		pivotloc=Partition(L,low,high);
		QSort(L,low,pivotloc-1);
		QSort(L,pivotloc+1,high); 
	}
}
void QuickSort(SqList &L)//快速排序 
{
	QSort(L,1,L.length);
}
int main()
{
	SqList L;
	Insert(L);
	Print(L);
	QuickSort(L);
	Print(L);
	return 0;	
} 
