#include <stdio.h>
#define maxn 99999999
//long long ans;
int n, a[10001];
int find();
int main()
{
    long long ans=0;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1;i++)
        ans += find();
        printf("%lld", ans);
}
int find()
{
    int min1 = maxn, min2 = maxn;
    int mark1 = 1, mark2 = 1;
    for (int i = 1; i <= n;i++)
    if(a[i]!=0)
    {
        if(a[i]<min1)
        {
            min1 = a[i];
            mark1 = i;
        }
    }
    a[mark1] = 0;
    for (int i = 1; i <= n;i++)
    if(a[i]!=0)
    {
        if(a[i]<min2)
        {
            min2 = a[i];
            mark2 = i;
        }
    }
    a[mark1] = min1 + a[mark2];
    a[mark2] = 0;
    return a[mark1];
}