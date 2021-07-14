#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct BiNode
{
    char data;
    struct BiNode *lchild;
    struct BiNode *rchild;
}BiNode,*BiTree;
int indexpos(char c, char in[], int length);
BiTree createtree(char pre[],char in[],int length)
{
    if(length==0)
        return NULL;
    BiTree T;
    T = (BiTree)malloc(sizeof(BiNode));
    T->data = pre[length-1];
    int t = indexpos(pre[length-1], in, length);
    T->lchild = createtree(pre,in,t);
    T->rchild = createtree(pre +t, in + 1 + t, length-1-t);
    return T;
}
int indexpos(char c,char in[],int length)
{
    for (int i = 0; i < length;i++)
    {
        if(in[i]==c)
        {
            return i;
        }
    }
    return 0;
}
void posttraverse(BiTree T)
{
    if(T==NULL)
    {
        return;
    }
    printf("%c", T->data);
    posttraverse(T->lchild);
    posttraverse(T->rchild);
}
int main()
{
    char pre[1000], in[1000];
    BiTree T;
    scanf("%s", in);
    scanf("%s", pre);
    T = createtree(pre, in, strlen(pre));
    posttraverse(T);
}