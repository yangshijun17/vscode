#include<stdio.h>
#include<stdlib.h>
void table_(int n);
int table[30][30],n,sum,a[13],flag,flag_[13];
void dfs(int s,int depth);
int main()
{
    scanf("%d%d", &n, &sum);
    table_(n);
    dfs(0,1);
}
void dfs(int s,int depth)
{
    if(s>sum)
        return;
    if(depth==n+1){
    if(s==sum)
    {
        for (int i = 1; i <= n;i++)
        {
            printf("%d ", a[i]);
        }
        exit(0);
    }
    return;
    }
    for (int i = 1; i <= n;i++)
    {
        if(!flag_[i])
        {
            a[depth] = i;
            flag_[i] = 1;
            dfs(s + i*table[n][depth], depth + 1);
            flag_[i] = 0;
        }
    }
}
void table_(int n)
{
    int i, j;
    table[1][1] = 1;
    for (i = 2; i <= n;i++)
    {
        for (j = 1; j <= i;j++)
            table[i][j] = table[i-1][j - 1] + table[i - 1][j];
    }
}