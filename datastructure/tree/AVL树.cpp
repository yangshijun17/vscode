#include <stdio.h>
#include<stdlib.h>
#define max(a,b) (a)>(b)?(a):(b)
typedef struct AvlNode
{
    int data;
    int height;
    AvlNode *left;
    AvlNode *right;
} AvlNode,*AvlTree;
AvlTree FindMax(AvlTree &T)
{
    AvlNode *q=T;
    if(T==NULL)
        return NULL;
    while(q->right)
    {
        q = q->right;
    }
    return q;
}
AvlNode* FindMin(AvlNode* T)
{
    AvlNode *q = T;
    if (T == NULL)
        return NULL;
    while(q->left)
        q = q->left;
    return q;
}
int GetHeight(AvlNode *T)
{
    if (T == NULL)
        return -1;
    else
        return T->height;
}
AvlNode* LL(AvlNode *T)
{
    AvlNode *q = T->left;
    T->left = q->right;
    q->right = T;
    T = q;
    T->height = max(GetHeight(T->left), GetHeight(T->right)) + 1;
    q->height = max(GetHeight(q->left), GetHeight(q->right)) + 1;
    return q;
}
AvlNode* RR(AvlNode *T)
{
    AvlNode *q = T->right;
    T->right = q->left;
    q->left = T;
    T = q;
    T->height = max(GetHeight(T->left), GetHeight(T->right)) + 1;
    q->height = max(GetHeight(q->left), GetHeight(q->right)) + 1;
    return q;
}
AvlNode* LR(AvlNode* T)
{
    RR(T->left);
    return LL(T);
}
AvlNode* RL(AvlNode *T)
{
    LL(T->right);
    return RR(T);
}
void insert(AvlNode *&T,int x)
{
    if(T==NULL)
    {
        T = (AvlNode *)malloc(sizeof(AvlNode));
        T->left = NULL;
        T->right = NULL;
        T->height = 1;
        T->data = x;
        return;
    }
    else if(x<T->data)
    {
        insert(T->left,x);
        if(GetHeight(T->left)-GetHeight(T->right)>1)
        {
            if(x<T->left->data)
                LL(T);
            else
                LR(T);
        }

    }
    else if(x>T->data)
    {
        insert(T->right, x);
        if(GetHeight(T->right)-GetHeight(T->left)>1)
        {
            if(x>T->right->data)
                RR(T);
            else
                RL(T);
        }
    }
    T->height = max(GetHeight(T->left), GetHeight(T->right)) + 1;
    return;
}
void Delete(AvlNode* &T,int x)
{
    if(T==NULL)
        return;
    else if(T->data==x)
    {
        if(T->left&&T->right)
        {
            if(GetHeight(T->left)>GetHeight(T->right))
            {
                T->data = FindMax(T->left)->data;
                Delete(T->left, T->data);
            }
            else
            {
                T->data = FindMax(T->right)->data;
                Delete(T->right, T->data);
            }
        }
        else
        {
            T = T->left ? T->left : T->right;
        }
    }
    else if(x<T->data)
    {
        Delete(T->left, x);
        if(GetHeight(T->right)-GetHeight(T->left)>1)
        {
            if(GetHeight(T->right->left)>GetHeight(T->right->right))
                T=RL(T->right);
            else
                T=RR(T->right);
        }
        else
        {
            T->height = max(GetHeight(T->left), GetHeight(T->right)) + 1;
        }
    }
    else
    {
        Delete(T->right, x);
        if(GetHeight(T->left)-GetHeight(T->right)>1)
        {
            if(GetHeight(T->left->left)>GetHeight(T->left->right))
                T = LL(T->left);
            else
                T = LR(T->left);
        }
        else
            T->height = max(GetHeight(T->left), GetHeight(T->right)) + 1;
    }
    return;
}