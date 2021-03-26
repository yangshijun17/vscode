#include<stdio.h>
#include<limits.h>
int mergesort(int a[], int left, int right);
int merge(int a[], int left, int mid, int right);
int main()
{
    int n, a[20];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d", mergesort(a, 1, n));
}
int mergesort(int a[],int left,int right)
{
    if(left<right)
    {
        int ans = 0;
        int p = (left + right) / 2;
        ans+=mergesort(a, left, p);
        ans+=mergesort(a, p + 1, right);
        ans+=merge(a, left, p, right);
        return ans;
    }
    else {
        return 0;
    }
}
int merge(int a[], int left, int mid, int right)
    {
        int p = mid - left + 1, i, j;
        int q = right - mid, l[20], r[20];
        for (i = 1; i <= p; i++)
        {
            l[i] = a[i];
        }
        for (j = 1; j <= q; j++)
        {
            r[j] = a[j + p];
        }
        l[p + 1] = INT_MAX;
        r[q + 1] = INT_MAX;
        i = 1, j = 1;
        int ans = 0;
        for (int k = left; k <= right; k++)
        {
            if (l[i] > r[j])
            {
                ans+=p-i;
                a[k] = r[j++];
            }
            else{
                a[k] = l[i++];
            }
        }
        return ans;
}