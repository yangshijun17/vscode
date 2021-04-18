#include<stdio.h>
#define N 100
#define max 9999999
void dijkstra(int g[][N], int n,int v0);
int flag[N], path[N],dis[N];
int main()
{
    int n,g[N][N];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
        {
            if(i==j)
            {
                g[i][j] = 0;
            }
            else
                g[i][j] = max;
        }
    int ii, jj,len;
    while(ii!=-1)
    {
        scanf("%d %d %d", &ii, &jj, &len);
        g[ii][jj] = len;
    }
    printf("please input the source:\n");
    scanf("%d", &ii);
    for (int i = 1; i <= n;i++)
    {
        dis[i] = g[ii][i];
        if(dis[i]<max)
        {
            path[i] = ii;
        }
        else
        {
            path[i] = -1;
        }
    }
    flag[ii] = 1;
    dijkstra(g, n, ii);
    printf("%d", dis[6]);
}
void dijkstra(int g[][N],int n,int v0)
{
    for (int i = 2; i <= n;i++)
    {
        int min = max;
        int v = v0;
        for (int w = 1; w <= n;w++)
        {
            if(!flag[w]&&dis[w]<min)
            {
                v = w;
                min = dis[w];
            }
            flag[v] = 1;
            for (int w = 1; w <= n;w++)
            {
                if(!flag[w]&&(dis[v]+g[v][w]<dis[w]))
                {
                    dis[w] = dis[v] + g[v][w];
                    path[v] = w;
                }
            }
        }
    }
}