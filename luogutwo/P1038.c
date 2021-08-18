#include <stdio.h>
#define maxn 1000000
typedef struct
{
    int u;
    int key;
    int c;
    int indeg;
    int outdeg;
    int flag;
} node;
int main()
{
    int n, p;
    node nodes[101];
int a[101][101]={maxn}, flag[101];
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
    {
        int c, u;
        scanf("%d%d", &c, &u);
        nodes[i].key = i;
        nodes[i].u = u;
        nodes[i].c = c;
        nodes[i].outdeg = 0;
        nodes[i].indeg = 0;
        flag[i] = 0;
    }
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            a[i][j] = maxn;
            for (int i = 1; i <= p; i++)
            {
                int u, v, w;
                scanf("%d%d%d", &u, &v, &w);
                nodes[u].outdeg++;
                nodes[v].indeg++;
                a[u][v] = w;
            }
    for (int i = 1; i <= n; i++)
    {   if(nodes[i].indeg!=0)
            nodes[i].c = nodes[i].c - nodes[i].u;
        if (nodes[i].outdeg == 0)
            nodes[i].flag = 1;
        a[i][i] = 0;
            }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (nodes[j].indeg == 0 && !flag[j] && nodes[j].outdeg != 0&&nodes[j].c>0)
            {
                flag[j] = 1;
                for (int k = 1; k <= n; k++)
                {
                    if (a[j][k] != maxn && j != k && nodes[k].indeg != 0)
                    {
                        nodes[k].c += a[j][k] * nodes[j].c;
                        nodes[k].indeg--;
                        nodes[j].outdeg--;
                    }
                    if (nodes[j].outdeg <= 0)
                        break;
                }
            }
        }
    }
    int flag1 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (nodes[i].flag && nodes[i].c > 0)
        {
            flag1 = 1;
            printf("%d %d\n", nodes[i].key, nodes[i].c);
        }
    }
    if (flag1 == 0)
        printf("NULL");
}