/*dijkstra算法用来求解最短路径，其中每条边权值必须为正*/
/*dijkstra算法的基本思想很简单，即每次找到离最初点最近的结点，逐步向两
边扩充*/
/*该算法时间复杂度为O(n^2)，空间复杂度为O(n)*/
//该程序用图的邻接矩阵来存放图
#include <stdio.h>
#define N 100
#define max 9999999
void dijkstra(int g[][N], int n, int v0);
int flag[N], dis[N];
//dis数组用来存放最初点到第i个节点的距离
//flag数组用来统计当前结点是否走过
int main()
{
    int n, g[N][N];
    scanf("%d", &n);
    /*下面的二重循环用来对存放图的数组进行初始化*/
    /*自身结点为0，其余全部初始化为max*/
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                g[i][j] = 0;
            }
            else
                g[i][j] = max;
        }
    int ii, jj, len;
    /*下面的while循环将有权图的数据键入*/
    printf("请输入图的邻接矩阵\n");
    printf("注意，此处的邻接矩阵只需要输入有路的结点以及权值即可\n");
    scanf("%d %d %d", &ii, &jj, &len);
    while (ii != -1)
    {
        g[ii][jj] = len;
        scanf("%d %d %d", &ii, &jj, &len);
    }
    printf("请输入最开始的结点:\n");
    scanf("%d", &ii);
    /*接下来的一重循环对dis数组进行初始化*/
    for (int i = 1; i <= n; i++)
    {
        dis[i] = g[ii][i];
    }
    flag[ii] = 1; /*最初在ii处，对其进行初始化*/
    dijkstra(g, n, ii);
    printf("到第8个结点的最短距离为:");
    printf("%d", dis[8]);
}
void dijkstra(int g[][N], int n, int v0) //n表示节点数，g数组存放
//邻接矩阵，v0表示要求的结点
{
    for (int i = 1; i <= n; i++)
    {
        int min = max;
        int v = v0;
        for (int w = 1; w <= n; w++)
        {
            if (!flag[w] && dis[w] < min)
            {
                v = w;
                min = dis[w];
            }
        }
        /*上面那个一重循环用来找到没去过的并且距离最短的结点，用v储存*/
        flag[v] = 1;//将v标记为走过
        for (int w = 1; w <= n; w++)
        {
            if (!flag[w] && (dis[v] + g[v][w] < dis[w]))
            {
                dis[w] = dis[v] + g[v][w];
            }
            //如果更小就更新即可
        }
    }
}