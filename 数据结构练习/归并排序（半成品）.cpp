#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct RcdType{
	int key;//记录数据信息 
}RcdType;
typedef struct {
	RcdType r[MAXSIZE+1];//存取顺序表元素 
	int length;//顺序表的长度 
}SqList;
RcdType TR2[MAXSIZE+1];
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
void Merge(RcdType SR[],RcdType TR[],int s,int m,int t)
{
	int k;
	int j;
	int i;
	for(j=m+1,i=s,k=s;i<=m&&j<=t;++k)
	{
		if(SR[i].key<=SR[j].key)
		{
			TR[k]=SR[i];
			i++;
		}
		else
		{
			TR[k]=SR[j++];
		}
	}
	while(i<=m)
	{
		TR[k++]=SR[i++];
	}
	while(j<=t)
	{
		TR[k++]=SR[j++];
	}
}
void MSort(RcdType SR[],RcdType TR1[],int s,int t)
{
	int m;
	if(s==t)
	{
		TR1[s]=SR[s];
	}
	else
	{
		m=(s+t)/2;
		MSort(SR,TR2,s,m);
		MSort(SR,TR2,m+1,t);
		Merge(TR2,TR1,s,m,t);
	}
}
void MergeSort(SqList &L)
{
	MSort(L.r,L.r,1,L.length);
}
int main()
{
	SqList L;
	Insert(L);
	Print(L);
	MergeSort(L);
	Print(L);
}

