#include<stdio.h>
int f[1000000],x[1000000],y[1000000],z[1000000];
int find(int x)//该函数用来找到x的爸爸
{
    if(f[x]==x)
        return x;
    else
        return find(f[x]);
}
void merge(int x,int y)
{
    f[find(y)] = find(x);//把两个人的爸爸变成一个
}
void findyx(int x,int y)
{
    if(find(x)==find(y))//两个人在同一个集合的条件就是两个人的爸爸是一个人
    {
        printf("Y\n");
    }
    else
        printf("N\n");
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m;i++)
    {
        scanf("%d%d%d", &z[i], &x[i], &y[i]);
        f[i] = i;
    }
    for (int i = 1; i <= m;i++)
    {
        if(z[i]==1)
        {
            merge(x[i], y[i]);
        }
        else if(z[i]==2)
        {
            findyx(x[i], y[i]);
        }
    }
    return 0;
}