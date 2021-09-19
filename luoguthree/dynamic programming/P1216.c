#include<stdio.h>
#define max(a,b) (a)>(b)?(a):(b)
int main()
{
    int r;
    int a[101][101];
    int b[101][101];
    scanf("%d", &r);
    for (int i = 0; i < r;i++)
    {
        for (int j = 0; j <= i;j++)
            scanf("%d", &a[i][j]);
    }
    b[0][0] = a[0][0];
    for (int i = 1; i < r;i++)
    {
        b[i][0] += b[i - 1][0] + a[i][0];
        // b[i][i] += b[i - 1][i - 1] + a[i][i];
    }
    for (int i = 1; i < r;i++)
    {
        for (int j = 1; j <= i;j++)
        {
            b[i][j] = max(b[i - 1][j - 1], b[i - 1][j]);
            b[i][j] += a[i][j];
            //值得一提的是这里在我最开始，写的是b[i][j]=max(b[i-1][j-1],b[i-1][j])+a[i][j]
            //然而由于三目运算符优先级低于加法运算，导致一直出错！
        }
    }
    int max1=0;
    for (int i = 0; i < r;i++)
    if(max1<b[r-1][i])
        max1 = b[r - 1][i];
    printf("%d", max1);
}
