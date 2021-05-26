#include <stdio.h>
#include <stdlib.h>
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
} BiTNode, *BiTree;
typedef struct
{ //线性表的集合类型定义
    struct
    {
        char name[30]; //这个线性表的名字
        BiTree Bitree; //线性表
    } elem[10];
    int length; //线性表组中一共有多少线性表
} TREES;
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
BiTree PreOrderTree(BiTree T, void (*visit)(BiTree));
BiTree InOrderTree(BiTree T, void (*visit)(BiTree));
BiTree PostOrderTree(BiTree T, void (*visit)(BiTree));
BiTree LeverOrderTree(BiTree T, void (*visit)(BiTree));
status SaveData(BiTree T, char Filename[]);
status LoadData(BiTree &T, char Filename[]);
status AddTree(TREES &trees, char treename[]);
status DeleteTree(TREES &trees, char treename[]);
status TraverseTrees(TREES trees);
status Locatetree(TREES trees, char treename[]);
status check(BiTree T);
void visit(BiTree T);
int main()
{
    int op = 1, num, flag = 0;
    //flag为对二叉树操作还是对二叉树组操作
    //num为操作的二叉树的序号
    BiTree T;
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
                    printf("现在还没有线性表，建议您使用功能13创建哦\n");
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
                scanf("%d,%s", definition[j].key, definition[j].others);
            } while (definition[j++].key != -1);
            int i = CreateBitree(Trees.elem[num - 1].Bitree, definition);
            if (i == OK)
                printf("二叉树已经成功创建!\n");
            else if (i == ERROR)
                printf("输入关键字不唯一!请检查输入的先序序列!\n");
            break;
        }
        case 2:
        {
            printf("正在实现DestoryTree功能\n");
            int i = DestoryBitree(Trees.elem[num - 1].Bitree);
            if (check(Trees.elem[num - 1].Bitree) == INFEASIBLE)
            {
                printf("该二叉树不存在!\n");
            }
            else
            {
                printf("第%d个二叉树%s销毁成功!\n", num, Trees.elem[num - 1].name);
            }
            break;
        }
        case 3:
        {
            printf("正在实现ClearTree功能\n");
            int i = ClearBitree(Trees.elem[num - 1].Bitree);
            if (check(Trees.elem[num - 1].Bitree) == INFEASIBLE)
            {
                printf("该二叉树不存在!\n");
            }
            else
            {
                //Trees.elem[num - 1].Bitree=(BiTree)malloc(sizeof(BiTNode));
                printf("第%d个二叉树%s已成功清除!\n", num, Trees.elem[num - 1].name);
            }
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
            printf("二叉树%s的深度为%d", Trees.elem[num - 1].name, i);
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
                printf("在二叉树%s中没有找到有关键字%d的结点", Trees.elem[num - 1].name, e);
            }
            else
            {
                printf("关键字为%d的结点对应的数据为%s", e, T->data.others);
            }
            break;
        }
        case 7:
        {
            printf("正在实现Assign功能\n");
            printf("请输入您希望赋值的结点的关键字以及希望赋的值:\n");
            KeyType e;
            TElemType value;
            scanf("%d%d,%s", &e, &value.key, value.others);
            int i = Assign(Trees.elem[num - 1].Bitree, e, value);
            if (i == ERROR)
            {
                printf("赋值操作失败!请检查该二叉树中是否存在关键字为%d的结点或者希望赋的值的关键字与二叉树中的重复!\n", e);
            }
            else
                printf("已成功赋值!\n");
            break;
        }
        case 8:
        {
            printf("正在实现GetSiblings功能\n");
            printf("请输入您希望查找它兄弟结点的结点的关键字:\n");
            KeyType e;
            scanf("%d", &e);
            BiTree T = GetSibling(Trees.elem[num - 1].Bitree, e);
            printf("关键字为%d的结点的兄弟结点对应数据为:\n");
            printf("关键字:%d  数据:%s", T->data.key, T->data.others);
            break;
        }
        case 9:
        {
            printf("正在实现InsertNode功能\n");
            printf("请输入您想要插入的结点的关键字，插入的位置，插入结点的数据\n");
            printf("其中对于插入的位置，输入-1作为根节点插入，输入0作为对应关键字结点的左孩子插入，输入为1作为对应关键字结点的右孩子插入\n");
            printf("其中对于插入结点数据的输入，请以逗号隔开\n");
            KeyType e;
            int LR;
            TElemType c;
            scanf("%d%d%d,%c", e, LR, c.key, c.others);
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
        } //end of switch
    }     //end of while
}
status CreateBitree(BiTree &T, TElemType definition[])
{
    static int i = 0;
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
    //以上为查重的代码
    if (definition[i].key == -1)
        return OK; //读到最后，返回OK
    else if (definition[i].key == 0)
    {
        T = NULL;
        i++;
        return OK; //如果为0的话，当前结点为空，i自增，不用继续递归调用
    }
    else if (definition[i].key != -1)
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data = definition[i]; //已经求了T的数据域
        i++;
        CreateBitree(T->lchild, definition); //根据前序遍历的特征，递归创建T的左孩子
        CreateBitree(T->rchild, definition); //递归创建T的右孩子
        return OK;
    }
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
}
status ClearTree(BiTree &T)
{
    if (T != NULL)
    {
        ClearTree(T->lchild);
        ClearTree(T->rchild);
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
    if (T->data.key == value.key && value.key != e)
    {
        return 2; //如果关键字重复，那么返回2
    }
    if (T->data.key == e)
    {
        T->data = value;
        return OK;
    }
    if ((Assign(T->lchild, e, value) == 1 && Assign(T->rchild, e, value) != 2) || (Assign(T->rchild, e, value) == 1 && Assign(T->lchild, e, value) != 2))
    {
        return OK; //最终返回OK的必要条件就是，左树找到并且右树无重复，或者相反的情况
    }
    else
        return ERROR;
    /********** End **********/
}
BiTree GetSibling(BiTree T, KeyType e)
{
    if (T == NULL)
        return NULL;
    if (T->lchild)
    {
        if (T->lchild->data.key == e)
            return T->rchild; //左孩子符合条件就返回右孩子
    }
    else if (T->rchild)
    {
        if (T->rchild->data.key == e)
            return T->lchild; //右孩子符合条件就返回左孩子
    }
    //否则递归查找，如果左子树里有就返回左子树里的，否则返回右子树
    return GetSibling(T->lchild, e) != NULL ? GetSibling(T->lchild, e) : GetSibling(T->rchild, e);
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
status PreOrderTraverse(BiTree T, void (*visit)(BiTree))
//先序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL)
    {
        return 1;
    }
    visit(T);
    PreOrderTraverse(T->lchild, visit);
    PreOrderTraverse(T->rchild, visit);

    /********** End **********/
}
status InOrderTraverse(BiTree T, void (*visit)(BiTree))
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
    /********** End **********/
}
status PostOrderTraverse(BiTree T, void (*visit)(BiTree))
//后序遍历二叉树T
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL)
    {
        return 1;
    }
    PostOrderTraverse(T->lchild, visit);
    PostOrderTraverse(T->rchild, visit);
    visit(T);
    /********** End **********/
}
void visit(BiTree T)
{
    printf(" %d,%s", T->data.key, T->data.others);
}