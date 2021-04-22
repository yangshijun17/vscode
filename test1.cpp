#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int SElemType;
#define STACK_INIT_SIZE 100
typedef struct
{
    SElemType *base;
    SElemType *top;
    int size;
} SqStack;
int InitStack(SqStack A);
int Push(SqStack A, SElemType e);
int Pop(SqStack A, SElemType e);
SqStack S;
int main()
{
    char c;
    int i, e;
    scanf("%c", &c);
    InitStack(S);
    while (c != '\n')
    {
        if (c == 40)
            i = 1;
        else if (c == 41)
            i = 4;
        else if (c == 91)
            i = 2;
        else if (c == 93)
            i = 3;
        if (i == 1 || i == 2)
        {
            Push(S, i);
        }
        else if (i == 3 || i == 4)
        {
            if (i + *(S.top-1) == 5)
            {
                Pop(S, e);
            }
            else
            {
                printf("为不合格字符串");
                return 0;
            }
        }
        scanf("%c", &c);
    }
    if (S.top != S.base)
        printf("为不合格字符串");
    else
        printf("为合格字符串");
    return 0;
}
int InitStack(SqStack A)
{
    S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S.base)
        exit(-1);
    S.top = S.base;
    S.size = STACK_INIT_SIZE;
    return 1;
}
int Push(SqStack A, SElemType e)
{
    if (S.top - S.base >= S.size)
    {
        S.base = (SElemType *)realloc(S.base, (S.size + 10) * sizeof(SElemType));
        if (!S.base)
            exit(-1);
        S.top = S.base + S.size;
        S.size += 10;
    }
    S.top += 1;
    *(S.top) = e;
    return 1;
}
int Pop(SqStack A, SElemType e)
{
    if (S.top == S.base)
        return -1;
    e = *S.top;
    S.top -= 1;
    return 1;
}