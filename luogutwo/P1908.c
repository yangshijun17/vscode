#include<stdio.h>
int a[500001],tmp[500001];
long long ans;
void mergesort(int left, int right);
void merge(int left, int right);
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    mergesort(1, n);
    printf("%lld", ans);
}
void mergesort(int left,int right)
{
    if(left==right)
        return;
    int mid = (left + right) / 2;
    mergesort(left, mid);
    mergesort(mid+1, right);
    merge(left, right);
}
void merge(int left, int right)
{
    int k = 0,i=left,mid=(left+right)/2;
    int j = mid + 1;
    while(i<=mid&&j<=right)
    {
        if(a[i]<=a[j])
            tmp[k++] = a[i++];
        else
        {
            ans += mid - i + 1;
            tmp[k++] = a[j++];
        }
    }
    while(i<=mid)
        tmp[k++] = a[i++];
    while(j<=right)
        tmp[k++] = a[j++];
    for (k = 0, i = left; i <= right;i++,k++)
        a[i] = tmp[k];
}