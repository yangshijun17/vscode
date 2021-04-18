#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int a, x;
    struct node *next;
} node, *Linklist;
Linklist create();
Linklist add();
int main()
{
    Linklist head,p;
    head = add();
    p = head->next;
    while(p)
    {
        printf("%dx^%d", p->a, p->x);
        p = p->next;
    }
}
Linklist add()
{
    Linklist la, lb, lc, pa, pb;
    la = create();
    lb = create();
    lc = la;
    pa = la->next;
    pb = lb->next;
    free(lb);
    while(pa&&pb)
    {
        if(pa->x==pb->x)
        {
            if(pa->a+pb->a==0)
            {
                pa = pa->next;
                pb = pb->next;
            }
            else
            {
                Linklist p;
                p = (Linklist)malloc(sizeof(node));
                p->a = pa->a + pb->a;
                p->x = pa->x;
                p->next = lc->next;
                lc->next = p;
                lc = p;
                pa = pa->next;
                pb = pb->next;
            }
        }
        else if(pa->x<pb->x)
        {
            //lc->next = pa->next;
            lc->next = pa;
            lc = pa;
            pa = pa->next;
        }
        else
        {
            //lc->next = pb->next;
            lc->next = pb;
            lc = pb;
            pb = pb->next;
        }
    }
    if(pa)
    {
        lc->next = pa;
    }
    else
    {
        lc->next = pb;
    }
    return la;
}
Linklist create()
{
    Linklist head, tail;
    head = (Linklist)malloc(sizeof(node));
    tail = head;
    tail->next = NULL;
    int aa, xx;
    scanf("%d %d", &aa, &xx);
    while(aa!=0)
    {
        Linklist p;
        p = (Linklist)malloc(sizeof(node));
        p->a = aa;
        p->x = xx;
        p->next = tail->next;
        tail->next = p;
        tail = p;
        scanf("%d %d", &aa, &xx);
    }
    return head;
}
