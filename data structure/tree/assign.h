#include<D:\vscode_c\data structure\tree\def.h>
status Assign(BiTree &T,KeyType e,TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
if(T==NULL)
{
    return ERROR;
}
if(T->data.key==value.key&&value.key!=e)
{
    return 2;//如果关键字重复，那么返回2
}
if(T->data.key==e)
{
    T->data=value;
    return OK;
}
if((Assign(T->lchild,e,value)==1&&Assign(T->rchild,e,value)!=2)||(Assign(T->rchild,e,value)==1&&Assign(T->lchild,e,value)!=2))
{
    return OK;//最终返回OK的必要条件就是，左树找到并且右树无重复，或者相反的情况
}
else
    return ERROR;
    /********** End **********/
}