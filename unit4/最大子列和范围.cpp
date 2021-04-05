#include<stdio.h>
#include<limits.h>
struct arr{
    int l;
    int r;
    int nowsum;
}a;
arr function(int a[],int left, int right);
int main()
{
    int n,b[20];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &b[i]);
    }
    a = function(b, 1, n);
    printf("%d %d %d", a.l, a.r, a.nowsum);
}
arr function(int a[],int left,int right)
{
    if(left==right)
    {
        struct arr b;
        b.l = left;
        b.r = right;
        b.nowsum = a[left];
        return b;
    }
    struct arr le, ri;
    int mid = (left + right) / 2;
    le = function(a, left, mid);
    ri = function(a, mid + 1, right);
    int nowleft=0, nowright=0,maxleft=INT_MIN,maxright=INT_MIN;
    struct arr ans;
    for (int i = mid; i >= left;i--)
    {
        nowleft += a[i];
        if(nowleft>maxleft)
        {
            maxleft = nowleft;
            ans.l = i;
            //ans.nowsum = maxleft;
        }
    }
    for (int i = mid+1; i <= right;i++)
    {
        nowright += a[i];
        if(maxright<nowright)
        {
            maxright = nowright;
            //ans.nowsum = maxright;
            ans.r = i;
        }
    }
    int max = maxleft + maxright;
    ans.nowsum = max;
    if(max>=le.nowsum&&max>=ri.nowsum)
    {
        return ans;
    }
    else if(le.nowsum>=max&&le.nowsum>=ri.nowsum)
    {
        return le;
    }
    else
    {
        return ri;
    }
}