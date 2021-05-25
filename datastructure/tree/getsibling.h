#include<D:\vscode_c\data structure\tree\def.h>
BiTree GetSibling(BiTree T,KeyType e)
{
    if(T==NULL)
        return NULL;
    if(T->lchild)
    {
        if(T->lchild->data.key==e)
            return T->rchild;//左孩子符合条件就返回右孩子
    }
    else if(T->rchild)
    {
        if(T->rchild->data.key==e)
            return T->lchild;//右孩子符合条件就返回左孩子
    }
    //否则递归查找，如果左子树里有就返回左子树里的，否则返回右子树
    return GetSibling(T->lchild, e) != NULL ? GetSibling(T->lchild, e) : GetSibling(T->rchild, e);
}