#include<stdio.h>
#include<limits.h>
#define N 100
int prim(int primevertice);
int g[N][N],n,tree[N],shortest[N];
/*g数组用来存放图，tree数组最终用来存放生成树，shortest数组用来存放当前结点到
各个结点的距离*/
/*tree数组中存放的是和i结点相连的结点，可以说是子节点*/
int main()
{
    scanf("%d", &n);
    int i, j, len;
    for (i = 1; i <= n;i++)
    {
        for (j = 1; j <= n;j++)
        {
            if(i==j)
            {
                g[i][i] = 0;
            }
            else
                g[i][j] = INT_MAX;
        }
    }
    scanf("%d %d %d", &i, &j, &len);
    while(i!=-1)
    {
        g[i][j] = len;
        scanf("%d %d %d", &i, &j, &len);
    }
    printf("最小生成树权值为:%d\n", prim(1));
}
int prim(int primevertice)
{
    for (int i = 1; i <= n;i++)
    {
        shortest[i] = g[primevertice][i];
        tree[i] = primevertice;
    }
    /*以上循环用来对两个数组进行初始化，shortest[i]表示初始节点primevertice结点到
    第i个结点的距离*/
    int min=INT_MAX, v,sum=0;
    /*min储存最小权值，v储存最短边的结点，sum储存最小值*/
    for (int i = 1; i <= n;i++)
    {
        min = INT_MAX;
        for (int j = 1; j <= n;j++)
        {
            if(shortest[j]&&shortest[j]<min)
            {
                min = shortest[j];
                v = j;
            }
        }
        /*上述第一个循环用来找到最短边*/
        if(min==INT_MAX)//没有找到
            break;
        sum += min;
        shortest[v] = 0;//此时结点v从原有节点中删除
        for (int j = 1; j <= n;j++)//接下来这一重循环用来修改原有图
        {
            if(shortest[j]&&g[v][j]<shortest[j])
            {
                shortest[j] = g[v][j];//当前结点已经变成v了，所以更新shortest数组
                tree[j] = v;
            }
        }
    }
}