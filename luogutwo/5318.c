//要想清楚该用一种怎样的数据结构去存储图
//这道题有别于无向图，有向图可以有没输出的点
#include <stdio.h>
#include <stdlib.h>
typedef struct ArcNode
{                            //表结点类型定义
    int adjvex;              //顶点位置编号
    struct ArcNode *nextarc; //下一个表结点指针
} ArcNode;
typedef struct
{
    int key;
    ArcNode *firstvex;
} Graph;
Graph G[1000000];
int flag[1000000];
void dfs(int begin);
void bfs(int n);
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        G[i].key = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        ArcNode *p, *q = NULL, *r;
        for (p = G[x].firstvex; p != NULL; q = p, p = p->nextarc)
            if (p->adjvex > y)
                break;
        if (q == NULL && p == NULL)
        {
            r = (ArcNode *)malloc(sizeof(ArcNode));
            r->adjvex = y;
            r->nextarc = NULL;
            G[x].firstvex = r;
        }
        else if (q == NULL && p != NULL)
        {
            r = (ArcNode *)malloc(sizeof(ArcNode));
            r->adjvex = y;
            r->nextarc = p;
            G[x].firstvex = r;
        }
        else
        {
            r = (ArcNode *)malloc(sizeof(ArcNode));
            r->adjvex = y;
            q->nextarc = r;
            r->nextarc = p;
        }
    }
    dfs(1);
    printf("\n");
    bfs(n);
}
void dfs(int begin)
{
    flag[begin] = 1;
    printf("%d ", G[begin].key);
    ArcNode *p;
    for (p = G[begin].firstvex; p; p = p->nextarc)
    {
        int w = p->adjvex;
        if (!flag[w])
        {
            dfs(w);
        }
    }
}
int que[1000000];
void bfs(int n)
{
    for (int i = 0; i <= n; i++)
    {
        flag[i] = 0;
    }
    int front = 0, rear = 0;
    flag[1] = 1;
    que[rear++] = 1;
    printf("1 ");
    while (front != rear)
    {
        int j = que[front];
        front++;
        ArcNode *p = G[j].firstvex;
        while (p)
        {
            if (!flag[p->adjvex])
            {
                flag[p->adjvex] = 1;
                printf("%d ", p->adjvex);
                que[rear++] = p->adjvex;
            }
            p = p->nextarc;
        }
    }
}