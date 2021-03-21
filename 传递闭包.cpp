#include<stdio.h>
void matrixmultiply(int n);
void matrixadd(int n);
int a[10][10], b[10][10], r[10][10],aa[10][10];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            scanf("%d", &r[i][j]);
            a[i][j] = r[i][j];
            b[i][j] = a[i][j];
        }
    }
    for (int i = 2; i <= n;i++)
    {
        matrixmultiply(n);
        matrixadd(n);
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}
void matrixmultiply(int n)
{
    int i, j,m;
    for (i = 1; i <= n;i++)
    {
        for (j = 1; j <= n;j++)
        {
            int sum = 0;
            for (m = 1; m <= n;m++)
            {
                sum += a[i][m] * r[m][j];
            }
            aa[i][j] = sum;
        }
    }
    for (i = 1; i <= n;i++)
        for (j = 1; j <= n;j++)
            a[i][j] = aa[i][j];
}
void matrixadd(int n)
{
    int i, j;
    for (i = 1; i <= n;i++)
    {
        for (j = 1; j <= n;j++)
        {
            b[i][j] = aa[i][j] + b[i][j];
        }
    }
}