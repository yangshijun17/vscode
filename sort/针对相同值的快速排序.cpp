#include<stdio.h>
void sort(int a[], int p, int r);
void partition(int a[], int p, int r);
int q1, q2;
int main()
{
    int n, a[20];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, 1, n);
    for (int i = 1; i <= n;i++)
    {
        printf("%d ", a[i]);
    }
}
void sort(int a[],int p,int r)
{
    if(p<r)
    {
        partition(a, p, r);
        sort(a, p, q1-1);//-1将前面不相同的继续排列
        sort(a, q2+1, r);//+1将后面不相同的继续排列
    }
}
void partition(int a[],int p,int r)
{
    int x = a[r],t=r;
    for (int i = p; i <= r - 1;i++)//该循环将与主元相同的元素移到数组右边
    {
        if(a[i]==x)
        {
            if(x==a[r-1])
            {
                i--;
                r--;
            }
            else{
                int m;
                m = a[i], a[i] = a[r - 1], a[r - 1] = m;
                r--;
            }
        }
    }
    int i=p-1;
    for (int j = p; j < r;j++)//该循环将前面不相同的元素进行划分
    {
        if(a[j]<x)
        {
            i++;
            int m;
            m = a[i], a[i] = a[j], a[j] = m;
        }
    }
    for (int k = 0; k < t - r + 1;k++)//该循环将后面相同的元素进行排列
    {
        int m;
        m = a[i + k + 1], a[i + k + 1] = a[r + k], a[r + k] = m;
    }
    q1 = i + 1, q2 = i + t - r+1;
    /*前i个元素均小于主元，和主元相同的元素共有t-r+1个，也就是说
    在数组中相同于主元的为i+1到t-r+1位置*/
}