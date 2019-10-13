#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define maxsize 50
typedef struct BiTNode {                     //树的结构体
	char data; 
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
BiTree T;
typedef struct stack{                        //中序遍历所用的栈
	BiTree data[maxsize];
	int top;
}Seqstack;
Seqstack s;
BiTree createBiTree(BiTree &T);       
void zhongxu(BiTree T);
int deep(BiTree T);
int ss(BiTree T);
void judge(BiTree T);
int main(){
	int h,d;
	T=(BiTNode*)malloc(sizeof(BiTNode));
	printf("请以先序输入一个树\n");
	createBiTree(T);
	printf("\n");
	printf("中序输出为：\n");
	zhongxu(T);
	printf("\n");
	h=deep(T);
	d=ss(T);
	printf("\n");
	printf("树的繁茂度为：%d\n",h*d);
	printf("\n");
	judge(T);
	return 0; 
}
BiTree createBiTree(BiTree &T){                     //创建一棵树，以先序输入
	char ch;
	scanf("%c",&ch);
	if(ch=='#')T=NULL;
	else{
		T=(BiTNode*)malloc(sizeof(BiTNode));
		T->data=ch;
		createBiTree(T->lchild);                    //递归算法
		createBiTree(T->rchild);
	}
	return T;
}
void zhongxu(BiTree T){                             //中序遍历，用栈来实现非递归
	BiTree h;
	s.top=-1;
	h=(BiTNode*)malloc(sizeof(BiTNode));
	h=T;
	while(h||(s.top!=-1)){
		while(h){
			s.data[++s.top]=h;
			h=h->lchild;
		}
		if(s.top!=-1){
			h=s.data[s.top--];
			printf("%c",h->data);
			h=h->rchild;
		}
	}
}
int deep(BiTree T){                             //求二叉树高度，递归算法
	int d1,d2,d;
	if(T==NULL)return 0;
	else{
		d1=deep(T->lchild);
		d2=deep(T->rchild);
		if(d1>=d2)d=d1+1;
		else d=d2+1;
	}
	return d;
}
int ss(BiTree T){                                //求二叉树宽度
	BiTree Q[maxsize],p;
	int f=0,r=0,count=0,m=0,width=0;
	if(T==NULL)return 0;
	Q[r]=T;
	while(f<=m){
		p=Q[f++];
		count++;
		if(p->lchild){
			if(r>=maxsize){printf("overflow");exit(0);}
			Q[++r]=p->lchild;
		}
		if(p->rchild){
			if(r>=maxsize){printf("overflow");exit(0);}
			Q[++r]=p->rchild;
		}
		if(f>m){
			m=r;
			if(count>width)width=count;
			count=0;
		}
	}
	return width;
}
void judge(BiTree T){                              //判断是否为完全二叉树
	BiTree q[maxsize],p;
	int f=0,r=0,i=-1;
	if(T==NULL){
		printf("二叉树为完全二叉树\n");
		return;
	}
	q[r++]=T; 
	while(f!=r){
		p=q[f++];
		if(p->lchild==NULL&&p->rchild!=NULL){printf("二叉树不是完全二叉树\n");return;}
		if(p->lchild!=NULL){
			q[r++]=p->lchild;
			if(p->rchild!=NULL)q[r++]=p->rchild;
			else
				i=f;
		}	
		while(i>-1&&i<=r-1){
			if(q[i]->lchild!=NULL||q[i]->rchild!=NULL){
				printf("二叉树不是完全二叉树\n");
				return;
			}
			i++;
		}
	}
	printf("二叉树为完全二叉树\n");
}

