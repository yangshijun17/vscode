#include<stdio.h>
int select(int a[], int p, int r, int i);
int partition(int a[], int p, int r);
int main()
{
    int n, a[20];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    int i;
    scanf("%d", &i);
    printf("%d", select(a, 1, n, i));
}
int select(int a[],int p,int r,int i)
{
    if(p==r)
    {
        return a[r];
    }
    int q = partition(a, p, r);//求出比主元要小的分界线
    int k = q - p + 1;//计算出比主元小的个数
    if(i==k)//如果刚好在主元前面有i个比他小的(包括它本身)
    {//则直接返回该主元即可
        return a[q];
    }
    /*接下来类似于二分查找的思想*/
    else if(i<k)//如果当前k>i，说明第i小的值在前面，递归查找即可
    {
        return select(a, p, q - 1, i);
    }
    else//类似的
    {
        return select(a, q+1, r, i-k);
    }
}
int partition(int a[],int p,int r)
{
    /*其实本应该随机选取主元的，这里为了方便，没有这样做*/
    int x = a[r];
    int i, j;
    i = p - 1, j = p;
    for (; j <= r;j++)
    {
        if(a[j]<x)
        {
            i++;
            int t;
            t = a[i], a[i] = a[j], a[j] = t;
        }
    }
    int t;
    t = a[i + 1], a[i + 1] = a[r], a[r] = t;
    return i + 1;
}