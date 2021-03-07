#include<stdio.h>
int main()
{
    int n, f[1000][2];
    scanf("%d", &n);
    f[0][0] = 0, f[0][1] = 0;
    for (int i = 1; i <= n;i++){
        f[i][0] = f[i - 1][0] + f[i - 1][1];
        f[i][1] = f[i - 1][0] + f[i - 1][1] + i % 2;
    }
    printf("%d", f[n-1][1]);
}