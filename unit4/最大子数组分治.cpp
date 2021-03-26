#include<stdio.h>
#include<limits.h>
#define max(a,b,c) ((a>b?(a>c?a:c):(b>c?b:c)))
int merge(int a[], int left, int right);
int main()
{
    int n, a[30];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d", merge(a, 1, n));
}
int merge(int a[],int left,int right)//如果要知道具体是数组中的哪一段，只需要记录两个参数就行了
{
    if(left==right)
    {
        if(a[left]<0)
            return 0;
        else
            return a[left];
    }
        int mid = (left + right) / 2;
        int maxleft=merge(a, left, mid);
        int maxright=merge(a, mid + 1, right);
        int maxmidleft=0, maxmidright=0,thismaxleft=INT_MIN,thismaxright=INT_MIN;
        for (int i = mid; i >= left;i--)
        {
            maxmidleft += a[i];
            if(maxmidleft>thismaxleft)
            {
                thismaxleft = maxmidleft;
            }
        }
        for (int i = mid+1; i <= right;i++)
        {
            maxmidright += a[i];
            if(maxmidright>thismaxright)
            {
                thismaxright = maxmidright;
            }
        }
        return max(maxleft, maxright, (thismaxleft + thismaxright));
}