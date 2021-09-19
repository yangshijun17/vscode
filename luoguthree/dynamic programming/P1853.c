/*
 * @Author: ysj 
 * @Date: 2021-09-19 11:09:32 
 * @Last Modified by: ysj
 * @Last Modified time: 2021-09-19 11:20:29
 */
/**
 * @brief  此题目也是完全背包问题的一个改版，其实就是每次更新总资产然后循环即可
 * @note   
 * @retval 
 */
#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
long long s;
int n, d;
int w[11], v[11];
long long dp[10000001];
int main()
{
    scanf("%lld%d%d", &s, &n, &d);
    for (int i = 1; i <= d;i++)
        scanf("%d%d", &w[i], &v[i]);
    for (int y = 0; y < n;y++)
    {
        for (int i = 1; i <= d;i++)
            for (int j = w[i]; j <= s;j++)
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        s += dp[s];
    }
    printf("%lld", s);
}