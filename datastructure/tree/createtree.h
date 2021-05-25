#include<D:\vscode_c\datastructure\tree\def.h>
status createBitree(BiTree &T,TElemType definition[])
{
    static int i = 0;
    for (int j = 0; definition[j].key != -1;j++)
    {
        for (int t = j + 1; definition[t].key != -1;t++)
        {
            if(definition[j].key==definition[t].key&&definition[j].key!=0)
            {
                return ERROR;
            }
        }
    }
    //以上为查重的代码
    if(definition[i].key==-1)
        return OK;//读到最后，返回OK
    else if(definition[i].key==0)
    {
        T = NULL;
        i++;
        return OK;//如果为0的话，当前结点为空，i自增，不用继续递归调用
    }
    else if(definition[i].key!=-1)
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data = definition[i];//已经求了T的数据域
        i++;
        createBitree(T->lchild, definition);//根据前序遍历的特征，递归求T的左孩子
        createBitree(T->rchild, definition);//递归求T的右孩子
        return OK;
    }
}