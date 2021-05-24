#include <D:\vscode_c\data structure\tree\def.h>
status PostOrderTraverse(BiTree T)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL)
    {
        return 1;
    }
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%d,%s ", T->data.key, T->data.others);

    /********** End **********/
}