#include <bits/stdc++.h>
#include <limits.h>
#include <stdlib.h>
#define max(a, b) (a) > (b) ? (a) : (b)
typedef struct AvlNode
{
    int data;
    int height;
    int size, same;
    AvlNode *left;
    AvlNode *right;
} AvlNode, *AvlTree;
int GetSize(AvlTree T)
{
    if (T == NULL)
        return 0;
    else
        return T->size;
}
int GetHeight(AvlNode *T)
{
    if (T == NULL)
        return 0;
    else
        return T->height;
}
void update(AvlTree T)
{
    T->size = GetSize(T->left) + GetSize(T->right) + T->same;
    T->height = max(GetHeight(T->left), GetHeight(T->right)) + 1;
}
void LL(AvlTree &T)
{
    AvlNode *q = T->left;
    T->left = q->right;
    q->right = T;
    update(T);
    update(q);
    T = q;
}
void RR(AvlTree &T)
{
    AvlNode *q = T->right;
    T->right = q->left;
    q->left = T;
    update(T);
    update(q);
    T = q;
}
void LR(AvlTree &T)
{
    RR(T->left);
    LL(T);
}
void RL(AvlTree &T)
{
    LL(T->right);
    RR(T);
}
void insert(AvlTree &T, int x)
{
    if (T == NULL)
    {
        T = (AvlNode *)malloc(sizeof(AvlNode));
        T->left = NULL;
        T->right = NULL;
        T->height = 1;
        T->size = 1;
        T->same = 1;
        T->data = x;
        return;
    }
    if (x == T->data)
    {
        T->same++;
        update(T);
        return;
    }
    else if (x < T->data)
    {
        insert(T->left, x), update(T);
        if (GetHeight(T->left) - GetHeight(T->right) > 1)
        {
            if (x < T->left->data)
                LL(T);
            else
                LR(T);
        }
    }
    else if (x > T->data)
    {
        insert(T->right, x), update(T);
        if (GetHeight(T->right) - GetHeight(T->left) > 1)
        {
            if (x > T->right->data)
                RR(T);
            else
                RL(T);
        }
    }
    update(T);
}
void Delete(AvlNode *&T, int x)
{
    if (T == NULL)
        return;
    if (T->data == x)
    {
        if (T->same > 1)
        {
            (T->same)--;
            update(T);
            return;
        }
        if (T->left && T->right)
        {
            AvlTree q = T->right;
            while (q->left)
                q = q->left;
            T->data = q->data, T->same = q->same;
            q->same = 1;
            Delete(T->right, q->data);
            update(T);
            if (GetHeight(T->left) - GetHeight(T->right) > 1)
            {
                if (GetHeight(T->left->left) >= GetHeight(T->left->right))
                    LL(T);
                else
                    LR(T);
            }
        }
        else
        {
            AvlTree q = T;
            if (T->left)
                T = T->left;
            else if (T->right)
                T = T->right;
            else
                T = NULL;
            free(q);
            q = NULL;
        }
    }
    else if (x < T->data)
    {
        Delete(T->left, x), update(T);
        if (GetHeight(T->right) - GetHeight(T->left) > 1)
        {
            if (GetHeight(T->right->left) <= GetHeight(T->right->right))
                RR(T);
            else
                RL(T);
        }
    }
    else
    {
        Delete(T->right, x), update(T);
        if (GetHeight(T->left) - GetHeight(T->right) > 1)
        {
            if (GetHeight(T->left->left) >= GetHeight(T->left->right))
                LL(T);
            else
                LR(T);
        }
    }
    if (T == NULL)
        return;
    update(T);
}
int searchrankbyvalue(AvlTree T, int x)
{
    // if(T==NULL)
    //     return 0;
    if (T->data == x)
        return GetSize(T->left) + 1;
    if (T->data > x)
        return searchrankbyvalue(T->left, x);
    else
        return GetSize(T->left) + T->same + searchrankbyvalue(T->right, x);
}
int searchvaluebyrank(AvlTree T, int x)
{
    //  if(T==NULL)
    //      return 0;
    if (GetSize(T->left) >= x)
        return searchvaluebyrank(T->left, x);
    if (GetSize(T->left) + T->same >= x)
        return T->data;
    return searchvaluebyrank(T->right, x - GetSize(T->left) - T->same);
}
int GetPre(AvlTree T, int x)
{
    AvlTree ans, p;
    ans = (AvlTree)malloc(sizeof(AvlNode));
    ans->data = INT_MIN;
    p = T;
    while (p)
    {
        if (p->data == x)
        {
            if (p->left)
            {
                p = p->left;
                while (p->right)
                    p = p->right;
                ans = p;
            }
            break;
        }
        if (p->data < x && p->data > ans->data)
            ans = p;
        p = p->data >= x ? p->left : p->right;
    }
    return ans->data;
}
int GetBack(AvlTree T, int x)
{
    AvlTree ans, p;
    ans = (AvlTree)malloc(sizeof(AvlNode));
    ans->data = INT_MAX;
    p = T;
    while (p)
    {
        if (p->data == x)
        {
            if (p->right)
            {
                p = p->right;
                while (p->left)
                    p = p->left;
                ans = p;
            }
            break;
        }
        if (p->data > x && p->data < ans->data)
            ans = p;
        p = p->data >= x ? p->left : p->right;
    }
    return ans->data;
}
int main()
{
    int n;
    AvlTree root;
    root = NULL;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int opt, x;
        scanf("%d%d", &opt, &x);
        switch (opt)
        {
        case 1:
            insert(root, x);
            break;
        case 2:
            Delete(root, x);
            break;
        case 3:
            printf("%d\n", searchrankbyvalue(root, x));
            break;
        case 4:
            printf("%d\n", searchvaluebyrank(root, x));
            break;
        case 5:
            printf("%d\n", GetPre(root, x));
            break;
        case 6:
            printf("%d\n", GetBack(root, x));
            break;
        }
    }
}