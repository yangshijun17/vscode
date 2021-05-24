#include<D:\vscode_c\data structure\tree\def.h>
int BiTreeDepth(BiTree T)
{
    if(T==NULL)
    {
        return 0;//空树深度为0
    }
    //递归计算左子树和右子树的深度，哪个大就返回哪个加一
    return BiTreeDepth(T->lchild) > BiTreeDepth(T->rchild) ? BiTreeDepth(T->lchild) + 1 : BiTreeDepth(T->rchild) + 1;
}