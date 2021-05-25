#include<D:\vscode_c\data structure\tree\def.h>
status PreOrderTraverse(BiTree T)
{
    if(T==NULL)
        return 1;
    else
    {
        printf("%d,%s ", T->data.key, T->data.others);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
