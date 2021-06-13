#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
typedef int status;
typedef int KeyType;
typedef enum
{
    DG,
    DN,
    UDG,
    UDN
} GraphKind;
typedef struct
{
    KeyType key;
    char others[20];
} VertexType; //顶点类型定义
typedef struct ArcNode
{                            //表结点类型定义
    int adjvex;              //顶点位置编号
    struct ArcNode *nextarc; //下一个表结点指针
} ArcNode;
typedef struct VNode
{                      //头结点及其数组类型定义
    VertexType data;   //顶点信息
    ArcNode *firstarc; //指向第一条弧
} VNode, AdjList[MAX_VERTEX_NUM];
typedef struct
{                       //邻接表的类型定义
    AdjList vertices;   //头结点数组
    int vexnum, arcnum; //顶点数、弧数
    GraphKind kind;     //图的类型
} ALGraph;
typedef struct
{
    struct
    {
        ALGraph G;
        char Name[30];
    } elem[10];
    int length;

} GRAPHS;
status CreateGraph(ALGraph &G, VertexType V[], KeyType VR[][2]);
status DestoryGraph(ALGraph &G);
int LocateVex(ALGraph G, KeyType u);
status PutVex(ALGraph &G, KeyType u, VertexType value);
int FirstAdjVex(ALGraph G, KeyType u);
int NextAdjVex(ALGraph G, KeyType v, KeyType w);
status InsertVex(ALGraph &G, VertexType v);
status DeleteVex(ALGraph &G, KeyType v);
status InsertArc(ALGraph &G, KeyType v, KeyType w);
status DeleteArc(ALGraph &G, KeyType v, KeyType w);
void DFSTraverse(ALGraph G, void (*visit)(VertexType));
void BFSTraverse(ALGraph G, void (*visit)(VertexType));
status SaveGraph(ALGraph G, char FileName[]);
status LoadGraph(ALGraph &G, char FileName[]);
status AddGraph(GRAPHS &Graphs, char GraphName[]);
status DeleteGraph(GRAPHS &Graphs, char GraphName[]);
status LocateGraph(GRAPHS Graphs, char GraphName[]);
status TraverseGraphs(GRAPHS Graphs);
void PrintGraph(ALGraph G, void (*visit)(VertexType));
void visit(VertexType v);
void DFS(ALGraph G, int v, int flag[], void (*visit)(VertexType));
int main()
{
    int op = 1, num, flag = 0;
    //flag为对二叉树操作还是对二叉树组操作
    //num为操作的二叉树的序号
    GRAPHS Graphs;
    Graphs.length = 0;
    while (op)
    {
        system("cls");
        printf("\n\n");
        printf("Menu for Graph On adjacency list Structure\n");
        printf("------------------------------------------\n");
        printf("    	  1. CreateGraph       2. DestoryGraph\n");
        printf("    	  3. LocateVex        4. PutVex\n");
        printf("    	  5. FirstAdjVex       6. NextAdjVex \n");
        printf("    	  7. InsertVex          8. DeleteVex\n");
        printf("    	  9. InsertArc          10. DeleteArc\n");
        printf("    	  11. DFSTraverse       12. BFSTraverse\n");
        printf("          13. SaveGraph     14. LoadGraph\n");
        printf("          15. PrintGragh          16. AddGraph\n ");
        printf("          17. DeleteGragh           18. LocateGragh\n");
        printf("    	  19. TraverseGraghs        0. Exit\n");
        printf("-------------------------------------------\n");
        if (Graphs.length == 0) //最开始，提示使用功能16
        {
            printf("现在还没有无向图哦，赶快使用功能16创建一个吧！\n");
            printf("当然也可以选择功能0退出系统\n");
        }
        else
        {
            printf("按0可以退出程序,按1可以继续对某个无向图进行操作,按2可以无向图组进行操作哦\n");
            while (1) //下面的循环用来得到正确的flag值
            {
                scanf("%d", &flag);
                if (flag == 0)
                {
                    printf("\n欢迎下次使用本系统!\n");
                    getchar();
                    getchar();
                    return 0;
                }
                else if (flag == 1)
                {
                    printf("现在一共有%d个无向图哦，赶快从里面选一个来对他进行操作吧！\n", Graphs.length);
                    printf("注意这里是要输入无向图的序号哦\n");
                    while (1) //这个循环是为了得到正确的序号值
                    {
                        scanf("%d", &num);
                        if (num <= 0 || num > Graphs.length)
                        {
                            printf("选择的无向图序号不对哦\n");
                        }
                        else
                            break;
                    }
                    break;
                }
                else if (flag == 2)
                {
                    printf("我们可以用功能16添加无向图，用功能17删除无向图，用功能18查找无向图，用功能19遍历无向图组\n");
                    break;
                }
                else
                {
                    printf("输入的值不对哦，请从0或1或2中选择一个进行输入\n");
                }
            }
        }
        if (Graphs.length != 0) //接下来的这个分支用来输入操作
        {
            while (flag == 1) //对无向图的操作
            {
                printf("现在正在对无向图%s进行操作哦，这是我们的第%d个无向图\n", Graphs.elem[num - 1].Name, num);
                printf("请输入您需要的操作:");
                scanf("%d", &op);
                if (op >= 0 && op <= 15)
                {
                    break;
                }
                else
                {
                    printf("选择的操作不对哦，请重新输入\n");
                }
            }
            while (flag == 2) //无向图组的操作
            {
                printf("现在正在对无向图组进行操作，请输入您需要的功能");
                scanf("%d", &op);
                if (op >= 16 && op <= 19)
                {
                    break;
                }
                else
                {
                    printf("选择的操作不对哦，请重新输入\n");
                }
            }
        }
        else //这个分支是如果无向图组中没有无向图时的情况
        {
            while (1)
            {
                scanf("%d", &op);
                if (op == 16 || op == 0) //只能为15或0
                {
                    break;
                }
                else
                {
                    printf("现在还没有无向图，建议您使用功能16创建哦\n");
                }
            }
        }
        //下面用分支结构对输入进行处理
        switch (op)
        {
        case 1:
        {
            printf("正在实现CreateGraph功能\n");
            printf("请输入邻接表的点序列:\n");//提示输入
            VertexType v[20];
            KeyType VR[100][2];
            int j = 0;
            do
            {
                scanf("%d%s", &v[j].key, v[j].others);
            } while (v[j++].key != -1);
            j = 0;
            printf("请输入邻接表边序列(以空格隔开，以-1 -1结束):\n");
            do
            {
                scanf("%d%d", &VR[j][0], &VR[j][1]);
            } while (VR[j++][0] != -1);
            int i = CreateGraph(Graphs.elem[num - 1].G, v, VR);
            if (i == INFEASIBLE)
            {
                printf("该图已存在，无法创建!\n");
            }
            else if (i == ERROR)
            {
                printf("创建图失败!请检查输入的序列是否有误!\n");
            }
            else
            {
                printf("创建成功!\n");
            }
            break;
        }
        case 2:
        {
            printf("正在实现DestoryGraph功能!\n");
            int i = DestoryGraph(Graphs.elem[num - 1].G);
            if (i == ERROR)
            {
                printf("原图已为空图，清空失败!\n");
            }
            else
            {
                printf("销毁成功!\n");
            }
            break;
        }
        case 3:
        {
            printf("正在实现LocateVex功能\n");
            printf("请输入想要查找的节点的关键字:\n");
            KeyType e;
            scanf("%d", &e);
            int i = LocateVex(Graphs.elem[num - 1].G, e);
            if (i == -1)
            {
                printf("在该图中没有找到关键字为%d的结点\n", e);
            }
            else
            {
                printf("关键字为%d的结点对应的位序为%d\n", e, i);
            }
            break;
        }
        case 4:
        {
            printf("正在实现PutVex功能\n");
            KeyType e;
            VertexType value;
            printf("请输入想要赋值的结点的关键字:\n");
            scanf("%d", &e);
            printf("请输入想要赋值的节点的信息，以逗号隔开:\n");
            scanf("%d,%s", &value.key, value.others);
            int i = PutVex(Graphs.elem[num - 1].G, e, value);
            if (i == ERROR)
            {
                printf("赋值失败，请查看邻接表中是否有该关键字的结点或者赋值后关键字会有重复!\n");
            }
            else
            {
                printf("赋值成功!\n");
            }
            break;
        }
        case 5:
        {
            printf("正在实现FirstAdjVex功能\n");
            KeyType u;
            printf("请输入想要查找其第一条邻接边的节点的关键字\n");
            scanf("%d", &u);
            int i = FirstAdjVex(Graphs.elem[num - 1].G, u);
            if (i == -1)
            {
                printf("在邻接表中没有找到该节点!\n");
            }
            else
            {
                printf("该关键字对应的结点的第一条邻接边的位序为%d", i);
            }
            break;
        }
        case 6:
        {
            printf("正在实现NextAdjVex功能\n");
            KeyType u, w;
            printf("请输入想要查找下一个边的节点的关键字:\n");
            scanf("%d", &u);
            printf("请输入想要查找的相对位置对应的节点的关键字:\n");
            scanf("%d", &w);
            int i = NextAdjVex(Graphs.elem[num - 1].G, u, w);
            if (i == -1)
            {
                printf("查找失败!\n");
            }
            else
            {
                printf("对应的下一条边的结点为%d\n", i);
            }
            break;
        }
        case 7:
        {
            printf("正在实现InsertVex功能\n");
            printf("请输入想要插入的结点的值,以逗号隔开\n");
            VertexType v;
            scanf("%d,%s", &v.key, v.others);
            int i = InsertVex(Graphs.elem[num - 1].G, v);
            if (i == ERROR)
            {
                printf("插入操作失败，一旦插入会导致关键字重复!\n");
            }
            else
            {
                printf("插入成功!");
            }
            break;
        }
        case 8:
        {
            printf("正在实现DeleteVex功能\n");
            printf("请输入想要删除的结点的关键字\n");
            KeyType e;
            scanf("%d", &e);
            int i = DeleteVex(Graphs.elem[num - 1].G, e);
            if (i == ERROR)
            {
                printf("在该图中没有找到该节点!\n");
            }
            else
            {
                printf("删除成功!\n");
            }
            break;
        }
        case 9:
        {
            printf("正在实现InsertArc功能\n");
            printf("请输入您想要插入的弧对应的关键字,以空格隔开\n");
            KeyType v, w;
            scanf("%d%d", &v, &w);
            int i = InsertArc(Graphs.elem[num - 1].G, v, w);
            if (i == ERROR)
            {
                printf("插入弧操作失败!\n");
            }
            else
            {
                printf("该弧已成功插入!\n");
            }
            break;
        }
        case 10:
        {
            printf("正在实现DeleteArc功能\n");
            printf("请输入您想要删除的弧对应的关键字,以空格隔开\n");
            KeyType v, w;
            scanf("%d%d", &v, &w);
            int i = DeleteArc(Graphs.elem[num - 1].G, v, w);
            if (i == ERROR)
            {
                printf("删除弧操作失败!\n");
            }
            else
            {
                printf("删除弧操作成功!\n");
            }
            break;
        }
        case 11:
        {
            printf("正在实现DFSTraverse功能\n");
            if(Graphs.elem[num-1].G.vexnum==0)
            {
                printf("该树为空!\n");
            }
            else{
            printf("该图的深度优先遍历序列为:\n");
            DFSTraverse(Graphs.elem[num - 1].G, visit);}
            break;
        }
        case 12:
        {
            printf("正在实现BFSTraverse功能\n");
            if(Graphs.elem[num-1].G.vexnum==0)
            {
                printf("该树为空!\n");
            }
            else{
            printf("该图的广度优先遍历序列为:\n");
            BFSTraverse(Graphs.elem[num - 1].G, visit);}
            break;
        }
        case 13:
        {
            printf("正在实现SaveGraph功能\n");
            printf("请输入文件路径:");
            char FileName[30];
            scanf("%s", FileName);
            int i = SaveGraph(Graphs.elem[num - 1].G, FileName);
            if (i == -1)
            {
                printf("文件打开失败!\n");
            }
            else
            {
                printf("保存成功!\n");
            }
            break;
        }
        case 14:
        {
            printf("正在实现LoadGraph功能\n");
            printf("请输入文件路径:");
            char FileName[30];
            scanf("%s", FileName);
            int i = LoadGraph(Graphs.elem[num - 1].G, FileName);
            if (i == -1)
            {
                printf("文件打开失败!\n");
            }
            else
            {
                printf("读入成功!");
            }
            break;
        }
        case 15:
        {
            printf("正在实现PrintGraph功能\n");
            if(Graphs.elem[num-1].G.vexnum==0)
            {
                printf("该图为空!");
            }
            else{
            printf("无向图%s为:\n", Graphs.elem[num - 1].Name);
            PrintGraph(Graphs.elem[num - 1].G, visit);}
            break;
        }
        case 16:
        {
            printf("正在实现AddGraph功能\n");
            printf("请输入想要添加的无向图的名字:\n");
            char Name[100];
            scanf("%s", Name);
            int i = AddGraph(Graphs, Name);
            if (i == ERROR)
            {
                printf("无向图的名字重复!\n");
            }
            else if (i == INFEASIBLE)
            {
                printf("无向图组溢出!\n");
            }
            else
            {
                printf("已成功创建\n");
            }
            break;
        }
        case 17:
        {
            printf("正在实现DeleteGraph功能\n");
            printf("请输入想要删除的无向图的名字");
            char Name[100];
            scanf("%s", Name);
            int i = DeleteGraph(Graphs, Name);
            if (i == INFEASIBLE)
            {
                printf("现在还没有无向图哦，建议使用功能16去创建\n");
            }
            else if (i == ERROR)
            {
                printf("在无向图组中没有找到这个无向图!\n");
            }
            else
            {
                printf("无向图%s删除成功!\n", Name);
            }
            break;
        }
        case 18:
        {
            printf("正在实现LocateGraph功能\n");
            printf("请输入您想要查找的无向图的名字:");
            char name[100];
            scanf("%s", name);
            int i = LocateGraph(Graphs, name);
            if (i == ERROR)
            {
                printf("在无向图组中没有查找到该无向图!");
            }
            else
            {
                printf("该无向图为%d个\n", i);
            }
            break;
        }
        case 19:
        {
            printf("正在实现TraverseGraphs功能\n");
            if (Graphs.length == 0)
            {
                printf("现在二叉树组为空!\n");
            }
            else
            {
                TraverseGraphs(Graphs);
            }
            break;
        }
        case 0:
        {
            break;
        }
        }//end of switch
        getchar();
        getchar();
    }//end of while
    printf("欢迎下次使用本系统!\n");
    getchar();
    getchar();
}
status CreateGraph(ALGraph &G, VertexType V[], KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i = 0;
    while (V[i].key != -1)
    {
        int j = i + 1;
        while (V[j].key != -1)
        {
            if (V[i].key == V[j].key)
            {
                return ERROR;
            }
            j++;
        }
        i++;
    }//查看是否有重复的关键字
    if (i > 20 || i == 0)
    {
        return ERROR;//查看节点数量是否不合法
    }
    i = 0;
    while (V[i].key != -1)
    {
        G.vertices[i].data = V[i];
        G.vertices[i].firstarc = NULL;
        i++;
    }//将邻接表的主体部分进行输入
    G.vexnum = i;//节点数确定
    int flag = 0;
    for (int i = 0; VR[i][0] != -1; i++)//下面的二重循环用于把关键字序列变成位序
    {
        for (int j = 0; j < 2; j++)
        {
            int k = 0;
            flag = 0;
            while (V[k].key != -1)
            {
                if (V[k].key == VR[i][j])
                {
                    VR[i][j] = k;
                    flag = 1;
                    break;
                }
                k++;
            }
            if (!flag)
            {
                return ERROR;
            }
        }
    }
    for (int i = 0; VR[i][0] != -1; i++)//进行链表的创建
    {
        ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = VR[i][1];
        p->nextarc = NULL;
        if (G.vertices[VR[i][0]].firstarc == NULL)
        {
            G.vertices[VR[i][0]].firstarc = p;
        }
        else
        {
            p->nextarc = G.vertices[VR[i][0]].firstarc;
            G.vertices[VR[i][0]].firstarc = p;
        }
        ArcNode *q = (ArcNode *)malloc(sizeof(ArcNode));
        q->adjvex = VR[i][0];
        q->nextarc = NULL;
        if (G.vertices[VR[i][1]].firstarc == NULL)
        {
            G.vertices[VR[i][1]].firstarc = q;
        }
        else
        {
            q->nextarc = G.vertices[VR[i][1]].firstarc;
            G.vertices[VR[i][1]].firstarc = q;
        }
        G.arcnum++;
    }
    return OK;
    /********** End **********/
}
status DestoryGraph(ALGraph &G)
/*销毁无向图G,删除G的全部顶点和边*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (G.vexnum == 0)
    {
        return ERROR;
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        ArcNode *p = NULL;
        while (G.vertices[i].firstarc != NULL)
        {
            p = G.vertices[i].firstarc;
            G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
            free(p);
        }
    }
    G.vexnum = 0;
    G.arcnum = 0;
    return OK;
    /********** End **********/
}
int LocateVex(ALGraph G, KeyType u)
//根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == u)
        {
            return i;
        }
    }
    return -1;

    /********** End **********/
}
status PutVex(ALGraph &G, KeyType u, VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i1 = -1;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (i1 == -1 && G.vertices[i].data.key == u)
        {
            i1 = i;
        }
        if (G.vertices[i].data.key == value.key && value.key != u)
        {
            return ERROR;
        }
    }
    if (i1 != -1)
    {
        G.vertices[i1].data = value;
        return OK;
    }
    return ERROR;

    /********** End **********/
}
int FirstAdjVex(ALGraph G, KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == u)
        {
            if (G.vertices[i].firstarc != NULL)
            {
                return G.vertices[i].firstarc->adjvex;
            }
            else
                return -1;
        }
    }
    return -1;
    /********** End **********/
}
int NextAdjVex(ALGraph G, KeyType v, KeyType w)
//根据u在图G中查找顶点，查找成功返回顶点v的邻接顶点相对于w的下一邻接顶点的位序，查找失败返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i = 0;
    int vv = -1, ww = -1;
    for (; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == v)
        {
            vv = i;
        }
        if (G.vertices[i].data.key == w)
        {
            ww = i;
        }
    }
    if (vv == -1 || ww == -1)
    {
        return -1;
    }
    ArcNode *p = G.vertices[vv].firstarc;
    while (p)
    {
        if (p->adjvex == ww)
            break;
        p = p->nextarc;
    }
    if (p == NULL || p->nextarc == NULL)
        return -1;
    return p->nextarc->adjvex;

    /********** End **********/
}
status InsertVex(ALGraph &G, VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (G.vexnum == 20)
    {
        return ERROR;
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == v.key)
        {
            return ERROR;
        }
    }
    G.vexnum++;
    G.vertices[G.vexnum - 1].data = v;
    G.vertices[G.vexnum - 1].firstarc = NULL;
    return OK;
    /********** End **********/
}
status DeleteVex(ALGraph &G, KeyType v)
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i = 0;
    for (; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == v)
        {
            break;
        }
    }//判断是否查找到
    if (i == G.vexnum)
    {
        return ERROR;
    }
    if (G.vexnum == 1)
    {
        return ERROR;//判断节点数是否合法
    }
    ArcNode *p = G.vertices[i].firstarc;
    ArcNode *q = p;
    int num = 0;
    while (p != NULL)
    {
        q = q->nextarc;
        free(p);
        p = q;
        num++;
    }
    G.vertices[i].firstarc = NULL;
    for (int j = i; j < G.vexnum; j++)
    {
        G.vertices[j] = G.vertices[j + 1];
    }
    G.vexnum--;
    for (int j = 0; j < G.vexnum; j++)
    {
        if (G.vertices[j].firstarc == NULL)
            continue;
        ArcNode *p = G.vertices[j].firstarc;
        ArcNode *q = p;
        p = p->nextarc;
        while (p)
        {
            if (p->adjvex == i)
            {
                q->nextarc = p->nextarc;
                free(p);
                p = q->nextarc;
                continue;
            }
            if (p->adjvex >= i)//更改位序
            {
                p->adjvex--;
            }
            q = q->nextarc;
            p = p->nextarc;
        }
        if (G.vertices[j].firstarc->adjvex > i)
        {
            G.vertices[j].firstarc->adjvex--;
        }
        else if (G.vertices[j].firstarc->adjvex == i)
        {
            p = G.vertices[j].firstarc;
            G.vertices[j].firstarc = p->nextarc;
            free(p);
        }
    }
    G.arcnum -= num;
    return OK;
    /********** End **********/
}
status InsertArc(ALGraph &G, KeyType v, KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int vv = -1, ww = -1;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == v)
        {
            vv = i;
        }
        if (G.vertices[i].data.key == w)
        {
            ww = i;
        }
    }
    if (vv == -1 || ww == -1)
    {
        return ERROR;
    }
    ArcNode *p = G.vertices[vv].firstarc;
    while (p)
    {
        if (p->adjvex == ww)
        {
            return ERROR;
        }
        p = p->nextarc;
    }
    ArcNode *q;
    q = (ArcNode *)malloc(sizeof(ArcNode));
    q->adjvex = ww;
    q->nextarc = G.vertices[vv].firstarc;
    G.vertices[vv].firstarc = q;
    ArcNode *r;
    r = (ArcNode *)malloc(sizeof(ArcNode));
    r->adjvex = vv;
    r->nextarc = G.vertices[ww].firstarc;
    G.vertices[ww].firstarc = r;
    G.arcnum++;
    return OK;

    /********** End **********/
}
status DeleteArc(ALGraph &G, KeyType v, KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int vv = -1, ww = -1;
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vertices[i].data.key == v)
        {
            vv = i;
        }
        if (G.vertices[i].data.key == w)
        {
            ww = i;
        }
    }
    if (vv == -1 || ww == -1)
    {
        return ERROR;
    }
    ArcNode *q = G.vertices[vv].firstarc, *p = q;
    if (q)
    {
        if (q->adjvex == ww)
        {
            G.vertices[vv].firstarc = q->nextarc;
            free(q);
        }
        else
        {
            q = q->nextarc;
            while (q)
            {
                if (q->adjvex == ww)
                {
                    p->nextarc = q->nextarc;
                    free(q);
                    break;
                }
                p = p->nextarc;
                q = q->nextarc;
            }
        }
    }
    if (q == NULL)
    {
        return ERROR;
    }
    q = G.vertices[ww].firstarc;
    if (q->adjvex == vv)
    {
        G.vertices[ww].firstarc = q->nextarc;
        free(q);
        q = NULL;
    }
    else
    {
        p = q;
        q = q->nextarc;
        while (q)
        {
            if (q->adjvex == vv)
            {
                break;
            }
            p = p->nextarc;
            q = q->nextarc;
        }
        if (q)
        {
            p->nextarc = q->nextarc;
            free(q);
            q = NULL;
        }
        else
            return ERROR;
    }
    G.arcnum--;
    return OK;
    /********** End **********/
}
void DFSTraverse(ALGraph G, void (*visit)(VertexType))
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i, flag[20];//flag[]用来表示当前节点是否被访问过
    for (i = 0; i < G.vexnum; i++)
    {
        flag[i] = 0;//初始化
    }
    for (i = 0; i < G.vexnum; i++)
    {
        if (!flag[i])//如果没有被访问过，则进行DFS操作
        {
            DFS(G, i, flag, visit);
        }
    }
    /********** End **********/
}
void DFS(ALGraph G, int v, int flag[], void (*visit)(VertexType))
{
    ArcNode *p;
    int w;
    flag[v] = TRUE;
    visit(G.vertices[v].data);//访问当前节点
    for (p = G.vertices[v].firstarc; p; p = p->nextarc)
    {
        w = p->adjvex;
        if (!flag[w])
            DFS(G, w, flag, visit);
    }
}
void BFSTraverse(ALGraph G, void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int flag[20], front = 0, rear = 0;
    ArcNode *p;
    for (int i = 0; i < G.vexnum; i++)
    {
        flag[i] = 0;//对flag数组进行初始化
    }
    VNode que[100];//定义一个队列，其实这里用循环队列要更好一些，但是这里没有
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!flag[i])//如果没有被访问过
        {
            flag[i] = 1;//访问
            que[rear] = G.vertices[i];//入队
            rear++;
            visit(G.vertices[i].data);
            while (front != rear)//当队列不为空
            {
                p = que[front].firstarc;//出队
                front++;
                while (p)//遍历后面的所有邻接结点
                {
                    if (!flag[p->adjvex])
                    {
                        flag[p->adjvex] = 1;
                        visit(G.vertices[p->adjvex].data);
                        que[rear] = G.vertices[p->adjvex];
                        rear++;
                    }
                    p = p->nextarc;
                }
            }
        }
    }
    /********** End **********/
}
status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    FILE *p;
    p = fopen(FileName, "w");
    if (p == NULL)
    {
        return -1;
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        fprintf(p, "%d %s ", G.vertices[i].data.key, G.vertices[i].data.others);
        ArcNode *q;
        q = G.vertices[i].firstarc;
        while (q)
        {
            fprintf(p, "%d ", q->adjvex);
            q = q->nextarc;
        }
        fprintf(p, "-1 ");
    }
    fclose(p);
    return OK;
    /********** End 1 **********/
}
status LoadGraph(ALGraph &G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    FILE *p;
    p = fopen(FileName, "r");
    if (p == NULL)
    {
        return -1;
    }
    int i = 0, num = 0;
    G.vexnum = 0;
    G.arcnum = 0;
    for (int j = 0; j < 20; j++)
    {
        G.vertices[j].firstarc = NULL;
    }
    while (fscanf(p, "%d %s ", &G.vertices[i].data.key, G.vertices[i].data.others) != EOF)
    {
        G.vexnum++;
        int adj;
        fscanf(p, "%d", &adj);
        ArcNode *tail = G.vertices[i].firstarc;
        while (adj != -1)
        {
            ArcNode *q = (ArcNode *)malloc(sizeof(ArcNode));
            q->adjvex = adj;
            q->nextarc = NULL;
            if (G.vertices[i].firstarc == NULL)
            {
                G.vertices[i].firstarc = q;
                tail = q;
            }
            else
            {
                tail->nextarc = q;
                tail = q;
            }
            fscanf(p, "%d", &adj);
            num++;
        }
        i++;
    }
    fclose(p);
    num /= 2;
    G.arcnum += num;
    return OK;
    /********** End 2 **********/
}
status AddGraph(GRAPHS &Graphs, char GraphName[])
{
    if (Graphs.length > 10)
    {
        return INFEASIBLE;
    }
    for (int i = 0; i < Graphs.length; i++)
    {
        if (strcmp(Graphs.elem[i].Name, GraphName) == 0)
        {
            return ERROR;
        }
    }
    Graphs.length++;
    strcpy(Graphs.elem[Graphs.length - 1].Name, GraphName);
    Graphs.elem[Graphs.length - 1].G.arcnum = 0;
    Graphs.elem[Graphs.length - 1].G.vexnum = 0;
    return OK;
}
status DeleteGraph(GRAPHS &Graphs, char GraghName[])
{
    if (Graphs.length == 0)
    {
        return INFEASIBLE;
    }
    int i = 0, flag = 0;
    for (; i < Graphs.length; i++)
    {
        if (strcmp(Graphs.elem[i].Name, GraghName) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        return ERROR;
    }
    DestoryGraph(Graphs.elem[i].G);
    for (int j = i; j < Graphs.length; j++)
    {
        Graphs.elem[j] = Graphs.elem[j + 1];
    }
    Graphs.length--;
    return OK;
}
status TraverseGraphs(GRAPHS Graphs)
{
    for (int i = 0; i < Graphs.length; i++)
    {
        printf("%s", Graphs.elem[i].Name);
        printf("\n");
        PrintGraph(Graphs.elem[i].G, visit);
    }
    return OK;
}
int LocateGraph(GRAPHS Graphs, char Name[])
{
    int i = 0, flag = 0;
    for (; i < Graphs.length; i++)
    {
        if (strcmp(Graphs.elem[i].Name, Name) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        return ERROR;
    }
    else
    {
        return i + 1;
    }
}
void PrintGraph(ALGraph G,void (*visit)(VertexType))
{
    for (int i = 0; i < G.vexnum; i++)
    {
        ArcNode *p = G.vertices[i].firstarc;
        printf("%d %s", G.vertices[i].data.key, G.vertices[i].data.others);
        while (p)
        {
            printf(" %d", p->adjvex);
            p = p->nextarc;
        }
        printf("\n");
    }
}
void visit(VertexType v)
{
    printf("%d %s ", v.key, v.others);
}