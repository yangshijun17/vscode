#include<stdio.h>
#include<limits.h>
int main()
{
    int n, a[20];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    int maxsum = INT_MIN,nowsum=0;
    for (int i = 1; i <= n; i++)
    {
        nowsum += a[i];
        if(nowsum>maxsum)
        {
            maxsum = nowsum;
        }
        else if(nowsum<0)
        {
            nowsum = 0;
        }
    }
}