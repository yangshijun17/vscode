#include<stdio.h>
int a[7][7],n,m, sum,flag[7][7],dx[]={-1,-1,-1,0,0,1,1,1},dy[]={1,-1,0,1,-1,1,0,-1};
void dfs(int x, int y, int sum_);
int main()
{
    int t;
    scanf("%d", &t);
    while(t){
        sum = 0;
        scanf("%d%d", &n, &m);
        int i, j;
        for (i = 1; i <= n;i++)
            for (j = 1; j <= m;j++)
                scanf("%d", &a[i][j]);
        dfs(1, 1,0);
        printf("%d\n", sum);
        t--;
    }
}
void dfs(int x, int y, int sum_)
{
    if(y>m){
        x++;
        y = 1;
    }
    if(x>n){
        sum = sum_ > sum ? sum_ : sum;
        return;
    }
    int i;
    if(!flag[x][y])
    {
        for (i = 0; i < 8;i++){
            flag[x + dx[i]][y + dy[i]]++;
        }
        dfs(x, y + 2,sum_ + a[x][y]);
        for (i = 0; i < 8;i++){
            flag[x + dx[i]][y + dy[i]]--;
        }
    }
    dfs(x, y + 1, sum_);
}