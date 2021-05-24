#include<D:\vscode_c\data structure\tree\def.h>
status DeleteNode(BiTree &T,KeyType e)
{
    if(T==NULL)
        return ERROR;
    if(T->data.key==e)
    {
        if(T->lchild&&T->rchild)//度为2
        {
            BiTree p, q;
            p = T->lchild->rchild, q = T;
            T = T->lchild;
            while(p->rchild)
                p = p->rchild;
            p->rchild = q->rchild;
            free(q);
            return OK;
        }
        else if(T->lchild)//两种情况的度为1
        {
            BiTree p;
            p = T;
            T = T->lchild;
            free(p);
            return OK;
        }
        else if(T->rchild)
        {
            BiTree p;
            p = T;
            T = T->rchild;
            free(p);
            return OK;
        }
        else//度为0
        {
            free(T);
            T = NULL;
            return OK;
        }
    }
    else
        return DeleteNode(T->lchild, e) + DeleteNode(T->rchild, e);
}