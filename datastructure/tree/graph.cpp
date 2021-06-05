#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAX_VERTEX_NUM 20
typedef int status;
typedef int KeyType;
typedef enum {DG,DN,UDG,UDN} GraphKind;
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
    }elem[10];
    int length;

} GRAPHS;
status CreateGraph(ALGraph &G, VertexType V[], KeyType VR[][2]);
status DestroyGraph(ALGraph &G);
int LocateVex(ALGraph G, KeyType u);
status PutVex(ALGraph &G, KeyType u, VertexType value);
int FirstAdjVex(ALGraph G, KeyType u);
int NextAdjVex(ALGraph G, KeyType v, KeyType w);
status InsertVex(ALGraph &G, VertexType v);
status DeleteVex(ALGraph &G, KeyType v);
status InsertArc(ALGraph &G, KeyType v, KeyType w);
status DeleteArc(ALGraph &G, KeyType v, KeyType w);
status DFSTraverse(ALGraph &G, void (*visit)(VertexType));
status BFSTraverse(ALGraph &G, void (*visit)(VertexType));
status SaveGraph(ALGraph G, char FileName[]);
status LoadGraph(ALGraph &G, char FileName[]);
status AddGraph(GRAPHS &Graphs,char GraphName[]);
status DeleteGraph(GRAPHS &Graphs, char GraphName[]);
status LocateGraph(GRAPHS Graphs, char GraphName[]);
status TraverseGraphs(GRAPHS Graphs);
void visit(VertexType v);
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
        printf("          15. AddGraph          16. LoadGraph\n ");
        printf("          17. LocateGraph           18. TraverseGraphs\n");
        printf("    	          0. Exit\n");
        printf("-------------------------------------------\n");
        if (Graphs.length == 0) //最开始，提示使用功能15
        {
            printf("现在还没有二叉树哦，赶快使用功能15创建一个吧！\n");
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
                    printf("我们可以用功能15添加无向图，用功能16删除无向图，用功能17查找无向图，用功能18遍历无向图组\n");
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
                if (op >= 0 && op <= 14)
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
                if (op >= 15 && op <= 18)
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
                if (op == 15 || op == 0) //只能为15或0
                {
                    break;
                }
                else
                {
                    printf("现在还没有无向图，建议您使用功能15创建哦\n");
                }
            }
        }
    //下面用分支结构对输入进行处理
    switch(op)
    {
        case 1:
        {
            printf("正在实现CreateGraph功能\n");
            printf("请输入邻接表的点序列(以逗号隔开，以-1，nil结束):\n");
            VertexType v[20];
            KeyType VR[100][2];
            int j = 0;
            do{
                scanf("%d,%s", &v[j].key, v[j].others);
                j++;
            } while (v[j].key!=-1);
            j = 0;
            printf("请输入邻接表边序列(以空格隔开，以-1 -1结束):\n");
            do{
                scanf("%d%d", &VR[j][0], &VR[j][1]);
                j++;
            } while (VR[j][0] != -1);
            int i = CreateGraph(Graphs.elem[num - 1].G,v,VR);
            if(i==INFEASIBLE)
            {
                printf("该图已存在，无法创建!\n"); 
            }
            else if(i==ERROR)
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
            int i = DestroyGraph(Graphs.elem[num - 1].G);
            if(i==ERROR)
            {
                printf("原图不存在，销毁失败!\n");
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
            if(i==-1)
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
            if(i==ERROR)
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
            if(i==-1)
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
            if(i==-1)
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
            
        }

    }
}
}