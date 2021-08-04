#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    int flag;
    int left;
    int right;
} list;
list lists[1000000];
int main()
{
    int n, k, p;
    scanf("%d", &n);
    lists[1].flag = 1;
    lists[1].key = 1;
    lists[1].left = lists[1].right = 1;
    lists[0].key = 1;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d%d", &k, &p);
        if (p == 0 && lists[0].key == k)
        {
            lists[0].key = i;
        }
        lists[i].flag = 1;
        lists[i].key = i;
        if (p == 0)
        {
            lists[lists[k].left].right = i;
            lists[i].left = lists[k].left;
            lists[i].right = k;
            lists[k].left = i;
        }
        else
        {
            lists[lists[k].right].left = i;
            lists[i].right = lists[k].right;
            lists[i].left = k;
            lists[k].right = i;
        }
    }
    int m;
    scanf("%d", &m);
    int length = n;
    for (int i = 0; i < m; i++)
    {
        int p;
        scanf("%d", &p);
        if (lists[p].flag == 0)
        {
            continue;
        }
        else
        {
            lists[p].flag = 0;
            lists[lists[p].left].right = lists[p].right;
            lists[lists[p].right].left = lists[p].left;
            length--;
        }
    }
    for (int i = 0, j = lists[0].key; i < length;i++,j=lists[j].right)
    {
        printf("%d ", lists[j].key);
    }
}
