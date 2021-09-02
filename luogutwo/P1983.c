#include<stdio.h>
#include<string.h>
typedef struct
{
    int next, to;
}edge;//链式前向星存边
edge edges[1000001];
int head[1001],cnt,v[1001],ans,a[1001],flag[1001],flag1[1001][1001],que[100001],dep[1001];
//head数组存边，v数组存放入度，a数组用在每次读入的时候，flag数组用来判定是否通过，通过为1，flag1数组用来判断是否已经
//有边，有边则不加边，队列用来做拓扑，dep数组存放轨迹长度
void add(int u, int v);
void toposort(int n);
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));//初始化head
    for (int i = 1; i <= m;i++)
    {
        memset(a, 0, sizeof(a));
        memset(flag, 0, sizeof(flag));//每次循环前对读入的数组进行初始化
        int nn;
        scanf("%d", &nn);
        for (int j = 1; j <= nn;j++)
        {
            scanf("%d", &a[j]);
            flag[a[j]] = 1;//经过置为1
        }
        for (int j = a[1] + 1; j <= a[nn];j++)//然后在这条序列上进行相应的处理
        {
            if(!flag[j])//主要处理没经过的
            {
                for (int k = 1; k <= nn;k++)
                {
                    if(!flag1[j][a[k]])//在没经过的和经过的之间加一条边
                    {
                        v[a[k]]++;//入度增加
                        add(j, a[k]);
                        flag1[j][a[k]] = 1;
                    }
                }
            }
        }
    }
    toposort(n);
    printf("%d", ans);
}
void add(int u,int v)//加边
{
    edges[cnt++].to = v;
    edges[cnt].next = head[u];
    head[u] = cnt;
}
void toposort(int n)
{
    int front,rear;
    front = rear = 0;
    for (int i = 1; i <= n;i++)
    {
        if(!v[i])
        {
            que[rear++] = i;
            dep[i] = 1;
        }
    }
    while(rear!=front)
    {
        int t = que[front];
        front++;
        for (int i = head[t]; i != -1;i=edges[i].next)
        {
            int vv = edges[i].to;
            dep[vv] = dep[t] + 1;
            ans = ans > dep[vv] ? ans : dep[vv];
            v[vv]--;
            if(!v[vv])
                que[rear++] = vv;
        }
    }
}