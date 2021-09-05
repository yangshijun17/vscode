#include<stdio.h>
#include<stdlib.h>
//C语言内置的快速排序比手写快排要更快
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int n,c, a[100001];
int check(int mid);
// void quicksort(int left, int right);
// int partition(int left, int right);
int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    // quicksort(1, n);
    qsort(a + 1, n, sizeof(a[0]), cmp);
    int left = 0, right = a[n]-a[1];
    int ans = 0;
    while(left<=right)
    {
        int mid = (left + right) >> 1;
        if(check(mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    printf("%d", ans);
}
int check(int mid)
{
    int num = 1;
    int x = a[1];
    for (int i = 2; i <= n && num < c;i++)
    {
        if(a[i]-x>=mid)
        {
            num++;
            x = a[i];
        }
    }
    if(num>=c)
        return 1;
    else
        return 0;
}
// void quicksort(int left,int right)
// {
//     if(right<left)
//         return;
//     int q = partition(left, right);
//     quicksort(left, q - 1);
//     quicksort(q + 1, right);
// }
// int partition(int left,int right)
// {
//     a[0] = a[left];
//     int x = a[left];
//     while(left<right)
//     {
//         while(left<right&&a[right]>x)
//             right--;
//         a[left] = a[right];
//         while(left<right&&a[left]<x)
//             left++;
//         a[right] = a[left];
//     }
//     a[left] = a[0];
//     return left;
// }