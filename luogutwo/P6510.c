#include <stdio.h>
int stamax[10005], a[10005], stamin[10005], maxtop, mintop;
int bis(int left, int right);
int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    // for (int i = 1; i <= n; i++)
    //     scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        while (maxtop && a[stamax[maxtop]] < a[i])
            maxtop--;
        while (mintop && a[stamin[mintop]] > a[i])
            mintop--;
        int k = bis(1, mintop);
        if (k != mintop + 1)
            ans = (i + 1 - stamin[k]) > ans ? i + 1 - stamin[k] : ans;
        stamax[++maxtop] = i;
        stamin[++mintop] = i;
    }
    printf("%d\n", ans);
}
int bis(int left, int right)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (stamin[mid] > stamax[maxtop])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left;
}