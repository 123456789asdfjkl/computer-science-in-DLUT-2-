#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#define Elemtype int
typedef struct SList
{
    Elemtype data;
    struct SList *next;
}Node;

void initial(Node **head);
void push_back(Node *head,Elemtype x);
void show(Node *head);
Node* _buynode(Elemtype x);
void function(Node *ha,Node *hb,Node *hc);

int main()
{
    Node *ha,*hb,*hc;
    initial(&ha);
    initial(&hb);
    initial(&hc);

    printf("创建单链表A（-1结束）\n");
    int x;
    while(1)
    {
        scanf("%d",&x);
        if(x==-1)
            break;
        push_back(ha,x);
    }
    printf("这是单链表a>>> \n");
    show(ha);

    printf("创建单链表B（-1结束）\n");
    while(1)
    {
        scanf("%d",&x);
        if(x==-1)
            break;
        push_back(hb,x);
    }
    printf("这是单链表b>>> \n");
    show(hb);

    printf("创建单链表C（-1结束）\n");
    while(1)
    {
        scanf("%d",&x);
        if(x==-1)
            break;
        push_back(hc,x);
    }
    printf("这是单链表c>>> \n");
    show(hc);

    printf("function过后的单链表a>>>");
    function(ha,hb,hc);
    show(ha);
    return(1);
}

Node* _buynode(Elemtype x)
{//本算法的功能是申请一个节点，数据域存放x，并且返回该节点的指针
    Node *s=(Node*)malloc(sizeof(Node));
    assert(s!=NULL);

    s->data=x;//数据域赋值x
    s->next=NULL;
    return(s);//返回该节点
}

void initial(Node **head)
{//本算法的功能是初始化一个头指针，使其指向一个头结点
    (*head)=(Node*)malloc(sizeof(Node));
    assert((*head)!=NULL);

    (*head)->data=0;//空表
    (*head)->next=NULL;
}

void push_back(Node *head,Elemtype x)
{//本算法的前提是单链表已经初始化
    //本算法的功能是在单链表的尾部插入一个新的节点，节点的数据域
    //赋值为x
    Node *s=_buynode(x);
    Node *p=head;

    while(p->next!=NULL)
        p=p->next;//p指向单链表的尾部节点

    s->next=p->next;
    p->next=s;
    head->data++;//表长加一
}

void show(Node *head)
{//本算法的前提是链表已经初始化并且不空
    //本算法的功能是依次显示单链表中的元素
    if(head->data==0)
        return;//表长合法性判断

    Node *p=head;

    while(p->next!=NULL)
    {
        printf("%d-->",p->next->data);
        p=p->next;
    }
    printf("Null.\n");
}

void function(Node *ha,Node *hb,Node *hc)
{//本算法的前提是三个表都不能为空
    //本算法的功能是除去表a中在表b和表c同时出现的元素
    if(ha->data==0 || hb->data==0 || hc->data==0)
        return;//表长合法性判断

    Node *pa,*pb,*pc;
    pa=ha;
    pb=hb->next;
    pc=hc->next;

    while(pa->next && pb && pc)//当pa节点下一个不空，pb,pc不空
    {
        while(pb!=NULL && pc!=NULL && pb->data!=pc->data)//移动pb,pc直到相同
        {
            if(pb->data<pc->data)//如果pb的小，则移动pb
                pb=pb->next;
            else
                pc=pc->next;
        }
        if(pb!=NULL && pc!=NULL)//b表和c表中有相同的元素
        {
            while(pb->next!=NULL&&pb->data==pb->next->data || pc->next!=NULL&&pc->data==pc->next->data)//使pa和pb移向重复元素中的最后一个元素
            {
                if(pb->next!=NULL && pb->data==pb->next->data)
                    pb=pb->next;
                if(pc->next!=NULL && pc->data==pc->next->data)
                    pc=pc->next;
            }
            while(pa->next!=NULL && pa->next->data<pb->data)
            {
                pa=pa->next;
            }
            if(pa->next!=NULL && pa->next->data==pb->data)
            {
                while(pa->next!=NULL && pa->next->data==pb->data)//删除重复的元素
                {
                    Node *q=pa->next;
                    pa->next=q->next;
                    free(q);
                    ha->data--;//表长减一
                }
                pb=pb->next;
                pc=pc->next;//pa pb同时移动到下一个节点
            }
        }
    }
}

