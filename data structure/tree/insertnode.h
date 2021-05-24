#include<D:\vscode_c\data structure\tree\def.h>
BiTNode *LocateTree(BiTree T, KeyType e, TElemType c);
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
{
    BiTree p=NULL,q=NULL;
    if(LR==-1)
    {
        p = (BiTree)malloc(sizeof(BiTNode));
        p->data = c;
        p->lchild = NULL;
        p->rchild = T;
        T = p;
        return OK;
    }
    p = LocateTree(T, e,c);
    if(p==NULL)
        return ERROR;
    q = (BiTNode *)malloc(sizeof(BiTNode));
    q->data = c;
    if(LR==0)
    {
        q->rchild = p->lchild;
        p->lchild = q;
        q->lchild = NULL;
        return OK;
    }
    else if(LR==1)
    {
        q->rchild = p->rchild;
        p->rchild = q;
        q->lchild = NULL;
        return OK;
    }
}
BiTNode* LocateTree(BiTree T,KeyType e,TElemType c)
//查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
if(T==NULL)
{
    return NULL;
}
if(T->data.key==c.key)
{
    return NULL;
}
if(T->data.key==e)
{
    return T;
}
BiTree lt,rt;
lt=LocateTree(T->lchild,e,c);
rt=LocateTree(T->rchild,e,c);
if(lt==NULL&&rt==NULL) return NULL;
else if(lt!=NULL) return lt;
else return rt;

    /********** End **********/
}