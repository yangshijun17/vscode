#include<stdio.h>
int a[31][31];
int b[31][31];
int n;
int dx[4] = {0,0,1,-1};
void dfs(int x, int y);
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j])
                b[i][j] = 1;
        }
    }
    for (int i = 1; i <= n;i++)
    {
        dfs(i, 1);
        dfs(i,n);
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            if(b[i][j])
                printf("1 ");
            else if(a[i][j])
                printf("0 ");
            else
                printf("2 ");
        }
        printf("\n");
    }
}
void dfs(int x,int y)
{
    if(x<1||y<1||x>n||y>n||a[x][y]==1)
        return;
    a[x][y] = 1;
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);
}