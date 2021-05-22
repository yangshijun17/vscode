/* Linear Table On Sequence Structure */
#include <stdio.h>
#include <stdlib.h>
/*---------page 10 on textbook ---------*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int status;
typedef int ElemType; //数据元素类型定义
/*-------page 22 on textbook -------*/
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
typedef struct
{ //顺序表（顺序结构）的定义
    ElemType *elem = NULL;
    int length;
    int listsize;
} SqList;
typedef struct
{ //线性表的集合类型定义
    struct
    {
        char name[30]; //这个线性表的名字
        SqList L;      //线性表
    } elem[10];
    int length; //线性表组中一共有多少线性表
} LISTS;
/*-----page 19 on textbook ---------*/
status InitList(SqList &L);
status DestroyList(SqList &L);
status ClearList(SqList &L);
status ListEmpty(SqList L);
status ListLength(SqList L);
status GetElem(SqList L, int i, ElemType &e);
status LocateElem(SqList L, ElemType e); //简化过
status PriorElem(SqList L, ElemType cur, ElemType &pre_e);
status NextElem(SqList L, ElemType cur, ElemType &next_e);
status ListInsert(SqList &L, int i, ElemType e);
status ListDelete(SqList &L, int i, ElemType &e);
status ListTrabverse(SqList L);
status SaveList(SqList L, char FileName[]);
status LoadList(SqList &L, char FileName[]);
status AddList(LISTS &Lists, char ListName[]);
status RemoveList(LISTS &Lists, char ListName[]);
status LocateList(LISTS Lists, char ListName[]);
status TrabverseList(LISTS Lists); //简化过
/*--------------------------------------------*/
int main()
{
    SqList L;
    LISTS Lists;
    //L.elem = NULL;
    Lists.length = 0;
    int op = 1, e, i, num, flag = 0;
    while (op)
    {
        system("cls");
        printf("\n\n      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitList       10. ListInsert\n");
        printf("    	  2. DestroyList    11. ListDelete\n");
        printf("    	  3. ClearList       12. ListTrabverse\n");
        printf("    	  4. ListEmpty     13. AddList\n");
        printf("    	  5. ListLength     14. RemoveList\n");
        printf("    	  6. GetElem       15. LocateList\n");
        printf("          7. LocateElem      16. TrabverseList\n");
        printf("          8. PriorElem    17. SaveList\n");
        printf("          9. NextElem      18. LoadList\n");
        printf("                   0. Exit\n");
        printf("-------------------------------------------------\n");
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
        switch (op)
        {
        case 1:
            printf("正在实现IntiList功能\n");
            //printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
            if (InitList(Lists.elem[num - 1].L) == OK)
                printf("线性表创建成功！\n");
            else
                printf("线性表创建失败！\n");
            break;
        case 2:
            printf("正在实现DestoryList功能\n");
            //printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
            if (DestroyList(Lists.elem[num - 1].L) == INFEASIBLE)
            {
                printf("线性表L不存在，销毁失败!\n");
            }
            else
            {
                printf("线性表L成功销毁!\n");
            }
            break;
        case 3:
            printf("正在实现ClearList功能\n");
            //printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
            if (ClearList(Lists.elem[num - 1].L) == INFEASIBLE)
            {
                printf("线性表L不存在，清除失败!\n");
            }
            else
            {
                printf("已成功清除\n");
            }
            break;
        case 4:
            printf("正在实现ListEmpty功能!\n");
            //printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
            if (ListEmpty(Lists.elem[num - 1].L) == INFEASIBLE)
            {
                printf("线性表不存在!\n");
            }
            else if (ListEmpty(Lists.elem[num - 1].L) == TRUE)
            {
                printf("线性表为空!\n");
            }
            else
            {
                printf("线性表非空!\n");
            }
            break;
        case 5:
            printf("正在实现ListLength功能\n");
            //printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
            if (ListLength(Lists.elem[num - 1].L) == INFEASIBLE)
            {
                printf("线性表不存在!\n");
            }
            else
            {
                printf("线性表的长度为:%d\n", ListLength(Lists.elem[num - 1].L));
            }
            break;
        case 6:
            printf("正在实现GetElem功能\n");
            //printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
            printf("请输入您需要的线性表中的元素序号\n");
            scanf("%d", &i);
            putchar('\n');
            if (GetElem(Lists.elem[num - 1].L, i, e) == INFEASIBLE)
            {
                printf("线性表不存在!\n");
            }
            else if (GetElem(Lists.elem[num - 1].L, i, e) == ERROR)
            {
                printf("输入的元素序号有误!,请重新输入!\n");
            }
            else
            {
                printf("您需要的第%d个元素为%d\n", i, e);
            }
            break;
        case 7:
        {
            printf("正在实现LocateElem功能\n");
            //printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
            printf("请输入您需要查找的元素值:");
            scanf("%d", &e);
            putchar('\n');
            int j = LocateElem(Lists.elem[num - 1].L, e);
            if (j == INFEASIBLE)
            {
                printf("线性表不存在!\n");
            }
            else if (j == ERROR)
            {
                printf("未查找到该元素的位置，线性表中无该元素!\n");
            }
            else
            {
                printf("元素%d的位置序号为%d\n", e, j);
            }
            break;
        }
        case 8:
            printf("正在实现PriorElem功能\n");
            //printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
            printf("请输入您想查找前驱的元素:");
            int prior;
            scanf("%d", &e);
            putchar('\n');
            if (PriorElem(Lists.elem[num - 1].L, e, prior) == INFEASIBLE)
            {
                printf("线性表不存在!\n");
            }
            else if (PriorElem(Lists.elem[num - 1].L, e, prior) == ERROR)
            {
                printf("该元素没有前驱!\n");
            }
            else
            {
                printf("元素%d的前驱为%d\n", e, prior);
            }
            break;
        case 9:
            printf("正在实现NextElem功能\n");
            //printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
            printf("请输入您想查询其后继的元素:");
            int next;
            scanf("%d", &e);
            putchar('\n');
            if (NextElem(Lists.elem[num - 1].L, e, next) == INFEASIBLE)
            {
                printf("该线性表不存在!\n");
            }
            else if (NextElem(Lists.elem[num - 1].L, e, next) == ERROR)
            {
                printf("该元素没有后继!\n");
            }
            else
            {
                printf("元素%d的后继为%d\n", e, next);
            }
            break;
        case 10:
        {
            printf("正在实现ListInsert功能\n");
            //printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
            printf("请输入您想插入的元素以及想插入的位置(该功能将会把这个元素插入到该位置之前):");
            scanf("%d %d", &e, &i);
            putchar('\n');
            int j = ListInsert(Lists.elem[num - 1].L, i, e);
            if (j == INFEASIBLE)
            {
                printf("线性表不存在!\n");
            }
            else if (j == ERROR)
            {
                printf("插入的位置不合理!\n");
            }
            else
            {
                printf("已成功插入\n");
            }
            break;
        }
        case 11:
        {
            printf("正在实现ListDelete功能\n");
            //printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
            printf("请输入您想要删除的位置");
            scanf("%d", &i);
            putchar('\n');
            int j = ListDelete(Lists.elem[num - 1].L, i, e);
            if (j == INFEASIBLE)
            {
                printf("线性表不存在!\n");
            }
            else if (j == ERROR)
            {
                printf("删除位置不合理!\n");
            }
            else
            {
                printf("删除成功!\n");
                printf("删除的元素值为%d\n", e);
            }
            break;
        }
        case 12:
        {
            printf("正在实现ListTrabverse功能\n");
            //printf("现在正在对线性表%s进行操作哦，这是我们的第%d个线性表\n", Lists.elem[num - 1].name, num);
            int t = ListTrabverse(Lists.elem[num - 1].L);
            if (t == INFEASIBLE)
            {
                printf("线性表不存在！\n");
            }
            printf("\n");
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
            if (ll == ERROR)
            {
                printf("线性表组溢出!\n");
            }
            else

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
            {
                printf("该线性表不存在，赶快去创建一个吧!\n");
            }
            else if (j == ERROR)
            {
                printf("无法正常打开文件，请检查是否出错!\n");
            }
            else
            {
                printf("该功能已实现！");
            }
            break;
        }
        case 18:
        {
            printf("正在实现LoadList功能\n");
            char filename[100];
            printf("请输入文件路径与文件名\n");
            scanf("%s", filename);
            int j = LoadList(Lists.elem[num - 1].L, filename);
            if (j == INFEASIBLE)
            {
                printf("该线性表不为空！\n");
            }
            else if (j == ERROR)
            {
                printf("无法正常打开文件，请检查是否出错!\n");
            }
            else
            {
                printf("该功能已实现！");
            }
            break;
        }
        case 0:
        {
            break;
        }
        } //end of switch
        system("pause");
    } //end of while
    printf("欢迎下次再使用本系统！\n");
    getchar();
    getchar();
} //end of main()
/*--------page 23 on textbook --------------------*/
status InitList(SqList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem == NULL)
    {
        L.elem = (int *)malloc(100);
        L.listsize = LIST_INIT_SIZE;
        L.length = 0;
        return OK;
    }
    else
    {
        return INFEASIBLE;
    }

    /********** End **********/
}
status DestroyList(SqList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem == NULL)
    {
        return INFEASIBLE;
    }
    else
    {
        free(L.elem);
        L.elem = NULL;
        L.length = 0;
        return OK;
    }
    /********** End **********/
}
status ClearList(SqList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem == NULL)
    {
        return INFEASIBLE;
    }
    else
    {
        L.length = 0;
        return OK;
    }
    /********** End **********/
}
status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem == NULL)
    {
        return INFEASIBLE;
    }
    if (L.length == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    /********** End **********/
}
status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem == NULL)
    {
        return INFEASIBLE;
    }
    return L.length;
    /********** End **********/
}
status GetElem(SqList L, int i, ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；
//如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem == NULL)
    {
        return INFEASIBLE;
    }
    if (i > L.length || i == 0)
    {
        return ERROR;
    }
    e = L.elem[i - 1];
    return OK;
    /********** End **********/
}
status LocateElem(SqList L, ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回OK；
//如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem == NULL)
    {
        return INFEASIBLE;
    }
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            return i + 1;
        }
    }
    return ERROR;
    /********** End **********/
}
status PriorElem(SqList L, ElemType e, ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；
//如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem == NULL)
    {
        return INFEASIBLE;
    }
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            if (i > 0)
            {
                pre = L.elem[i - 1];
                return OK;
            }
        }
    }
    return ERROR;
    /********** End **********/
}
status NextElem(SqList L, ElemType e, ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；
//如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem == NULL)
    {
        return INFEASIBLE;
    }
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            if (i != L.length - 1)
            {
                next = L.elem[i + 1];
                return OK;
            }
        }
    }
    return ERROR;
    /********** End **********/
}
status ListInsert(SqList &L, int i, ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；
//当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem == NULL)
    {
        return INFEASIBLE;
    }
    if (L.length == 0)
    {
        if (i == 1)
        {
            L.elem[0] = e;
            L.length++;
            return OK;
        }
        return ERROR;
    }
    if (i > L.length + 1 || i <= 0)
    {
        return ERROR;
    }
    if (L.length == L.listsize)
    {
        L.elem = (ElemType *)realloc(L.elem, 100);
    }
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = e;
    L.length++;
    return OK;
    /********** End **********/
}
status ListDelete(SqList &L, int i, ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；
//当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (L.elem == NULL)
    {
        return INFEASIBLE;
    } /********** Begin *********/
    if (i <= 0 || i > L.length)
    {
        return ERROR;
    }
    e = L.elem[i - 1];
    for (int j = i - 1; j < L.length - 1; j++)
    {
        L.elem[j] = L.elem[j + 1];
    }
    L.length--;
    return OK;
    /********** End **********/
}
status ListTrabverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；
//如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem == NULL)
    {
        return INFEASIBLE;
    }
    if (L.length == 0)
    {
        return OK;
    }
    else
    {
        for (int i = 0; i < L.length - 1; i++)
        {
            printf("%d ", L.elem[i]);
        }
        printf("%d", L.elem[L.length - 1]);
        return OK;
    }
    /********** End **********/
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
    while (ListName[i])
    {
        Lists.elem[Lists.length - 1].name[i] = ListName[i];
        i++;
    }
    Lists.elem[Lists.length - 1].name[i] = '\0';
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
status SaveList(SqList L, char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    /********** Begin *********/
    if (L.elem == NULL)
    {
        return INFEASIBLE;
    }
    FILE *r;
    r = fopen(FileName, "w");
    if (r == NULL)
    {
        return ERROR;
    }
    for (int i = 0; i < L.length; i++)
    {
        fprintf(r, "%d ", L.elem[i]);
    }
    fclose(r);
    return OK;
    /********** End **********/
}
status LoadList(SqList &L, char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.length != 0)
    {
        return INFEASIBLE;
    }
    FILE *r;
    r = fopen(FileName, "r");
    if (r == NULL)
    {
        return ERROR;
    }
    L.elem = (ElemType *)malloc(100);
    L.length = 0;
    L.listsize = 100;
    int t, i = 0;
    while (fscanf(r, "%d", &t) != EOF && r != NULL)
    {
        L.elem[i] = t;
        i++;
        L.length++;
    }
    fclose(r);
    return OK;
    /********** End **********/
}