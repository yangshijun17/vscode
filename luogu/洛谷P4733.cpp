#include<stdio.h>
void dfs(int now, int n);
int flag[100],a[100];
int main()
{
    int n;
    scanf("%d", &n);
    dfs(1, n);
}
void dfs(int now,int n)
{
    if(now==n+1)
    {
        for (int i = 1; i <= n;i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 1; i <= n;i++)
    {
        if(!flag[i]){
            flag[i] = 1;
            a[now] = i;
            dfs(now + 1, n);
            flag[i] = 0;
        }
    }
}