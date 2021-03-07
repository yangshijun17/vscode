#include<stdio.h>
#include<limits.h>
#define min(a,b) (a>b?b:a)
int m,n,flag[101][101],ans=INT_MAX,f[101][101];
void dfs(int money,int x,int y,int flag_);
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <= m;j++)
            flag[i][j] = 2;
    }
    for (int i = 1; i <= n;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        scanf("%d", &flag[x][y]);
    }
	for (int i = 1; i <= m;i++)
		for (int j = 1; j <= m;j++)
		{
			f[i][j] = INT_MAX;
		}
			dfs(0, 1, 1, 0);
    if(ans==INT_MAX){
        printf("-1");
        return 0;
    }
    printf("%d", ans);
}
void dfs(int money,int x,int y,int flag_)
{
    if(money>=f[x][y])
		return;
	if(x<=0||y<=0||x>m||y>m)
        return;
    if(x==m&&y==m){
        ans = min(money, ans);
        return;
		}
		f[x][y] = money;
		for (int i = 0; i < 4; i++)
		{
			if (flag[x + dx[i]][y + dy[i]] != 2)
			{
				if (flag[x][y] == flag[x + dx[i]][y + dy[i]])
				{
					dfs(money, x + dx[i], y + dy[i], 0);
				}
				else
					dfs(money + 1, x + dx[i], y + dy[i], 0);
			}
			else if (!flag_)
			{
				flag[x + dx[i]][y + dy[i]] = flag[x][y];
				dfs(money + 2, x + dx[i], y + dy[i], 1);
				flag[x + dx[i]][y + dy[i]] = 2;
				money = money - 2;
			}
	}
	}