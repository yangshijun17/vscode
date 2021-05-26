/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int status;
typedef int ElemType; //数据元素类型定义
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef int ElemType;
typedef struct LNode
{ //单链表（链式结构）结点的定义
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
typedef struct
{ //线性表的集合类型定义
    struct
    {
        char name[30]; //这个线性表的名字
        LinkList L;    //线性表
    } elem[100];
    int length; //线性表组中一共有多少线性表
} LISTS;
status InitList(LinkList &L);
status DestoryList(LinkList &L);
status ClearList(LinkList &L);
status ListEmpty(LinkList L);
status ListLength(LinkList L);
status GetElem(LinkList L, int i, ElemType &e);
status LocateElem(LinkList L, ElemType e);
status PriorElem(LinkList L, ElemType e, ElemType &pre);
status NextElem(LinkList L, ElemType e, ElemType &next);
status ListInsert(LinkList &L, int i, ElemType e);
status ListDelete(LinkList &L, int i, ElemType &e);
status ListTraverse(LinkList L);
status SaveList(LinkList L, char Filename[]);
status LoadList(LinkList &L, char Filename[]);
status AddList(LISTS &Lists, char ListName[]);
status RemoveList(LISTS &Lists, char ListName[]);
status LocateList(LISTS Lists, char ListName[]);
status TrabverseList(LISTS Lists); //简化过
int main()
{
    LISTS Lists;
    Lists.length = 0;
    int op = 1, j, e, flag = 0, num;
    while (op)
    {
        system("cls");
        printf("\n\n      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("          1. InitList       10. ListInsert\n");
        printf("          2. DestroyList    11. ListDelete\n");
        printf("          3. ClearList       12. ListTrabverse\n");
        printf("          4. ListEmpty     13. AddList\n");
        printf("          5. ListLength     14. RemoveList\n");
        printf("          6. GetElem       15. LocateList\n");
        printf("          7. LocateElem      16. TrabverseList\n");
        printf("          8. PriorElem    17. SaveList\n");
        printf("          9. NextElem      18. LoadList\n");
        printf("                   0. Exit\n");
        printf("-------------------------------------------------\n");
        /*下面使用了大量的if-else分支结构，主要是对错误的输入进行各种情况的处理判断
        同时使用while循环，可以重复输入*/
        if (Lists.length == 0)
        {
            printf("现在还没有线性表哦，赶快使用功能13创建一个吧！\n");
            printf("当然也可以选择功能0退出系统\n");
        }
        else
        {
            printf("按0可以退出程序,按1可以继续对某个线性表进行操作,按2可以对线性表组进行操作哦\n");
            while (1)
            {
                scanf("%d", &flag);
                if (flag == 0)
                {
                    printf("\n欢迎下次使用本系统!\n");
                    getchar();
                    return 0;
                }
                else if (flag == 1)
                {
                    printf("现在一共有%d个线性表哦，赶快从里面选一个来对他进行操作吧！\n", Lists.length);
                    printf("注意这里是要输入线性表的序号哦\n");
                    while (1)
                    {
                        scanf("%d", &num);
                        if (num <= 0 || num > Lists.length)
                        {
                            printf("选择的线性表序号不对哦\n");
                        }
                        else
                            break;
                    }
                    break;
                }
                else if (flag == 2)
                {
                    printf("我们可以用功能13添加线性表，用功能14删除线性表，用功能15查找线性表哦，用功能16遍历线性表组\n");
                    break;
                }
                else
                {
                    printf("输入的值不对哦，请从0或1或2中选择一个进行输入\n");
                }
            }
        }
        if (Lists.length != 0)
        {
            while (flag == 1)
            {
                printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
                printf("请输入您需要的操作:");
                scanf("%d", &op);
                if ((op >= 0 && op <= 12) || op == 17 || op == 18)
                {
                    break;
                }
                else
                {
                    printf("选择的操作不对哦，请重新输入\n");
                }
            }
            while (flag == 2)
            {
                printf("现在正在对线性表组进行操作，请输入您需要的功能");
                scanf("%d", &op);
                if (op >= 13 && op <= 16)
                {
                    break;
                }
                else
                {
                    printf("选择的操作不对哦，请重新输入\n");
                }
            }
            while (flag != 1 && flag != 2)
            {
                scanf("%d", &op);
                if (op > 19 || op < 0)
                {
                    printf("输入的操作有误!\n");
                }
                else
                    break;
            }
        }
        else
        {
            while (1)
            {
                scanf("%d", &op);
                if (op == 13 || op == 0)
                {
                    break;
                }
                else
                {
                    printf("现在还没有线性表，建议您使用功能13创建哦\n");
                }
            }
        }
        switch (op) /*下面是对于各种情况的分支*/
        {
        case 1:
        {
            printf("正在实现InitList功能\n");
            j = InitList(Lists.elem[num - 1].L);
            if (j == INFEASIBLE)
            {
                printf("该线性表已存在，请重新选择!\n");
            }
            else
                printf("线性表已成功初始化\n");
            break;
        }
        case 2:
        {
            printf("正在实现DestroyList功能\n");
            j = DestoryList(Lists.elem[num - 1].L);
            if (j == INFEASIBLE)
            {
                printf("该线性表不存在！\n");
            }
            else
                printf("该线性表已成功销毁\n");
            break;
        }
        case 3:
        {
            printf("正在实现ClearList功能\n");
            j = ClearList(Lists.elem[num - 1].L);
            if (j == INFEASIBLE)
                printf("该线性表不存在!\n");
            else
                printf("该线性表已成功清空!\n");
            break;
        }
        case 4:
        {
            printf("正在实现ListEmpty功能\n");
            j = ListEmpty(Lists.elem[num - 1].L);
            if (j == INFEASIBLE)
                printf("该线性表不存在!\n");
            else if (j == ERROR)
                printf("线性表非空!\n");
            else
                printf("线性表为空!\n");
            break;
        }
        case 5:
        {
            printf("正在实现ListLength功能\n");
            j = ListLength(Lists.elem[num - 1].L);
            if (j == INFEASIBLE)
                printf("线性表不存在!\n");
            else
                printf("线性表长度为%d", j);
            break;
        }
        case 6:
        {
            printf("正在实现GetElem功能\n");
            printf("请输入您想要查找的元素的位置序号:\n");
            int i;
            scanf("%d", &i);
            j = GetElem(Lists.elem[num - 1].L, i, e);
            if (j == INFEASIBLE)
                printf("线性表不存在!\n");
            else if (j == ERROR)
            {
                printf("输入的位置序号有误!\n");
            }
            else
                printf("该元素为%d", e);
            break;
        }
        case 7:
        {
            printf("正在实现LocateElem功能\n");
            printf("请输入您想要查找的元素的值:");
            scanf("%d", &e);
            j = LocateElem(Lists.elem[num - 1].L, e);
            if (j == INFEASIBLE)
                printf("线性表不存在!\n");
            else if (j == ERROR)
                printf("在线性表中没有元素%d", e);
            else
                printf("线性表中元素%d的位置是%d", e, j);
            break;
        }
        case 8:
        {
            printf("正在实现PriorElem功能\n");
            printf("请输入您想要查找其前驱的元素:");
            scanf("%d", &e);
            int pri;
            j = PriorElem(Lists.elem[num - 1].L, e, pri);
            if (j == INFEASIBLE)
                printf("线性表不存在!\n");
            else if (j == ERROR)
                printf("在线性表中没有查找到元素%d的前驱", e);
            else
                printf("元素%d的前驱为%d", e, pri);
            break;
        }
        case 9:
        {
            printf("正在实现NextElem功能\n");
            printf("请输入您想要查找其后驱的元素:\n");
            scanf("%d", &e);
            int next;
            j = NextElem(Lists.elem[num - 1].L, e, next);
            if (j == INFEASIBLE)
                printf("线性表不存在!\n");
            else if (j == ERROR)
                printf("没有查找到元素%d的后驱\n", e);
            else
                printf("元素%d的后驱为%d", e, next);
            break;
        }
        case 10:
        {
            printf("正在实现ListInsert功能\n");
            printf("请输入您想要插入的位置以及插入元素的值:\n");
            int i;
            scanf("%d%d", &i, &e);
            j = ListInsert(Lists.elem[num - 1].L, i, e);
            if (j == INFEASIBLE)
                printf("线性表不存在!\n");
            else if (j == ERROR)
                printf("输入的位置错误!\n");
            else
                printf("已成功插入!\n");
            break;
        }
        case 11:
        {
            printf("正在实现ListDelete功能\n");
            printf("请输入您想要删除的元素的位置序号:\n");
            int i;
            scanf("%d", &i);
            j = ListDelete(Lists.elem[num - 1].L, i, e);
            if (j == INFEASIBLE)
                printf("线性表不存在!\n");
            else if (j == ERROR)
                printf("删除位置错误!\n");
            else
                printf("您删除的位置的元素纸为%d", e);
            break;
        }
        case 12:
        {
            printf("正在实现ListTraverse功能\n");
            int j = ListTraverse(Lists.elem[num - 1].L);
            if (j == INFEASIBLE)
                printf("该表不存在!\n");
            else if (j == ERROR)
                printf("该表为空!\n");
            break;
        }
        case 13:
        {

            printf("正在实现AddList功能\n");
            printf("先给这个线性表起个名字吧:");
            char nam[100];
            scanf("%s", nam);
            int ll = 0;
            ll = AddList(Lists, nam);
            printf("您已经成功添加一个线性表啦!\n");
            break;
        }
        case 14:
        {
            printf("正在实现RemoveList功能\n");
            printf("输入那个想要删除的线性表的名字吧:");
            char nam[100];
            scanf("%s", nam);
            if (Lists.length == 0)
            {
                printf("现在连一个线性表都没有哦,请快去创建一个吧\n");
            }
            else if (RemoveList(Lists, nam) == OK)
            {
                printf("线性表%s已经成功被删除啦!\n", nam);
            }
            else
            {
                printf("没有找到这个线性表哦\n");
            }
            break;
        }
        case 15:
        {
            printf("正在实现LocateList功能\n");
            printf("请输入那个想要查找的线性表的名字吧:");
            char nam[100];
            scanf("%s", nam);
            if (!LocateList(Lists, nam))
            {
                printf("没有找到线性表%s哦\n", nam);
            }
            else
            {
                printf("线性表%s是第%d个哦\n", nam, LocateList(Lists, nam));
            }
            break;
        }
        case 16:
        {
            printf("正在实现TrabverseList功能\n");
            int j = TrabverseList(Lists);
            if (j == INFEASIBLE)
            {
                printf("现在还没有线性表哦\n");
            }
            break;
        }
        case 17:
        {
            printf("正在实现SaveList功能\n");
            char filename[100];
            printf("请输入文件路径与文件名:");
            scanf("%s", filename);
            int j = SaveList(Lists.elem[num - 1].L, filename);
            if (j == INFEASIBLE)
                printf("线性表不存在!\n");
            else if (j == ERROR)
                printf("无法正常打开文件!\n");
            else
                printf("已成功将线性表中的内容保存到文件中\n");
            break;
        }
        case 18:
        {
            printf("正在实现LoadList功能\n");
            char filename[100];
            printf("请输入文件路径与文件名:");
            scanf("%s", filename);
            j = LoadList(Lists.elem[num - 1].L, filename);
            if (j == INFEASIBLE)
                printf("线性表不存在!\n");
            else if (j == ERROR)
                printf("无法正常打开文件!\n");
            else
                printf("文件中的内容已成功写入到线性表中\n");
            break;
        }
        case 0:
        {
            printf("欢迎下次使用本系统!\n");
            getchar();
        }
        }
        system("pause");
    }
}
status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    if (L != NULL)
    {
        return INFEASIBLE;
    }
    LinkList p;
    p = (LinkList)malloc(sizeof(LNode));
    p->next = NULL;
    L = p;
    return OK;
    /********** End **********/
}
status DestoryList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
    {
        return INFEASIBLE;
    }
    else
    {
        L = NULL;
    }
    return OK;
    /********** End **********/
}

status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
    {
        return INFEASIBLE;
    }
    else
    {
        LinkList p, q;
        p = L->next;
        while (p != NULL)
        {
            q = p->next;
            free(p);
            p = q;
        }
    }
    L->next = NULL;
    return OK;

    /********** End **********/
}
status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
    {
        return INFEASIBLE;
    }
    if (L->next == NULL)
    {
        return OK;
    }
    else
    {
        return ERROR;
    }

    /********** End **********/
}
status ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
    {
        return INFEASIBLE;
    }
    LinkList p;
    p = L->next;
    int i = 0;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;

    /********** End **********/
}
status GetElem(LinkList L, int i, ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
    {
        return INFEASIBLE;
    }
    LinkList p;
    p = L->next;
    int j = 1;
    while (p)
    {
        if (j == i)
        {
            e = p->data;
            return OK;
        }
        j++;
        p = p->next;
    }
    return ERROR;

    /********** End **********/
}
status LocateElem(LinkList L, ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
    {
        return INFEASIBLE;
    }
    LinkList p;
    p = L->next;
    int j = 1;
    while (p)
    {
        if (p->data == e)
        {
            return j;
        }
        j++;
        p = p->next;
    }
    return ERROR;

    /********** End **********/
}
status PriorElem(LinkList L, ElemType e, ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
    {
        return INFEASIBLE;
    }
    LinkList p, q;
    p = L;
    q = p->next;
    if (q == NULL)
    {
        return ERROR;
    }
    if (q->data == e)
    {
        return ERROR;
    }
    while (q)
    {
        if (q->data == e)
        {
            pre = p->data;
            return OK;
        }
        p = p->next;
        q = q->next;
    }
    return ERROR;
    /********** End **********/
}
status NextElem(LinkList L, ElemType e, ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
    {
        return INFEASIBLE;
    }
    LinkList p;
    p = L->next;
    if (p == NULL)
    {
        return ERROR;
    }
    while (p->next)
    {
        if (p->data == e)
        {
            next = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return ERROR;
    /********** End **********/
}
status ListInsert(LinkList &L, int i, ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
    {
        return INFEASIBLE;
    }
    LinkList p;
    p = L;
    int j = 0;
    while (p)
    {
        if (j == i - 1)
        {
            LinkList r;
            r = (LinkList)malloc(sizeof(LNode));
            r->data = e;
            r->next = p->next;
            p->next = r;
            return OK;
        }
        j++;
        p = p->next;
    }
    return ERROR;
    /********** End **********/
}
status ListDelete(LinkList &L, int i, ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
    {
        return INFEASIBLE;
    }
    int j = 0;
    LinkList p = L;
    while (p)
    {
        if (j == i - 1)
        {
            LinkList q = p->next;
            p->next = q->next;
            e = q->data;
            free(q);
            return OK;
        }
        j++;
        p = p->next;
    }
    return ERROR;

    /********** End **********/
}
status ListTraverse(LinkList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == NULL)
    {
        return INFEASIBLE;
    }
    LinkList q = L->next;
    if (q == NULL)
        return ERROR;
    while (q)
    {
        printf("%d ", q->data);
        q = q->next;
    }
    return OK;
    /********** End **********/
}
status SaveList(LinkList L, char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if (L == NULL && L->next == NULL)
    {
        return INFEASIBLE;
    }
    FILE *r;
    r = fopen(FileName, "w");
    if (r == NULL)
    {
        return ERROR;
    }
    LinkList p = L->next;
    while (p)
    {
        fprintf(r, "%d ", p->data);
        p = p->next;
    }
    fclose(r);
    return OK;
    /********** End 1 **********/
}

status LoadList(LinkList &L, char FileName[])
// 如果线性表L不为空，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/

    if (L->next != NULL || L == NULL)
    {
        return INFEASIBLE;
    }
    FILE *r;
    r = fopen(FileName, "r");
    if (r == NULL)
    {
        return ERROR;
    }
    L = (LinkList)malloc(sizeof(LNode));
    LinkList tail = L;
    tail->next = NULL;
    int t;
    while (fscanf(r, "%d", &t) != EOF && r != NULL)
    {
        LinkList p;
        p = (LinkList)malloc(sizeof(LNode));
        p->data = t;
        p->next = tail->next;
        tail->next = p;
        tail = p;
    }
    tail->next = NULL;
    fclose(r);
    return OK;
    /********** End 2 **********/
}
status AddList(LISTS &Lists, char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据由后台测试程序插入。
{
    /********** Begin *********/
    if (Lists.length > 10)
    {
        return ERROR;
    }
    Lists.length++;
    int i = 0;
    strcpy(Lists.elem[Lists.length - 1].name, ListName);
    InitList(Lists.elem[Lists.length - 1].L);
    return OK;
    /********** End **********/
}
status RemoveList(LISTS &Lists, char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    /********** Begin *********/
    if (Lists.length == 0)
    {
        return ERROR;
    }
    int i = 0, flag = 1;
    for (; i < Lists.length; i++)
    {
        flag = 1;
        int t = 0;
        while (Lists.elem[i].name[t] && ListName[t])
        {
            if (Lists.elem[i].name[t] != ListName[t])
            {
                flag = 0;
                break;
            }
            t++;
        }
        if (flag)
        {
            break;
        }
    }
    if (!flag)
    {
        return ERROR;
    }
    for (int j = i; j < Lists.length; j++)
    {
        Lists.elem[j] = Lists.elem[j + 1];
    }
    Lists.length--;
    return OK;
    /********** End **********/
}
status LocateList(LISTS Lists, char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    /********** Begin *********/
    for (int i = 0; i < Lists.length; i++)
    {
        int t = 0, flag = 1;
        while (Lists.elem[i].name[t] || ListName[t])
        {
            if (Lists.elem[i].name[t] != ListName[t])
            {
                flag = 0;
                break;
            }
            t++;
        }
        if (flag)
        {
            return i + 1;
        }
    }
    return 0;
    /********** End **********/
}
status TrabverseList(LISTS List)
{
    if (List.length == 0)
    {
        return INFEASIBLE;
    }
    for (int i = 0; i < List.length; i++)
    {
        printf("%d   %s\n", i + 1, List.elem[i].name);
    }
    return OK;
}
