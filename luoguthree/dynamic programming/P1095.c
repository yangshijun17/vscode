/*
 * @Author: ysj 
 * @Date: 2021-09-19 09:46:51 
 * @Last Modified by: ysj
 * @Last Modified time: 2021-09-19 09:58:03
 */
/**
 *! @brief  动态规划入门题
 * @note   
 * @retval 
 */
#include<stdio.h>
int main()
{
    int m, s, t;
    scanf("%d%d%d", &m, &s, &t);
    int s1=0, s2=0;
    for (int i = 1; i <= t;i++)
    {
        s1 += 17;
        if(m>=10)
        {
            s2 += 60;
            m -= 10;
        }
        else
            m += 4;
        if(s2>s1)
            s1 = s2;
        if(s1>s)
        {
            printf("Yes\n");
            printf("%d", i);
            return 0;
        }
    }
    printf("No\n");
    printf("%d", s1);
}