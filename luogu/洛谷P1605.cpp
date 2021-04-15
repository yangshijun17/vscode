#include<stdio.h>
int n, m,fx,fy,ans,flag[10][10],t,map[10][10];
void dfs(int nowx, int nowy);
struct point_{
    int x, y;
}point[200];
int dx[4] = {1, -1, 0, 0},dy[4]={0,0,1,-1};
int main()
{
    int sx,sy;
    scanf("%d%d%d", &n, &m, &t);
    scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
    for (int i = 1; i <= t;i++)
    {
        scanf("%d%d", &point[i].x, &point[i].y);
        map[point[i].x][point[i].y] = 1;
    }
    dfs(sx, sy);
    printf("%d", ans);
}
void dfs(int nowx,int nowy)
{
    if(nowx==fx&&nowy==fy)
    {
        ans++;
        return;
    }
    //if(nowx>fx||nowy>fy||nowx<=0||nowy<=0)
        //return;
    for (int i = 0; i < 4;i++)
    {
        if(nowx+dx[i]>=1&&nowy+dy[i]>=1&&nowx+dx[i]<=n&&nowy+dy[i]<=m&&(!flag[nowx+dx[i]][nowy+dy[i]])&&(!map[nowx+dx[i]][nowy+dy[i]]))
        {
            flag[nowx][nowy] = 1;
            dfs(nowx + dx[i], nowy + dy[i]);
            flag[nowx][nowy] = 0;
        }
    }
}