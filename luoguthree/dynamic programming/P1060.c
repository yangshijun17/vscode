/*
 * @Author: ysj 
 * @Date: 2021-09-19 10:13:47 
 * @Last Modified by: ysj
 * @Last Modified time: 2021-09-19 10:24:52
 */
/**
 * @brief  这道题其实就是背包问题的简单更改，将放入背包物品的价值和其容量作乘积求和
 * @note   
 * @retval 
 */
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int ans[30][30001];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int v[30], w[30];
    for (int i = 1; i <= m;i++)
    {
        scanf("%d%d", &v[i], &w[i]);
    }
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            if(j<v[i])
                ans[i][j] = ans[i - 1][j];
            else
                ans[i][j] = max(ans[i-1][j],ans[i-1][j-v[i]]+w[i]*v[i]);
        }
    }
    printf("%d", ans[m][n]);
}