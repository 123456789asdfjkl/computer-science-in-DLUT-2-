#include<stdio.h>
#include<stdlib.h>
typedef struct data{
	int num;
	struct data *next;
}data;

typedef struct queue{
	data *head;
	data *rear;
	data *k_before;
}queue;

void init(queue *list,int k){
	int i;
	data *p = (data*) malloc (sizeof(data));
	p->num = 0;
	p->next = NULL;
	list->head = p;
	list->rear = p;
	list->k_before = p;
	for(i = 0; i < k-2; i++){
	    data *p = (data*) malloc (sizeof(data));
		p->num = 0;
		p->next = NULL;
		list->rear->next = p;
		list->rear = p;
	}
	for(i = 0; i < 2; i++){
	    data *p = (data*) malloc (sizeof(data));
		p->num = 1;
		p->next = NULL;
		list->rear->next = p;
		list->rear = p;
	}
}

void pop(queue *list){
	data *p;
	p = list->k_before;
	while(p->next != list->rear){
		printf("%d ", p->num);
		p = p->next;
	}
	printf("%d\n", p->num);
}

void push(queue *list, int z){
    data *q;
    q = (data*) malloc (sizeof(data));
	q->num = z;
	q->next = NULL;
	list->rear->next = q;
	list->rear = q;
	list->k_before = list->k_before->next;
} 
int main(){
     int max,k,x,y,z;
     printf("ÇëÊäÈëMAX£º\n"); 
	 scanf("%d", &max);
	 printf("ÇëÊäÈë½×Êý:");
	 scanf("%d",&k); 
	 queue *list = (queue*) malloc (sizeof(queue));
	 init(list, k);
	 while(1){
		 x = list->rear->num;
		 y = list->k_before->num;
		 z = 2*x - y;
		 if(x > max){
		     pop(list);
			 break;
		 }
		 else{
		     push(list, z);
		 }
	 }
	 return 0;
}
