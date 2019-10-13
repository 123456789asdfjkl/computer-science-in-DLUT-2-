#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define OVERFLOW -2
#define ERROR 0
typedef struct{
	int *base;
	int f;
	int r;
}SqQueue;
int InitQueue(SqQueue &Q,int k)
{
	Q.base=(int*)malloc(k*sizeof(int));
	if(!Q.base)
	{
		exit(OVERFLOW);
	}
	Q.f=Q.r=0;
	return OK;
}
int QueueLength(SqQueue Q,int k)
{
	return (Q.r-Q.f+k)%k;
}
int EnQueue (SqQueue &Q,int e,int k)
{
	Q.base[Q.r]=e;
	Q.r=(Q.r+1)%k;
	return OK;
}
int main()
{
	SqQueue Q;
	int k;
	int max;
	int i;
	int sum=1;
	int count=0;
	int j;
	printf("请输入阶数:");
	scanf("%d",&k);
	printf("请输入MAX值:");
	scanf("%d",&max);
	InitQueue(Q,k);
	for(i=0;i<k-1;i++)
	{
		EnQueue (Q,0,k);
	}
	while(sum<max)
	{
		EnQueue (Q,sum,k);
		Q.f=(Q.f+1)%k;
		sum=0;
		j=Q.f;
		for(i=0;i<k;i++)
			sum+=Q.base[(j+i)%k];
	}
	while(count<k-1)
	{
		printf("%d  ",Q.base[(Q.r+count)%k]);
		count++;
	}
	printf("%d\n",Q.base[(Q.r+count)%k]);
	return 0;
}


