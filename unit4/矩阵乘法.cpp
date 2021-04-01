#include<stdio.h>
int main()
{
    int n, m, t, a[10][10], b[10][10], c[10][10];
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= t;j++)
        {
            c[i][j] = 0;
            for (int k = 1; k <= n;k++)
            {
                c[i][j] += a[i][k] * a[k][j];
            }
        }
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= t;j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}