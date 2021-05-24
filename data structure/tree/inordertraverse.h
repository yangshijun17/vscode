#include<D:\vscode_c\data structure\tree\def.h>
status InoderTraverse(BiTree T)
{
    BiTree s[100],q=T;
    int top = 0;
    while(q||top)
    {
        while(q)
        {
            s[top++] = q;
            q = q->lchild;
        }
        printf("%d,%s ", s[top-1]->data.key,s[top-1]->data.others);
        if(top)
        {
            top--;
            q = s[top];
            q = q->rchild;
        }
    }
}