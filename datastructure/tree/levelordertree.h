#include<D:\vscode_c\datastructure\tree\def.h>
int BiTreeDepth(BiTree T);
void LevelTree(BiTree T, int depth);
status LevelOrderTree(BiTree T)
{
    int depth = BiTreeDepth(T);
    for (int i = 1; i <= depth;i++)
    {
        LevelTree(T, i);
    }
}
int BiTreeDepth(BiTree T)
{
    if(T==NULL)
    {
        return 0;
    }
    return BiTreeDepth(T->lchild) > BiTreeDepth(T->rchild) ? BiTreeDepth(T->lchild) + 1 : BiTreeDepth(T->rchild) + 1;
}
void LevelTree(BiTree T,int depth)
{
    if(T==NULL||depth==0)
    {
        return;
    }
    if(depth==1)
    {
        printf("%d,%s ", T->data.key, T->data.others);
    }
    LevelTree(T->lchild, depth - 1);
    LevelTree(T->rchild, depth - 1);
}