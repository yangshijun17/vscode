#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int status;
typedef int KeyType;
typedef struct
{
    KeyType key;
    char others[20];
} TElemType; //二叉树结点类型定义
typedef struct BiTNode
{ //二叉链表结点的定义
    TElemType data;
    struct BiTNode *lchild, *rchild;
    int height;
} BiTNode, *BiTree;
typedef struct
{ //二叉树的集合类型定义
    struct
    {
        char name[30]; //这个二叉树的名字
        BiTree Bitree; //二叉树
    } elem[10];
    int length; //二叉树组中一共有多少二叉树
} TREES;
void setPrintBuffer(BiTree t);
status CreateBitree(BiTree &T, TElemType definition[]);
status DestoryBitree(BiTree &T);
status ClearBitree(BiTree &T);
status BitreeEmpty(BiTree T);
int BitreeDepth(BiTree T);
BiTree LocateNode(BiTree T, KeyType e);
BiTree Locatenode2(BiTree T, KeyType e, TElemType c);
status Assign(BiTree &T, KeyType e, TElemType data);
BiTree GetSibling(BiTree T, KeyType e);
status InsertNode(BiTree &T, KeyType e, int LR, TElemType c);
status DeleteNode(BiTree &T, KeyType e);
status PreOrderTree(BiTree T, void (*visit)(BiTree));
status InOrderTree(BiTree T, void (*visit)(BiTree));
status PostOrderTree(BiTree T, void (*visit)(BiTree));
status SaveBiTree(BiTree T, char Filename[]);
status LoadBiTree(BiTree &T, char Filename[]);
status AddTree(TREES &trees, char treename[]/*,TElemType definition[]*/);
status DeleteTree(TREES &trees, char treename[]);
status TraverseTrees(TREES trees);
int Locatetree(TREES trees, char treename[]);
void visit(BiTree T);
void bt_print(BiTree bt);
char **printBuffer = NULL;
int flag1 = 0,i1 = 0,flag15=0,i15=0,j15=0,flag16=0,i16=0,j16=0;
int dep = 0;
// 该树的深度，如果只有根节点则深度为1
int depthMax = 0;
// 打印缓冲区的宽度，当前应打印的列数，上次打印位置的列数
int width = 0, column = 0, lastColumn = 0;

int main()
{
    int op = 1, num, flag = 0;
    //flag为对二叉树操作还是对二叉树组操作
    //num为操作的二叉树的序号
    TREES Trees;
    Trees.length = 0;
    while (op)
    {
        system("cls");
        printf("\n\n");
        printf("Menu for Tree On Linked Storage Structure\n");
        printf("------------------------------------------\n");
        printf("    	  1. CreateBitree       2. DestoryBitree\n");
        printf("    	  3. ClearBitree        4. BitreeEmpty\n");
        printf("    	  5. BitreeDepth       6. LocateNode \n");
        printf("    	  7. Assign          8. GetSibling\n");
        printf("    	  9. InsertNode     10. DeleteNode\n");
        printf("    	  11. PreOrderTree       12. InOrderTree\n");
        printf("          13. PostOrderTree     14. LevelOrderTree\n");
        printf("          15. SaveData          16. LoadData\n ");
        printf("          17. AddTree           18. DeleteTree\n");
        printf("          19. TraverseTrees     20. LocateTree\n ");
        printf("    	          0. Exit\n");
        printf("-------------------------------------------\n");
        if (Trees.length == 0) //最开始，提示使用功能17
        {
            printf("现在还没有二叉树哦，赶快使用功能17创建一个吧！\n");
            printf("当然也可以选择功能0退出系统\n");
        }
        else
        {
            printf("按0可以退出程序,按1可以继续对某个二叉树进行操作,按2可以二叉树组进行操作哦\n");
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
                    printf("现在一共有%d个二叉树哦，赶快从里面选一个来对他进行操作吧！\n", Trees.length);
                    printf("注意这里是要输入二叉树的序号哦\n");
                    while (1) //这个循环是为了得到正确的序号值
                    {
                        scanf("%d", &num);
                        if (num <= 0 || num > Trees.length)
                        {
                            printf("选择的二叉树序号不对哦\n");
                        }
                        else
                            break;
                    }
                    break;
                }
                else if (flag == 2)
                {
                    printf("我们可以用功能17添加二叉树，用功能18删除二叉树，用功能19遍历二叉树组，用功能20查找某个二叉树\n");
                    break;
                }
                else
                {
                    printf("输入的值不对哦，请从0或1或2中选择一个进行输入\n");
                }
            }
        }
        if (Trees.length != 0) //接下来的这个分支用来输入操作
        {
            while (flag == 1) //对二叉树的操作
            {
                printf("现在正在对二叉树%s进行操作哦，这是我们的第%d个二叉树\n", Trees.elem[num - 1].name, num);
                printf("请输入您需要的操作:");
                scanf("%d", &op);
                if (op >= 0 && op <= 16)
                {
                    break;
                }
                else
                {
                    printf("选择的操作不对哦，请重新输入\n");
                }
            }
            while (flag == 2) //对二叉树组的操作
            {
                printf("现在正在对二叉树组进行操作，请输入您需要的功能");
                scanf("%d", &op);
                if (op >= 17 && op <= 20)
                {
                    break;
                }
                else
                {
                    printf("选择的操作不对哦，请重新输入\n");
                }
            }
        }
        else //这个分支是如果二叉树组中没有二叉树时的情况
        {
            while (1)
            {
                scanf("%d", &op);
                if (op == 17 || op == 0) //只能为17或0
                {
                    break;
                }
                else
                {
                    printf("现在还没有二叉树，建议您使用功能17创建哦\n");
                }
            }
        }
        switch (op)
        {
        case 1:
        {
            printf("正在实现CreateBitree功能\n");
            printf("请输入带空的二叉树的先序序列:");
            printf("注意关键字和内容之间以逗号隔开，最终以-1结束!\n");
            TElemType definition[100];
            int j = 0;
            do
            {
                scanf("%d,%s", &definition[j].key, definition[j].others);
            } while (definition[j++].key != -1);
            if(Trees.elem[num - 1].Bitree!=NULL)
            {
                printf("二叉树已存在!\n");
            }
            else{
            int i = CreateBitree(Trees.elem[num - 1].Bitree, definition);
            if (i == OK)
                printf("二叉树已经成功创建!\n");
            else if (i == ERROR)
                printf("输入关键字不唯一!请检查输入的先序序列!\n");}
            i1 = 0;
            flag1 = 0;
            break;
        }
        case 2:
        {
            printf("正在实现DestoryTree功能\n");
            int i = DestoryBitree(Trees.elem[num - 1].Bitree);
            printf("第%d个二叉树%s销毁成功!\n", num, Trees.elem[num - 1].name);
            break;
        }
        case 3:
        {
            printf("正在实现ClearTree功能\n");
            int i = ClearBitree(Trees.elem[num - 1].Bitree);
            printf("第%d个二叉树%s已成功清除!\n", num, Trees.elem[num - 1].name);
            break;
        }
        case 4:
        {
            printf("正在实现BitreeEmpty功能\n");
            int i = BitreeEmpty(Trees.elem[num - 1].Bitree);
            if (i == ERROR)
            {
                printf("二叉树为空!\n");
            }
            else
            {
                printf("二叉树不为空!\n");
            }
            break;
        }
        case 5:
        {
            printf("正在实现BitreeDepth功能\n");
            int i = BitreeDepth(Trees.elem[num - 1].Bitree);
            printf("二叉树%s的深度为%d\n", Trees.elem[num - 1].name, i);
            break;
        }
        case 6:
        {
            printf("正在实现LocateNode功能\n");
            printf("请输入想要查找的结点的关键字:\n");
            KeyType e;
            scanf("%d", &e);
            BiTree T;
            T = LocateNode(Trees.elem[num - 1].Bitree, e);
            if (T == NULL)
            {
                printf("在二叉树%s中没有找到有关键字%d的结点\n", Trees.elem[num - 1].name, e);
            }
            else
            {
                printf("关键字为%d的结点对应的数据为%s\n", e, T->data.others);
            }
            break;
        }
        case 7:
        {
            printf("正在实现Assign功能\n");
            printf("请输入您希望赋值的结点的关键字以及希望赋的值:\n");
            printf("希望赋的值关键字和数据之间以逗号隔开");
            KeyType e;
            TElemType value;
            int t=scanf("%d%d,%s", &e, &value.key, value.others);
            if(t==0)
            {
                printf("输入格式错误!请重新输入!");
                t=scanf("%d%d,%s", &e, &value.key, value.others);
            }
            BiTree T = LocateNode(Trees.elem[num - 1].Bitree, value.key);
            if(T!=NULL)
            {
                if(value.key!=e)
                {
                    printf("赋值操作失败！一旦成功关键字会有重复!\n");
                }
                else
                {
                                int i = Assign(Trees.elem[num - 1].Bitree, e, value);
            if (i == ERROR)
            {
                printf("赋值操作失败!请检查该二叉树中是否存在关键字为%d的结点\n", e);
            }
            else if(i==OK)
                printf("已成功赋值!\n");
                }
            }
            else
            {
            int i = Assign(Trees.elem[num - 1].Bitree, e, value);
            if (i == ERROR)
            {
                printf("赋值操作失败!请检查该二叉树中是否存在关键字为%d的结点\n", e);
            }
            else if(i==OK)
                printf("已成功赋值!\n");
            
            }
            break;
        }
        case 8:
        {
            printf("正在实现GetSiblings功能\n");
            printf("请输入您希望查找它兄弟结点的结点的关键字:\n");
            KeyType e;
            scanf("%d", &e);
            BiTree T = GetSibling(Trees.elem[num - 1].Bitree, e);
            if(T==NULL)
            {
                printf("没有找到兄弟节点!\n");
            }
            else
            {printf("关键字为%d的结点的兄弟结点对应数据为:\n",e);
            printf("关键字:%d  数据:%s", T->data.key, T->data.others);}
            break;
        }
        case 9:
        {
            printf("正在实现InsertNode功能\n");
            printf("请输入您想要插入的结点的关键字，插入的位置，插入结点的数据\n");
            printf("其中对于插入的位置，输入-1作为根节点插入，输入0作为对应关键字结点的左孩子插入，输入为1作为对应关键字结点的右孩子插入\n");
            printf("其中对于插入结点数据的输入，请以逗号隔开\n");
            KeyType e;
            int LR=0;
            TElemType c;
            scanf("%d%d%d,%c", &e, &LR, &c.key, c.others);
            while(1){
            if(!(LR==1||LR==-1||LR==0))
            {
                printf("请重新输入LR的值!");
                scanf("%d", &LR);
            }
            else
                break;
            }
            int i = InsertNode(Trees.elem[num - 1].Bitree, e, LR, c);
            if (i == 0)
            {
                printf("插入操作失败！请检查关键字是否重复或者该二叉树中没有该关键字!");
            }
            else
            {
                printf("已成功插入!\n");
            }
            break;
        }
        case 10:
        {
            printf("正在实现DeleteNode功能\n");
            printf("请输入您想要删除的结点的关键字:\n");
            KeyType e;
            scanf("%d", &e);
            int i = DeleteNode(Trees.elem[num - 1].Bitree, e);
            if (i == 0)
                printf("删除操作失败!请检查二叉树中是否有该关键字对应的结点!\n");
            else
                printf("已成功删除!\n");
            break;
        }
        case 11:
        {
            printf("正在实现PreOrderTree功能\n");
            printf("树%s的先序遍历序列为:\n", Trees.elem[num - 1].name);
            PreOrderTree(Trees.elem[num - 1].Bitree, visit);
            break;
        }
        case 12:
        {
            printf("正在实现InOrderTree功能\n");
            printf("树%s的中序遍历序列为:\n", Trees.elem[num - 1].name);
            InOrderTree(Trees.elem[num - 1].Bitree, visit);
            break;
        }
        case 13:
        {
            printf("正在实现PostOrderTree功能\n");
            printf("树%s的后序遍历序列为:\n", Trees.elem[num - 1].name);
            PostOrderTree(Trees.elem[num - 1].Bitree, visit);
            break;
        }
        case 14:
        {
            printf("正在实现LevelOrderTree功能\n");
            printf("树%s的按层遍历序列为:\n", Trees.elem[num - 1].name);
            bt_print(Trees.elem[num - 1].Bitree);
            break;
        }
        case 15:
        {
            printf("正在实现SaveData功能\n");
            printf("请输入文件路径:");
            char Filename[100];
            scanf("%s", Filename);
            int i = SaveBiTree(Trees.elem[num - 1].Bitree, Filename);
            if(i==ERROR)
            {
                printf("文件打开失败!\n");
            }
            else if(i==INFEASIBLE)
            {
                printf("二叉树为空!\n");
            }
            else
            {
                printf("二叉树中数据已经成功按先序序列保存在了文件中!\n");
            }
            flag15 = 0;
            i15 = 0;
            j15 = 0;
            break;
        }
        case 16:
        {
            printf("正在实现LoadBiTree功能\n");
            printf("请输入文件路径:");
            char Filename[100];
            scanf("%s", Filename);
            int i = LoadBiTree(Trees.elem[num - 1].Bitree, Filename);

            if(i==ERROR)
            {
                printf("文件打开失败!\n");
            }
            else if(i==INFEASIBLE)
            {
                printf("二叉树非空!无法写入!\n");
            }
            else
            {
                printf("文件中的数据已经成功写入到该二叉树中!\n");
            }
            flag16 = 0;
            i16 = 0;
            j16 = 0;
            break;
        }
        case 17:
        {
            printf("正在实现AddTree功能\n");
            printf("请输入想要添加的二叉树的名字:\n");
            char Name[100];
            scanf("%s", Name);
            int i = AddTree(Trees, Name);
            if(i==ERROR)
            {
                printf("二叉树的名字重复!\n");
            }
            else if(i==INFEASIBLE)
            {
                printf("输入的序列中的二叉树关键字有重复!\n");
            }
            else
            {
                printf("已成功创建\n");
            }
            break;
        }
        case 18:
        {
            printf("正在实现DeleteTree功能\n");
               printf("请输入想要删除的二叉树的名字");
                char Name[100];
                scanf("%s", Name);
                int i = DeleteTree(Trees, Name);
            if(i==INFEASIBLE)
            {
                printf("现在还没有二叉树哦，建议使用功能17去创建\n");
            }
            else if(i==ERROR)
            {
                printf("在二叉树组中没有找到这个二叉树!\n");
            }
            else
            {
                printf("二叉树%s删除成功!\n", Name);
            }
            break;
        }
        case 19:
        {
            printf("正在实现TraverseTrees功能\n");
            if(Trees.length==0)
            {
                printf("现在二叉树组为空!\n");
            }
            else
            {
                TraverseTrees(Trees);
            }
            break;
        }
        case 20:
        {
            printf("正在实现Locatetree功能\n");
            printf("请输入您想要查找的二叉树的名字:");
            char name[100];
            scanf("%s", name);
            int i = Locatetree(Trees, name);
            if(i==ERROR)
            {
                printf("在二叉树组中没有查找到该树!");
            }
            else
            {
                printf("该树的位置序号为%d", i);
            }
            break;
        }
        case 0:
        {
            break;
        }
        } //end of switch
        getchar();
        getchar();
    }//end of while
    printf("欢迎下次使用本系统!\n");
    getchar();
    getchar();
    return 1;
}
status CreateBitree(BiTree &T, TElemType definition[])
{
    if(flag1==0){
    for (int j = 0; definition[j].key != -1; j++)
    {
        for (int t = j + 1; definition[t].key != -1; t++)
        {
            if (definition[j].key == definition[t].key && definition[j].key != 0)
            {
        
                return ERROR;
            }
        }
    }
    flag1 = 1;
    }
    //以上为查重的代码
    if (definition[i1].key == -1)
        return OK; //读到最后，返回OK
    else if (definition[i1].key == 0)
    {
        T = NULL;
        i1++;
        return OK; //如果为0的话，当前结点为空，i自增，不用继续递归调用
    }
    else if (definition[i1].key != -1)
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data = definition[i1]; //已经求了T的数据域
        i1++;
        CreateBitree(T->lchild, definition); //根据前序遍历的特征，递归创建T的左孩子
        CreateBitree(T->rchild, definition); //递归创建T的右孩子
        return OK;
    }
    return OK;
}
status DestoryBitree(BiTree &T)
{
    if (T != NULL)
    {
        DestoryBitree(T->lchild);
        DestoryBitree(T->rchild);
        free(T);
        T = NULL;
        return OK;
    }
    return OK;
}
status ClearBitree(BiTree &T)
{
    if (T != NULL)
    {
        ClearBitree(T->lchild);
        ClearBitree(T->rchild);
        free(T);
        T = NULL;
        return OK;
    }
    return OK;
}
status BitreeEmpty(BiTree T)
{
    if (T == NULL)
        return ERROR;
    else
        return OK;
}
int BitreeDepth(BiTree T)
{
    if (T == NULL)
    {
        return 0; //空树深度为0
    }
    //递归计算左子树和右子树的深度，哪个大就返回哪个加一
    return BitreeDepth(T->lchild) > BitreeDepth(T->rchild) ? BitreeDepth(T->lchild) + 1 : BitreeDepth(T->rchild) + 1;
}
BiTree LocateNode(BiTree T, KeyType e)
{
    if (T == NULL)
    {
        return NULL;
    }
    if (T->data.key == e)
    {
        return T;
    }
    BiTree left = LocateNode(T->lchild, e);  //递归查找左子树
    BiTree right = LocateNode(T->rchild, e); //递归查找右子树
    if (left == NULL && right == NULL)
        return NULL;
    else if (left == NULL)
        return right;
    else
        return left;
}
status Assign(BiTree &T, KeyType e, TElemType value)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL)
    {
        return ERROR;
    }
    if (T->data.key == e)
    {
        T->data = value;
        return OK;
    }
    int left = Assign(T->lchild, e, value);
    int right = Assign(T->rchild, e, value);
    if (left||right)
    {
        return OK; 
    }
    else
        return ERROR;
    /********** End **********/
}
BiTNode* GetSibling(BiTree T,KeyType e)
//实现获得兄弟结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T==NULL)
    {
        return NULL;
    }
    if(T->lchild)
    {
        if(T->lchild->data.key==e)
        {
            return T->rchild;
        }}
        if(T->rchild)
        if(T->rchild->data.key==e)
        {
            return T->lchild;
        }
        return GetSibling(T->lchild,e)?GetSibling(T->lchild,e):GetSibling(T->rchild,e);
    
    /********** End **********/
}
status InsertNode(BiTree &T, KeyType e, int LR, TElemType c)
{
    BiTree p = NULL, q = NULL;
    if (LR == -1)
    {
        p = (BiTree)malloc(sizeof(BiTNode));
        p->data = c;
        p->lchild = NULL;
        p->rchild = T;
        T = p;
        return OK;
    }
    p = Locatenode2(T, e, c);
    if (p == NULL)
        return ERROR;
    q = (BiTNode *)malloc(sizeof(BiTNode));
    q->data = c;
    if (LR == 0)
    {
        q->rchild = p->lchild;
        p->lchild = q;
        q->lchild = NULL;
        return OK;
    }
    else if (LR == 1)
    {
        q->rchild = p->rchild;
        p->rchild = q;
        q->lchild = NULL;
        return OK;
    }
    return OK;
}
BiTree Locatenode2(BiTree T, KeyType e, TElemType c)
//查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL)
    {
        return NULL;
    }
    if (T->data.key == c.key)
    {
        return NULL;
    }
    if (T->data.key == e)
    {
        return T;
    }
    BiTree lt, rt;
    lt = Locatenode2(T->lchild, e, c);
    rt = Locatenode2(T->rchild, e, c);
    if (lt == NULL && rt == NULL)
        return NULL;
    else if (lt != NULL)
        return lt;
    else
        return rt;
    /********** End **********/
}
status DeleteNode(BiTree &T, KeyType e)
{
    if (T == NULL)
    {
        return ERROR;
    }
    if (T->data.key == e)
    {
        if (T->lchild && T->rchild) //度为2
        {
            BiTree p, q;
            q = T->rchild;
            p = T;
            T = T->lchild;
            free(p);
            p = T;
            while (p->rchild)
                p = p->rchild;
            p->rchild = q;
            return OK;
        }
        else if (T->lchild)
        {
            BiTree p = T;
            T = T->lchild;
            free(p);
            p = NULL;
            return OK;
        }
        else if (T->rchild)
        {
            BiTree p = T;
            T = T->rchild;
            free(p);
            p = NULL;
            return OK;
        }
        else
        {
            free(T);
            T = NULL;
            return OK;
        }
    }
    return DeleteNode(T->lchild, e) + DeleteNode(T->rchild, e);
}
status PreOrderTree(BiTree T, void (*visit)(BiTree))
//先序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL)
    {
        return 1;
    }
    visit(T);
    PreOrderTree(T->lchild, visit);
    PreOrderTree(T->rchild, visit);
    return OK;
    /********** End **********/
}
status InOrderTree(BiTree T, void (*visit)(BiTree))
//中序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTree s[100], p;
    int top = 0;
    p = T;
    while (top || p)
    {
        while (p)
        {
            s[top] = p;
            top++;
            p = p->lchild;
        }
        if (top)
        {
            top--;
            p = s[top];
            visit(p);
            p = p->rchild;
        }
    }
    return OK;
    /********** End **********/
}
status PostOrderTree(BiTree T, void (*visit)(BiTree))
//后序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL)
    {
        return 1;
    }
    PostOrderTree(T->lchild, visit);
    PostOrderTree(T->rchild, visit);
    visit(T);
    return OK;
    /********** End **********/
}
 status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{

    static FILE *fp;
    i15++;
    if(j15==0)
    {
        if(T==NULL)
        {
            return INFEASIBLE;
        }
        j15 = 1;
    }
    if(!T) {
    	fp = fopen(FileName,"a+");
        fprintf(fp,"-1 ");
        fclose(fp);
        return ERROR;}
    if(flag15==0){
    //FILE *fp;
    fp = fopen(FileName,"w");
    flag15++;
    }
    else{
    fp = fopen(FileName,"a+");	
	}
    if(T){
    fprintf(fp,"%d ",i15);
    fprintf(fp,"%d ",T->data.key);
    fprintf(fp,"%s ",T->data.others);
    fclose(fp);
    SaveBiTree(T->lchild,FileName);
    SaveBiTree(T->rchild,FileName);
    }
    return OK;
}
status LoadBiTree(BiTree &T,  char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    static FILE *fp;
    if(i16==0)
    {
        if(T!=NULL)
        {
            return INFEASIBLE;
        }
        i16 = 1;
    }
    if(flag16 == 0){
        fp = fopen(FileName,"r");
        flag16++;
    }
    fscanf(fp,"%d ",&j16);
    if(j16==-1) T=NULL;
    else{
    	T  = (BiTNode *)malloc(sizeof(BiTNode));
    	fscanf(fp,"%d ",&T->data.key);
    	fscanf(fp,"%s ",T->data.others);
    	LoadBiTree(T->lchild,FileName);
    	LoadBiTree(T->rchild,FileName);
	}
    if(fp==NULL) exit(0);
    return OK;
    /********** End 2 **********/
}
status AddTree(TREES &Trees,char Treename[])
{
    if(Trees.length>10)
    {
        return INFEASIBLE;
    }
    for (int i = 0; i < Trees.length;i++)
    {
        if(strcmp(Trees.elem[i].name,Treename)==0)
        {
            return ERROR;
        }
    }
    Trees.length++;
    strcpy(Trees.elem[Trees.length - 1].name, Treename);
    Trees.elem[Trees.length - 1].Bitree = NULL;
    return OK;
}
status DeleteTree(TREES &Trees,char treename[])
{
    if(Trees.length==0)
    {
        return INFEASIBLE;
    }
    int i = 0, flag=0;
    for (; i < Trees.length;i++)
    {
        if(strcmp(Trees.elem[i].name,treename)==0)
        {
            flag = 1;
            break;
        }
    }
    if(flag==0)
    {
        return ERROR;
    }
    DestoryBitree(Trees.elem[i].Bitree);
    for (int j = i; j < Trees.length; j++)
    {
        Trees.elem[j] = Trees.elem[j + 1];
    }
    Trees.length--;
    return OK;
}
status TraverseTrees(TREES Trees)
{
    for (int i = 0; i < Trees.length;i++)
    {
        printf("%s", Trees.elem[i].name);
        printf("\n");
        bt_print(Trees.elem[i].Bitree);
    }
    return OK;
}
int Locatetree(TREES Trees,char Name[])
{
    int i = 0, flag=0;
    for (; i < Trees.length;i++)
    {
        if(strcmp(Trees.elem[i].name,Name)==0)
        {
            flag = 1;
            break;
        }
    }
    if(flag==0)
    {
        return ERROR;
    }
    else
    {
        return i + 1;
    }
}
void bt_print(BiTree bt)
 {
	column = 0;
	lastColumn = 0;
	depthMax = 0;
	// 根据树的大小申请内存
    depthMax = BitreeDepth(bt);
    width = 3 * ((1 << (depthMax - 1)) * 2 - 1);
	int height = 1 + (depthMax - 1) * 3;
	printBuffer = (char**)malloc(height *sizeof(char*));
	for (int i = 0; i < height; i++) {
		printBuffer[i] = (char*)malloc(width * sizeof(char));
		memset(printBuffer[i],' ',width);
		printBuffer[i][width - 1] = '\0';
	}

	dep = 0;
	column = width / 2;
	lastColumn = column;
	setPrintBuffer(bt);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%c", printBuffer[i][j]);
		}
		printf("\n");
	}

}
void setPrintBuffer(BiTree t) 
{
	if (t) {
		dep++;

		TElemType data = t->data;
		printBuffer[(dep - 1) * 3][column-1] = data.key%10 + 0x30;
        printBuffer[(dep - 1) * 3][column] = ',';
        strcpy(*(printBuffer+(dep - 1) * 3)+column + 1, data.others);
		if (dep > 1) {
			int linkLineInterval =  (column- lastColumn)/3;
			char linkChar = linkLineInterval > 0 ? '\\' : '/';
			printBuffer[(dep - 1) * 3 - 1][column - linkLineInterval] = linkChar;
			printBuffer[(dep - 1) * 3 - 2][column - 2*linkLineInterval] = linkChar;
		}
		int step = (1<<(depthMax-dep-1))*3;
		lastColumn = column;
		column -= step;
		setPrintBuffer(t->lchild);
		column += step;

		lastColumn = column;
		column += step;
		setPrintBuffer(t->rchild);
		column -= step;
		dep--;
	}
}
void visit(BiTree T)
{
    printf(" %d,%s",T->data.key,T->data.others);
}