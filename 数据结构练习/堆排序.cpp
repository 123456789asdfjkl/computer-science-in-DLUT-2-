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
void HeepAdjust(SqList &L,int s,int m )//堆排序的调整 
{
	int rc;
	int j;
	rc=L.r[s].key;
	for(j=2*s;j<m;j*=2)
	{
		if(j<m&&L.r[j].key<L.r[j+1].key)
		{
			++j;
		}
		if(!(rc<L.r[j].key))
		{
			break;
		}
		L.r[s].key=L.r[j].key;
		s=j;
	}
	L.r[s].key=rc;
 } 
void HeepSort(SqList &L)
{
	int i;
	int k;
	for(i=L.length/2;i>0;--i)
	{
		HeepAdjust(L,i,L.length);	
	}
	for(i=L.length;i>1;--i)
	{
		k=L.r[i].key;
		L.r[i].key=L.r[1].key;
		L.r[1].key=k;
		HeepAdjust(L,1,i-1);	
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
	HeepSort(L);
	Print(L); 
	return 0;
	
}
