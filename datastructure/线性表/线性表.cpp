#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node,*Linklist;
Linklist createxianjinxianchu()//该函数创建先进先出单链表
{
    Linklist head, tail;
    head = (Linklist)malloc(sizeof(node));
    tail = head;
    tail->next = NULL;
    int n;
    scanf("%d", &n);
    while(n!=0)
    {
        Linklist p;
        p = (Linklist)malloc(sizeof(node));
        p->data = n;
        p->next = tail->next;
        tail->next = p;
        tail = p;
        scanf("%d", &n);
    }
    tail->next = NULL;
    return head;
}
Linklist creatxianjinhouchu()//该函数创建先进后出单链表
{
    Linklist head;
    head = (Linklist)malloc(sizeof(node));
    int n;
    scanf("%d", &n);
    head->next = NULL;
    while(n!=0)
    {
        Linklist p;
        p = (Linklist)malloc(sizeof(node));
        p->data = n;
        p->next = head->next;
        head->next = p;
        scanf("%d", &n);
    }
    return head;
}
/*insert函数是在递增有序链表中插入x，这里创建了一个带头结点的链表，所以代码就显得更加
简洁*/
Linklist insert(Linklist head,int x)
{
    Linklist p, q;
    q = head;
    p = head->next;
    while(p&&p->data<x)
    {
        p = p->next;
        q = q->next;
    }
    Linklist r;
    r = (Linklist)malloc(sizeof(node));
    r->data = x;
    r->next = p;
    q->next = r;
    return head;
}
/*这里设计了第三种创建链表的方法，由于insert函数中包含了空表的情况，所以可以通过调用
insert函数不断进行插入*/
Linklist creat3()
{
    Linklist head;
    head = (Linklist)malloc(sizeof(node));
    head->next = NULL;
    int n;
    scanf("%d", &n);
    while(n!=0)
    {
        head = insert(head, n);
        scanf("%d", &n);
    }
    return head;
}
/*该函数用于在指定位置前插入元素x*/
void insert2(Linklist head,int i,int x)
{
    int j=1;
    Linklist p;
    p = head->next;
    while(p&&j<i-1)
    {
        j++;
        p = p->next;
    }
    if(p==NULL)
    {
        printf("error!");
        return;
    }
    Linklist q;
    q = (Linklist)malloc(sizeof(node));
    q->data = x;
    q->next = p->next;
    p->next = q;
}
/*delet函数删除链表中所有值为x的元素*/
void delet(Linklist head,int x)
{
    Linklist p;
    p = head;
    int flag = 0;
    while(p)
    {
        if(p->next->data==x)
        {
            Linklist q;
            q = p->next;
            p->next = p->next->next;
            free(q);
            flag++;
        }
        p = p->next;
    }
    if(!flag)
    {
        printf("no found!");
    }
}
Linklist merge(Linklist la,Linklist lb)
{
    Linklist pa, pb, pc;
    pa = la->next;
    pb = lb->next;
    pc = la;
    free(lb);
    while(pa&&pb)
    {
        if(pa->data<=pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else if(pa->data>pb->data)
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    if(pa)
        pc->next = pa;
    else
        pc->next = pb;
    return la;
}
int main()
{
    Linklist La,p,Lb,lc;
    La = createxianjinxianchu();
    Lb = createxianjinxianchu();
    //pa = La, pb = Lb;
    lc = merge(La, Lb);
    p = lc->next;
    //int x;
    //scanf("%d", &x);
    //delet(L,x);
    //p = L->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}