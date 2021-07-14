#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct BiNode
{
    char data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;
BiTree creatFBItree(char a[],int n)
{
    if(n>-1)
    {
        int length = pow(2, n),flag=0;
        if(a[0]=='0')
        {
            flag = 0;
            for (int i = 1; i < length;i++)
            if(a[i]=='1')
            {
                flag = 2;
            }
        }
        else
        {
            flag = 1;
            for (int i = 1; i < length;i++)
            if(a[i]=='0')
                flag = 2;
        }
        BiTree T;
        T=(BiTree)malloc(sizeof(BiNode));
        if(flag==0)
            T->data = 'B';
        else if(flag==1)
            T->data = 'I';
        else
            T->data = 'F';
        T->lchild = creatFBItree(a, n - 1);
        T->rchild = creatFBItree(a+(int)pow(2,n-1), n - 1);
        return T;
    }
    if(n==-1)
    {
        return NULL;
    }
}
void posttraverse(BiTree T);
int main()
{
    int n;
    scanf("%d", &n);
    char a[1200];
    scanf("%s", a);
    BiTree T;
    T = creatFBItree(a, n);
    posttraverse(T);
}
void posttraverse(BiTree T)
{
    if(T==NULL)
    {
        return;
    }
    posttraverse(T->lchild);
    posttraverse(T->rchild);
    printf("%c", T->data);
}
