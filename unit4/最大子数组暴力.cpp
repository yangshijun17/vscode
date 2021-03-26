#include<stdio.h>
#include<limits.h>
int main()
{
    int n,a[20];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    int maxsum = INT_MIN,nowsum;
    for (int i = 1; i <= n;i++)
    {
        nowsum = 0;
        for (int j = i; j <= n;j++)
        {
            nowsum += a[j];
            if(nowsum>maxsum)
            {
                maxsum = nowsum;
            }
        }
    }
    printf("%d", maxsum);
}