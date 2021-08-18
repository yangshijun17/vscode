#include<stdio.h>
#define maxn 10000000
int a[101][101],b[10001];
int main()
{
    int n, m;
    scanf("%d%d", &n,&m);
    for (int i = 1; i <= m;i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            scanf("%d", &a[i][j]);
    for (int k = 1; k <= n;k++)
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= n;j++)
            if(a[i][j]>a[i][k]+a[k][j])
                a[i][j] = a[i][k] + a[k][j];
    int ans = 0,now=1;
    for (int i = 1; i <= m;i++)
    {
        ans += a[now][b[i]];
        now = b[i];
    }
    printf("%d", ans);
}