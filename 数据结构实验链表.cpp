/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <stdlib.h>
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
int main()
{
    LinkList L;
    L = NULL;
    int op = 1, j, e;
    while (op)
    {
        system("cls");
        printf("\n\n      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitList       7. LocateElem\n");
        printf("    	  2. DestroyList    8. PriorElem\n");
        printf("    	  3. ClearList       9. NextElem \n");
        printf("    	  4. ListEmpty     10. ListInsert\n");
        printf("    	  5. ListLength     11. ListDelete\n");
        printf("    	  6. GetElem       12. ListTrabverse\n");
        printf("          13. SaveList      14. LoadList\n");
        printf("                   0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("请选择一个操作:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
        {
            printf("正在实现InitList功能\n");
            j = InitList(L);
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
            j = DestoryList(L);
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
            j = ClearList(L);
            if (j == INFEASIBLE)
                printf("该线性表不存在!\n");
            else
                printf("该线性表已成功清空!\n");
            break;
        }
        case 4:
        {
            printf("正在实现ListEmpty功能\n");
            j = ListEmpty(L);
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
            j = ListLength(L);
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
            j = GetElem(L, i, e);
            if (j == INFEASIBLE)
                printf("线性表不存在!\n");
            else if (j == ERROR)
            {
                printf("输入的位置序号有误!\n");
            }
            else
                printf("第i个元素为%d", e);
            break;
        }
        case 7:
        {
            printf("正在实现LocateElem功能\n");
            printf("请输入您想要查找的元素的值:");
            scanf("%d", &e);
            j = LocateElem(L, e);
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
            j = PriorElem(L, e, pri);
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
            j = NextElem(L, e, next);
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
            j = ListInsert(L, i, e);
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
            j = ListDelete(L, i, e);
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
            int j = ListTraverse(L);
            if (j == INFEASIBLE)
                printf("该表不存在!\n");
            else
                break;
        }
        case 13:
        {
            printf("正在实现SaveList功能\n");
            char filename[100];
            printf("请输入文件路径与文件名:");
            scanf("%s", filename);
            int j = SaveList(L, filename);
            if (j == INFEASIBLE)
                printf("线性表不存在!\n");
            else if (j == ERROR)
                printf("无法正常打开文件!\n");
            else
                printf("已成功将线性表中的内容保存到文件中\n");
            break;
        }
        case 14:
        {
            printf("正在实现LoadList功能\n");
            char filename[100];
            printf("请输入文件路径与文件名:");
            scanf("%s", filename);
            j = LoadList(L, filename);
            if (j == INFEASIBLE)
                printf("线性表不存在!\n");
            else if (j == ERROR)
                printf("无法正常打开文件!\n");
            else
                printf("文件中的内容已成功写入到线性表中\n");
            break;
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
        free(L);
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
        LinkList p = L->next;
        free(p);
        return OK;
    }

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
    LinkList p, q;
    p = L;
    q = p->next;
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
    if (L==NULL&&L->next == NULL)
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
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    if (L!=NULL&&L->next != NULL)
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
