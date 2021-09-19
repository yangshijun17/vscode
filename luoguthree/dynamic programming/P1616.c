/*
 * @Author: ysj 
 * @Date: 2021-09-19 10:30:27 
 * @Last Modified by: ysj
 * @Last Modified time: 2021-09-19 11:17:17
 */
/**
 * @brief  这道题是完全背包问题，是01背包的改版，原本最朴素的解法是利用三重循环实现，但是可以依据01背包的解法进行优化
 * @note   
 * @retval 
 */
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int ans[1000001];
int time[10001], value[10001];
int main()
{
    int t, m;
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m;i++)
        scanf("%d%d", &time[i], &value[i]);
    for (int i = 1; i <= m;i++)
        for (int j = time[i]; j <= t;j++)
                ans[j] = max(ans[j], ans[j - time[i]] + value[i]);
    printf("%d", ans[t]);
}