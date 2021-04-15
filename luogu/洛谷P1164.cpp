#include<stdio.h>
int main()
{
    int n, m, a[101],i,way[1001]={0},j;
    way[0] = 1;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= n;i++)
    {
        for (j = m; j >= a[i];j--)
        {
            way[j] += way[j - a[i]];
        }
        printf("\n%d\n", i);
        for (j = 1; j <= m;j++)
            printf("%d ", way[j]);
    }
    printf("%d", way[m]);
}