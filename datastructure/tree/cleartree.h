#include<D:\vscode_c\datastructure\tree\def.h>
status ClearTree(BiTree &T)
{
    if(T!=NULL)
    {
        ClearTree(T->lchild);
        ClearTree(T->rchild);
        free(T);
        return OK;
    }
    return OK;
}