#include<stdio.h>
int main()
{
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    int x[101];
    for (int i = 1; i <= n;i++)
    {
        x[i] = 0;
    }
    for (int i = 1; i <= m;i++)
    {
        scanf("%d %d", &a, &b);
        for (int j = a; j <= b;j++)
        {
            x[j]++;
        }
    }
    for (int i = 1; i <= n;i++)
    {
        if(x[i]!=1)
        {
            printf("%d %d", i, x[i]);
            return 0;
        }
    }
    printf("OK");
}