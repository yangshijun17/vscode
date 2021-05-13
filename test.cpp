#include <stddef.h> //malloc等动态分配函数
#include <stdlib.h> //系统清屏函数
#include <stdio.h>  //标准输入输出函数
#include <math.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 10
#define MaxSize 10
#define FILE_SAVE_PATH ".\\in.txt" //表示数据文件的存储
#define INFEASIBLE -1
#define OVERFLOW -2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status; //status是函数类型，其值为函数结果状态代码
typedef int status;
typedef int Boolean;
typedef int Elemtype; //ElemType是用户自定义类型，为了便于根据不同使用情况修改代码
typedef int ElemType;
typedef struct
{ //顺序表（顺序结构）的定义
    ElemType *elem;
    int length;
    int listsize;
} SqList;
typedef struct
{ //线性表的管理表定义
    struct
    {
        char name[30];
        SqList L;
    } elem[10];
    int length;
    int listsize;
} LISTS;

void menu_1(void);
void menu_2(SqList *L);
void fileop(void);
Status Loaddata(FILE *fp, SqList *L);
Status filere(SqList *L1, SqList *L2);
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
status ListTraverse(SqList L); //简化过

FILE *fp;

Status main(void)
{
    menu_1();
    return 0;
}

//FILE 文件管理函数

//fileread 文件打开
Status filere(SqList *L1, SqList *L2)
{
    FILE *fp = fopen(FILE_SAVE_PATH, "r");
    if (fp == NULL)
    {
        printf("数据文件打开失败\n");
        return 0;
    }
    printf("当前正在读取表一的数据。\n");
    if (Loaddata(fp, L1) == ERROR)
    {
        printf("数据存储失败！\n");
        return ERROR;
    }
    if (Loaddata(fp, L2) == ERROR)
    {
        printf("数据存储失败！\n");
        return ERROR;
    }
    fclose(fp);
    return OK;
}

//filewrite
Status Loaddata(FILE *fp, SqList *L)
{

    if ('@' != fgetc(fp))
    {
        printf("文件缺失！\n");
        return 0;
    }
    else
    {
        switch (1)
        {
        case OK:
            printf("顺序表已初始化\n");
            break;
        case ERROR:
            printf("顺序表初始化失败\n");
            return ERROR;
        }
    }
    fscanf(fp, "%d", &(L->listsize));
    fgetc(fp);
    fscanf(fp, "%d", &(L->length));
    fgetc(fp);

    fread(L->elem, sizeof(Elemtype), L->listsize, fp);

    printf("文件已读取完毕\n");
    return OK;
}

//功能实现
status InitList(SqList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    if (L.elem == NULL)
    {
        L.elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
        if (!L.elem)
            return INFEASIBLE;

        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        return OK;
    }
    else
    {
        return INFEASIBLE;
    }
}

status DestroyList(SqList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    if (L.elem)
    {
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        //free(L.elem);
        L.elem = NULL;
        return OK;
    }
    else
        return INFEASIBLE;
}

status ClearList(SqList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    if (!L.elem)
        return INFEASIBLE;
    else
    {
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        free(L.elem);
        return OK;
    }
}

status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    if (!L.elem)
        return INFEASIBLE;
    else
    {
        if (!L.length)
            return TRUE;
        else
            return FALSE;
    }
}

status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    if (!L.elem)
        return INFEASIBLE;
    else
        return L.length;
}

status GetElem(SqList L, int i, ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (!L.elem)
        return INFEASIBLE;
    else
    {
        if (i - 1 < 0 || i - 1 > L.length - 1)
            return ERROR;
        else
        {
            e = *(L.elem + i - 1);
            return OK;
        }
    }
}

status LocateElem(SqList L, ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回OK；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    if (!L.elem)
        return INFEASIBLE;
    else
    {
        for (int i = 0; i < L.length; i++)
        {
            if (*(L.elem + i) == e)
                return i + 1;
        }
        return ERROR;
    }
}

status PriorElem(SqList L, ElemType e, ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (!L.elem)
        return INFEASIBLE;
    else
    {
        for (int i = 0; i < L.length - 1; i++)
        {
            if (*(L.elem + i) == e)
            {
                if (i != 0)
                {
                    pre = *(L.elem + i - 1);
                    return OK;
                }
                else
                    return ERROR;
            }
        }
        return ERROR;
    }
}

status NextElem(SqList L, ElemType e, ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (!L.elem)
        return INFEASIBLE;
    else
    {
        for (int i = 0; i < L.length; i++)
        {
            if (*(L.elem + i) == e)
            {
                if (i == L.length - 1)
                    return ERROR;
                else
                {
                    next = *(L.elem + i + 1);
                    return OK;
                }
            }
        }
        return ERROR;
    }
}

status ListInsert(SqList &L, int i, ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    /********** Begin *********/
    if (!L.elem)
        return INFEASIBLE;
    else
    {
        if (L.length == 0)
        {
            *L.elem = e;
            L.length += 1;
            return OK;
        }
        else if (i < 1 || i > L.length + 1)
            return ERROR;
        else
        {
            L.elem = (ElemType *)realloc(L.elem, sizeof(ElemType) * 100);

            if (i == L.length + 1)
            {
                L.length += 1;
                *(L.elem + i - 1) = e;
                return OK;
            }
            else
            {
                for (int j = L.length - 1; j > i - 2; j--)
                {
                    *(L.elem + j + 1) = *(L.elem + j);
                }
                *(L.elem + i - 1) = e;
                L.length += 1;
                return OK;
            }
        }
    }
}

status ListDelete(SqList &L, int i, ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    if (!L.elem)
        return INFEASIBLE;
    else
    {
        if (i < 1 || i > L.length)
            return ERROR;
        else
        {
            e = L.elem[i - 1];
            for (int j = i - 1; j + 1 < L.length; j++)
            {
                L.elem[j] = L.elem[j + 1];
            }
            L.length -= 1;
            return OK;
        }
    }
}

status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    if (!L.elem)
        return INFEASIBLE;
    else
    {
        if (L.length)
        {
            for (int i = 0; i < L.length - 1; i++)
            {

                printf("%d ", L.elem[i]);
            }
            printf("%d", L.elem[L.length - 1]);
        }
        return OK;
    }
}

//依次向文件中覆盖地写入
Status Savedata(FILE *fp, SqList *L)
{
    if (L->length == 0)
    {
        printf("信息不存在！\n");
        fputc('#', fp);
        return ERROR;
    }
    fputc('@', fp);
    fprintf(fp, "%d", L->listsize);
    fputc('@', fp);
    fprintf(fp, "%d", L->length);
    fputc('@', fp);
    fwrite(L->elem, sizeof(Elemtype), L->listsize, fp);
    printf("数据存储成功。\n");
    printf("%s", FILE_SAVE_PATH);
    return OK;
}
//退出函数
Status EXit(SqList *L1, SqList *L2)
{
    FILE *fp = fopen(FILE_SAVE_PATH, "w+");
    if (fp == NULL)
    {
        printf("文件建立失败！\n"); //建立失败
    }
    printf("当前正在存储表一的数据。\n");
    if (Savedata(fp, L1) == ERROR)
    {
        printf("数据存储失败！\n");
        return ERROR;
    }
    printf("当前正在存储表二的数据。\n");
    if (Savedata(fp, L2) == ERROR)
    {
        printf("数据存储失败！\n");
        return ERROR;
    }
    fclose(fp);
    getchar();
    return OK;
}
//menu

//menu 菜单：实现用户界面
void menu_1(void)
{
    SqList *L1;
    SqList li, ly;
    SqList *L2;
    L1 = &li;
    L2 = &ly;
    //InitList(*L2);
    int x;
    int op = 1; //在函数内实现变量控制和输出控制
    while (op != 0)
    {
        printf("\n\n");
        printf("                    主菜单                        \n");
        printf("-------------------------------------------------\n");
        printf("          1. 新建表文件           2. 打开已有文件\n");
        printf("          3. 退出系统              \n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[1~3]:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("请输入您要操作的表【1-2】：");
            scanf("%d", &x);
            switch (x)
            {
            case 1:
                menu_2(L1);
                printf("是否还要继续操作另一个表？（1/-1）:\n");
                scanf("%d", &op);
                if (op)
                {
                    menu_2(L2);
                    EXit(L1, L2);
                    printf("\n是否还要继续操作？（1/-1）:");
                    scanf("%d", &op);

                    if (op == 1)
                    {
                        printf("请输入您要操作的表【1-2】:");
                        scanf("%d", &x);
                        if (x == 1)
                            menu_2(L1);
                        if (x == 2)
                            menu_2(L2);
                        else
                            printf("错误输入！\n");
                        break;
                    }
                    if (op == -1)
                        break;

                    break;
                }
                else if (op == -1)
                {
                    EXit(L1, NULL);
                    break;
                }

            case 2:
                menu_2(L2);
                printf("是否还要继续操作另一个表？（1/-1）\n");
                scanf("%d", &op);
                if (op)
                {
                    menu_2(L1);
                    EXit(L1, L2);
                    printf("是否还要继续操作？（1/-1）\n");
                    scanf("%d", &op);

                    {
                        if (op == 1)
                            printf("请输入您要操作的表【1-2】：");
                        scanf("%d", &x);
                        if (x == 1)
                            menu_2(L1);
                        if (x == 2)
                            menu_2(L2);
                        else
                            printf("错误输入！\n");
                        break;
                        if (op == -1)
                            break;
                    }
                    break;
                }
                else if (op == -1)
                {
                    EXit(L2, NULL);
                    break;
                }
            default:
                printf("错误输入！\n");
                break;
            }
            break;
        case 2:
            x = filere(L1, L2);
            if (x)
            {
                printf("请输入您要操作的表【1-2】：");
                scanf("%d", &x);
                if (x == 1)
                    menu_2(L1);
                if (x == 2)
                    menu_2(L2);
                else
                    printf("错误输入！\n");
                printf("是否还要继续操作？（1/0）\n");
                scanf("%d", &op);
                while (op)
                {
                    switch (op)
                    {
                    case 1:
                        printf("请输入您要操作的表【1-2】：");
                        scanf("%d", &x);
                        if (x == 1)
                            menu_2(L1);
                        if (x == 2)
                            menu_2(L2);
                        else
                            printf("错误输入！\n");
                        printf("是否还要继续操作？（1/0）\n");
                        scanf("%d", &op);
                    case 2:
                        op = 0;
                        break;
                    default:
                        printf("错误输入！\n");
                        break;
                    }
                }
                x = 0;
                menu_1();
            }
            //这里从文件中逐个读取数据元素恢复顺序表，对于不同的物理结构，可通过读//取的数据元素恢复内存中的物理结构。
            break;

        case 3:
            EXit(L1, L2);
            exit(0);
            break;
        } //end of switch
    }     //end of while
}
void menu_2(SqList *L)
{

    int op = 1, j = 0, i, e, pre, next;
    char name;
    while (op)
    {
        system("cls");
        printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("          1. InitList       7. LocateElem\n");
        printf("          2. DestroyList    8. PriorElem\n");
        printf("          3. ClearList      9. NextElem \n");
        printf("          4. ListEmpty      10. ListInsert\n");
        printf("          5. ListLength     11. ListDelete\n");
        printf("          6. GetElem        12. ListTrabverse\n");
        printf("           0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    请选择你的操作[0~12]:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\n----IntiList功能待实现！\n");
            if (InitList(*L) == OK)
                printf("线性表创建成功！\n");
            else
                printf("线性表创建失败！\n");
            getchar();
            getchar();
            break;
        case 2:
            printf("\n----DestroyList功能待实现！\n");
            if (DestroyList(*L) == OK)
                printf("线性表销毁成功！\n");
            else
                printf("线性表销毁失败！\n");
            getchar();
            getchar();
            break;
        case 3:
            printf("\n----ClearList功能待实现！\n");
            if (ClearList(*L) == OK)
                printf("线性表清空成功！\n");
            else
                printf("线性表清空失败！\n");
            getchar();
            getchar();
            break;
        case 4:
            printf("\n----ListEmpty功能待实现！\n");
            if (ListEmpty(*L) == TRUE)
                printf("线性表长度为0！\n");
            else if (ListEmpty(*L) == FALSE)
                printf("线性表长度不为0！\n");
            else
                printf("线性表不存在");
            getchar();
            getchar();
            break;
        case 5:
            printf("\n----ListLength功能待实现！\n");
            j = ListLength(*L);
            if (j != INFEASIBLE)
                printf("线性表长度为%d\n", j);
            else
                printf("线性表不存在\n");
            getchar();
            getchar();
            break;
        case 6:
            printf("\n----输入你想获取的元素的位置，请填正整数，线性表的总长度为%d\n", (*L).length);
            scanf("%d", &i);
            printf("\n----GetElem功能待实现！\n");
            j = GetElem(*L, i, e);
            if (j == OK)
                printf("查找成功！线性表第%d个元素值为%d\n", i, e);
            else if (j == ERROR)
                printf("%d小于1或者%d超过线性表长度，输入不合法！\n", i, i);
            else
                printf("线性表不存在\n");
            getchar();
            getchar();
            break;
        case 7:
            printf("\n----请输入想查找的元素值\n");
            scanf("%d", &e);
            printf("\n----LocateElem功能待实现！\n");
            j = LocateElem(*L, e);
            if (j == INFEASIBLE)
                printf("线性表不存在\n");
            else if (j == ERROR)
                printf("线性表中无值为%d的元素，查找失败\n", e);
            else
                printf("查找成功！线性表中值为%d的元素是第%d个\n", e, j);
            getchar();
            getchar();
            break;
        case 8:
            printf("\n----请输入想获取前驱的元素值\n");
            scanf("%d", &e);
            printf("\n----PriorElem功能待实现！\n");
            j = PriorElem(*L, e, pre);
            if (j == INFEASIBLE)
                printf("线性表不存在\n");
            else if (j == ERROR)
                printf("没有找到指定元素%d的前驱，查找失败\n", e);
            else
                printf("查找成功！指定元素%d的前驱为%d", e, pre);
            getchar();
            getchar();
            break;
        case 9:
            printf("\n----请输入想获取后继的元素值\n");
            scanf("%d", &e);
            printf("\n----NextElem功能待实现！\n");
            j = NextElem(*L, e, next);
            if (j == INFEASIBLE)
                printf("线性表不存在\n");
            else if (j == ERROR)
                printf("没有找到指定元素%d的后继，查找失败\n", e);
            else
                printf("查找成功！指定元素%d的后继为%d\n", e, next);
            getchar();
            getchar();
            break;
        case 10:
            printf("\n----请输入在第几个元素前插入新的元素值");
            printf("\n元素位置:");
            scanf("%d", &i);
            printf("\n元素值：");
            scanf("%d", &e);
            printf("\n----ListInsert功能待实现！\n");
            j = ListInsert(*L, i, e);
            if (j == INFEASIBLE)
                printf("线性表不存在");
            else if (j == ERROR)
                printf("插入失败");
            else
                printf("插入成功！");
            getchar();
            getchar();
            break;
        case 11:
            printf("\n----请输入待删除元素的元素位置");
            scanf("%d", &i);
            printf("\n----ListDelete功能待实现！\n");
            j = ListDelete(*L, i, e);
            if (j == INFEASIBLE)
                printf("线性表不存在");
            else if (j == ERROR)
                printf("删除失败");
            else
                printf("删除成功！删除元素的值为%d", e);
            getchar();
            getchar();
            break;
        case 12:
            printf("\n----ListTrabverse功能待实现！\n");
            if (ListTraverse(*L) == INFEASIBLE)
                printf("线性表是空表！\n");
            getchar();
            getchar();
            break;
        case 0:
            break;
        } //end of switch
    }     //end of while
}