#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef  struct  Dnode
    {
        ElemType     data;
        struct  Dnode *prior,*next;
    } *DuLinkList;

    void adjust(DuLinkList L);
    int main()
    {
        DuLinkList L, p, tail;
        int n, i;
        L = tail = (DuLinkList)malloc(sizeof(struct Dnode));
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
            p = (DuLinkList)malloc(sizeof(struct Dnode));
            scanf("%d", &p->data);
            tail->next = p;
            p->prior = tail;
            tail = p;
        }
        L->prior = tail;
        tail->next = L;
        adjust(L);
        p = L->next;
        while (p != L)
        {
            printf(" %d", p->data);
            p = p->next;
        }
}
void adjust(DuLinkList L)
{
	DuLinkList now,q,tail;
	int count=0;          //count记录数组下标；当数组下标为偶数时，当前结点移动到an后 
	now=L->next;     
	tail=L->prior;     //tail指向表尾结点an
	while(now!=tail){
		count++;
		if(count%2==0){         //count是偶数  
			q=now;                //q指向p所指结点 
			now=now->next;         //p后移 
			q->prior->next=q->next;         //q的前驱结点的next指针指向q的后继 
			q->next->prior=q->prior;        //q的后继结点的prior指针指向q的前驱 （也就是将ai删除） 
			
			q->next=tail->next;
			tail->next->prior=q;
			q->prior=tail;
			tail->next=q; 
		}
		else      
			now=now->next;
	}
}