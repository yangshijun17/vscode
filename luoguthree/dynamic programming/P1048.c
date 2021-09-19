/*
 * @Author: ysj 
 * @Date: 2021-09-19 09:59:00 
 * @Last Modified by: ysj
 * @Last Modified time: 2021-09-19 10:24:39
 */
/**
 * @brief  动态规划中的背包问题，这里属于一种简单地01背包
 * @note   其实这道题目就相当于是一个模板了
 * @retval 
 */
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
    int t, m;
    int time[101], value[101];
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m;i++)
    {
        scanf("%d%d", &time[i], &value[i]);
    }
    int v[101][1001];
    for (int i = 0; i <= m;i++)
        v[i][0] = 0;
    for (int j = 0; j <= t;j++)
        v[0][j] = 0;
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <= t;j++)
        {
            if(j<time[i])//如果装不下
            {
                v[i][j] = v[i - 1][j];//那么就和之前那个相等
            }
            else
                v[i][j] = max(v[i-1][j],v[i-1][j-time[i]]+value[i]);//否则进行一次比较大小
        }
    }
    printf("%d", v[m][t]);
}