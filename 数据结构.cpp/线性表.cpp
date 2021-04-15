#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node,*Linklist;
Linklist createxianjinxianchu()
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
Linklist creatxianjinhouchu()
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
int main()
{
    Linklist L,p;
    L = creatxianjinhouchu();
    p = L->next;
    while(p!=NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

