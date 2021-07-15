#include <limits.h>
#include <stdio.h>
int a[5000001];
int d[5000001];
int main()
{
    int n, p;
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
        d[i] = a[i] - a[i - 1];//计算差分序列
    for (int i = 0; i < p; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        d[x] += z;//根据规则特征，将差分序列某一段的对应的数做修改
        d[y + 1] -= z;
    }
    int min = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + d[i];//得到后来的正确的序列
        if (min > a[i])//计算最小值
            min = a[i];
    }
    printf("%d", min);
}