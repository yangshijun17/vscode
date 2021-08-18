#include <stdio.h>
int f[10001];
int find(int x) //该函数用来找到x的爸爸
{
    if(f[x]==x)
        return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy)
        f[fx] = fy;
}
void findyx(int x, int y)
{
    if (find(x) == find(y)) //两个人在同一个集合的条件就是两个人的爸爸是一个人
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
    int x, y, z;
    for (int i = 1; i <= n; i++)
        f[i] = i;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &z, &x, &y);
        if (z == 1)
            merge(x, y);
        if (z == 2)
            findyx(x, y);
    }
}