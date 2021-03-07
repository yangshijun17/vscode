#include<stdio.h>
int main()
{
    int n,f[100][3]={0};
    scanf("%d", &n);
    int i;
    f[0][0] = f[1][1] = f[0][2] = 1;
    for (i = 2; i <= n;i++)
    {
        f[i][0] = f[i - 1][1] + f[i - 2][0] + f[i - 2][2];
        f[i][1] = f[i - 1][2];
        f[i][2] = f[i][0] + f[i - 1][1];
    }
    printf("%d", f[n][0]);
}