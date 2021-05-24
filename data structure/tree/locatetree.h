#include<D:\vscode_c\data structure\tree\def.h>
BiTree LocateNode(BiTree T, KeyType e)
{
    if(T==NULL)
    {
        return NULL;
    }
    if(T->data.key==e)
    {
        return T;
    }
    BiTree left = LocateNode(T->lchild, e);//µİ¹é²éÕÒ×ó×ÓÊ÷
    BiTree right = LocateNode(T->rchild, e);//µİ¹é²éÕÒÓÒ×ÓÊ÷
    if(left==NULL&&right==NULL)
        return NULL;
    else if(left==NULL)
        return right;
    else
        return left;
}
