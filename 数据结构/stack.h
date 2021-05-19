#include<stdio.h>
#include<stdlib.h>
#include<D:\\vscode_c\\数据结构\\def.h>
typedef struct
{
    ElemType *elem;
    int top;
    int stacksize;
} Sqstack;
int initstack(Sqstack s)
{
    s.top = 0;
    s.stacksize = MAXLENG;
    s.elem = (ElemType *)malloc(s.stacksize*sizeof(Sqstack));
    return OK;
}
int push(Sqstack s,ElemType e)
{
    if(s.top>=s.stacksize)
    {
        s.elem = (ElemType *)realloc(s.elem,s.stacksize*(sizeof(Sqstack)+10));
        s.stacksize += 10;
    }
    s.elem[s.top] = e;
    s.top++;
    return OK;
}
int pop(Sqstack s,ElemType &e)
{
    if(s.top==0)
    {
        return ERROR;
    }
    s.top--;
    e = s.elem[s.top];
    return OK;
}
