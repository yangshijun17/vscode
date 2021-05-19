#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}node,*Linklist;
Linklist create();
void sort(Linklist l);
int main()
{
    Linklist head,p;
    head = create();
    p = head;
    sort(p);
    p = head->next;
    while(p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void sort(Linklist l)
{
    Linklist p = l->next,q=l;
    Linklist r = p->next;
    while(p)
    {
        q = l;
        while(q->next&&q->next->data>p->data)
        {
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
        p = r;
    }
}
Linklist create()
{
    Linklist head, tail;
    head = (Linklist)malloc(sizeof(node));
    tail = head;
    tail->next = NULL;
    int aa;
    scanf("%d", &aa);
    while(aa!=0)
    {
        Linklist p;
        p = (Linklist)malloc(sizeof(node));
        p->data = aa;
        //p->x = xx;
        p->next = tail->next;
        tail->next = p;
        tail = p;
        scanf("%d", &aa);
    }
    return head;
}
