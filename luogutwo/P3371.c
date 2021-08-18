//prim算法
//注释掉的是使用链式向前星存图方法，暂时还没找到bug在哪
/*
#include <stdio.h>
#define maxn 100000000
typedef struct
{
    int w;
    int now;
    int nexty;
} edge;
edge edges[200002];
int head[200002], flag[5001], cnt = 0, dis[5001];
void add(int u, int v, int w);
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    for (int i = 2; i <= n;i++)
    {
        dis[i] = maxn;
    }
    for (int i = head[1]; i != 0;i=edges[i].nexty)
        dis[edges[i].now] = dis[edges[i].now] > edges[i].w ? edges[i].w : dis[edges[i].now];
    int sum = 0, num = 0;
    int now = 1;
    while(num<n-1)
    {
        int min = maxn;
        flag[now] = 1;
        for (int j = 1; j <= n; j++)
            if (!flag[j] && dis[j] < min)
                min = dis[j], now = j;
        //flag[now] = 1;
        sum += min;
        num++;
        for (int j = head[now]; j; j = edges[j].nexty)
        {
            if (dis[edges[j].now] > edges[j].w && !flag[edges[j].now])
                dis[edges[j].now] = edges[j].w;
        }
    }
    if (num != n - 1)
        printf("orz");
    else
        printf("\n%d", sum);
}
void add(int u, int v, int w)
{
    cnt++;
    edges[cnt].w = w;
    edges[cnt].now = v;
    edges[cnt].nexty = head[u];
    head[u] = cnt;
}
*/
#include <stdio.h>
#define maxn 1000000
int G[5001][5001], flag[5001], dis[5001];
int main()
{
    int m, n;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (i == j)
                G[i][j] = 0;
            else
                G[i][j] = maxn;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = G[u][v]>w?w:G[u][v];
        G[v][u] = G[u][v];
    }
    for (int i = 0; i <= n;i++)
        dis[i] = G[1][i];
    int sum = 0, num = 0, now = 1;
    flag[now] = 1;
    dis[now] = 0;
    for (int k = 1; k <= n;k++)
    {
        now = 0;
        for (int i = 1; i <= n;i++)
        {
            if(!flag[i]&&dis[i]<dis[now])//这里的处理非常巧妙，因为每次找到的最小值肯定在dis数组中，保持了最优结构，所以只需要记录下标
                 now = i;
        }
        sum += dis[now];
        flag[now] = 1;
        for (int i = 1; i <= n;i++)
        {
            if(dis[i]>G[now][i])
            {
                dis[i] = G[now][i];
            }
        }
        num++;
        if(num==n-1&&sum<maxn)
            {printf("%d", sum);
        return 0;}
    }
    printf("orz");

}