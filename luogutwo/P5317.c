#include <stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 100000
typedef struct ArcNode
{                            //表结点类型定义
    int adjvex;              //顶点位置编号
    struct ArcNode *nextarc; //下一个表结点指针
} ArcNode;
typedef struct VNode
{                      //头结点及其数组类型定义
    int data;          //顶点信息
    ArcNode *firstarc; //指向第一条弧
} VNode, AdjList[10000];
typedef struct
{                       //邻接表的类型定义
    AdjList vertices;   //头结点数组
    int vexnum, arcnum; //顶点数、弧数
} ALGraph;
void dfs();
void bfs(ALGraph G);
ArcNode *tail[10000];
int main()
{
    int vn, an;
    scanf("%d %d", &vn, &an);
    ALGraph G;
    G.vexnum = vn;
    G.arcnum = an;
    for (int i = 1; i <= vn; i++)
    {
        G.vertices[i].data = i;
        tail[i] = G.vertices[i].firstarc;
        //tail[i]->nextarc = NULL;
    }
    for (int i = 1; i <= an; i++)
    {
        int vi, vj;
        scanf("%d %d", &vi, &vj);
        ArcNode *p;
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = vj;
        p->nextarc = NULL;
        tail[vi]->nextarc = p;
        tail[vi] = p;
    }
    bfs(G);
}
VNode que[10000];
ArcNode *p;
void bfs(ALGraph G)
{
    int flag[10000], rear = 0, front = 0;
    for (int i = 1; i <= G.vexnum; i++)
        flag[i] = 0;
    for (int i = 1; i <= G.vexnum; i++)
    {
        if (!flag[i])
        {
            flag[i] = 1;
            que[rear++] = G.vertices[i];
            printf("%d ", que[rear - 1].data);
            while (front != rear)
            {
                p = que[front].firstarc;
                front++;
                while(p)
                {
                    if(!flag[p->adjvex])
                    {
                        flag[p->adjvex] = 1;
                        printf("%d", G.vertices[p->adjvex].data);
                        que[rear++] = G.vertices[p->adjvex];
                    }
                    p = p->nextarc;
                }
            }
        }
    }
}