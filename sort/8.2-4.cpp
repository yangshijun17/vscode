#include<stdio.h>
int main()
{
    int a[20], c[20], l, r, max,n;
    scanf("%d", &n);
    max = -1;
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
        max = a[i] > max ? a[i] : max;
    }
    for (int i = 0; i <= max;i++)
    {
        c[i] = 0;
    }
    for (int i = 1; i <= n; i++)
        {
            c[a[i]]++;
        }
        scanf("%d%d", &l, &r);
        for (int i = 1; i <= max;i++)
        {
            c[i] += c[i - 1];
            /*根据计数排序的相关知识，这一步骤是统计有多少个数比i小*/
        }
        /*以上为预处理阶段*/
        printf("%d", c[r+1] - c[l]);
}