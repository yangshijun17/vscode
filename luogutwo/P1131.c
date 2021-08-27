#include <stdio.h>
#define max(a, b) (a > b) ? (a) : (b)
struct edge
{
    int next, to, w;
};
struct edge edges[1000002];
int head[500001];
int cnt;
void dfs(int s, int v);
void add(int u, int v, int w);
long long ans;
int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 0; i <= n; i++)
        head[i] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    dfs(s, -1);
    printf("%lld", ans);
}
void add(int u, int v, int w)
{
    edges[cnt].to = v;
    edges[cnt].w = w;
    edges[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int s, int v)//s是当前搜索结点，v是其父亲节点
{
    for (int i = head[s]; i != -1; i = edges[i].next)
    {
        if (edges[i].to == v)//因为我们把无向边变成了两条有向边，所以有可能出现这种情况
            continue;
        dfs(edges[i].to, s);//一直搜索到叶子节点
    }
    int maxn = 0;
    for (int i = head[s]; i != -1; i = edges[i].next)
    {
        if (edges[i].to == v)
            continue;
        maxn = max(edges[i].w, maxn);//这一个循环用来找所有和当前节点相邻的边中权值最大的
    }
    for (int i = head[s]; i != -1; i = edges[i].next)
    {
        if (edges[i].to == v)
            continue;
        ans += (maxn - edges[i].w);//对于每个叶子节点，要想满足条件，只需要更新到当前的maxn即可
    }
    if (v == -1)
        return;
    for (int i = head[v]; i != -1; i = edges[i].next)
    {
        if (edges[i].to == s)
            edges[i].w += maxn;//用来找到当前结点和其父亲节点的那一条边，更新权值
    }
}