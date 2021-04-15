#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *p;
};
int main()
{
  node* L,*r;
  L = (node*)malloc(sizeof(node));
  L->p = NULL;
  int n;
  scanf("%d", &n);
  while(n!=0)
  {
    r = (node *)malloc(sizeof(node));
    r->data = n;
    r->p = L->p;
    L->p = r->p;
    scanf("%d", &n);
  }

  node *q;
  q = L->p;
  while(q->p->p!=NULL)
  {
    q = q->p;
  }
  q->p = q->p->p;
  q = L->p;
  while(q->p!=NULL)
  {
    printf("%d ", q->data);
    q = q->p;
  }
}