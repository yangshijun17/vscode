/*floyd算法的思想是要缩短两个点间的距离只可能通过别的点来缩短距离*/
/*时间复杂度为O(n^3)*/
#include<stdio.h>
#define INT_MAX 99999
int main()
{
    int n,g[100][100];
    printf("请输入顶点个数：\n");
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            if(i==j)
            {
                g[i][j] = 0;
            }
            else 
            {
                g[i][j] = INT_MAX;
            }
        }
    }
    //以上为初始化的内容
    int ii, jj, len=0;
    printf("请输入各点的信息\n以-1截止\n");
    while(len!=-1)
    {
        scanf("%d %d %d", &ii, &jj, &len);
        g[ii][jj] = len;
    }
    for (int k = 1; k <= n;k++)//k起到了遍历所有结点的作用
    {
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= n;j++)
            {
                if(g[i][j]>g[i][k]+g[k][j])
                {
                    g[i][j] = g[i][k] + g[k][j];
                }
                /*如果有一个中间结点缩短了距离，就更新距离*/
            }
        }
    }
    printf("最终求得最短距离的邻接矩阵如下");
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
}