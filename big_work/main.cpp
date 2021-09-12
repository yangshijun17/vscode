#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int boolnum;
int clausnum;
int *flag;
typedef struct _charanode
{
    int data;
    struct _charanode *next;
} charanode;
typedef struct _cnf
{
    charanode *head;
    struct _cnf *next;
} cnf;
int readCNF(cnf *&CNF, char Filename[80]);
void deleteCNF(cnf *&CNF);
void showCNF(cnf *CNF);
int isOneClause(charanode *chara);
int deleteClause(cnf *&CNF, cnf *&deleted);
int deletechara(charanode *&head, charanode *&CNF);
int iswithEmptyClause(cnf *CNF);
int DPLL(cnf *&CNF, int value[]);
void addClause(cnf *&CNF, charanode *boolnode);
void copyclause(cnf *&CNF, cnf *CNF2);
int savedata(int value[], char Filename[], double time);
int main()
{
    cnf *CNF = NULL;
    int opt = 1;
    int *value;
    clock_t start, finish;
    char Filename[80];
    while (opt)
    {
        //system("cls");
        printf("\n\n");
        printf("                    Menu Of options   \n");
        printf("-----------------------------------------------------\n");
        printf("1. Read the CNF file              2. Show every clause\n");
        printf("3. Solve it by DPLL and save the answer   4. Sudoku \n");
        printf("                      0. exit\n");
        printf("---------------------------------------------------- \n");
        printf("Please input your option[0-4]\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        {
            printf("Please input the path of the CNF file\n");
            scanf("%s", Filename);
            int ret = readCNF(CNF, Filename);
            if (ret == 0)
                printf("the path of file is error!\n");
            else
                printf("read the data from the CNF file successfully\n");
            getchar();
            getchar();
            break;
        }
        case 2:
        {
            if (CNF == NULL)
            {
                printf("Please read the data first!\n");
            }
            else
            {
                printf("the clause in this file is as follows:\n");
                showCNF(CNF);
            }
            getchar();
            getchar();
            break;
        }
        case 3:
        {
            if (CNF == NULL)
            {
                printf("Please read the data first!\n");
            }
            else
            {
                value = (int *)malloc(sizeof(int) * (boolnum + 1));
                for (int i = 1; i <= boolnum; i++)
                    value[i] = 1;
                start = clock();
                int result = DPLL(CNF, value);
                finish = clock();
                printf("result: %d\n", result);
                if (result)
                {
                    printf("the answer is as follows:\n");
                    for (int i = 1; i <= boolnum; i++)
                    {
                        if (value[i])
                            printf("%d ", i);
                        else
                            printf("-%d ", i);
                    }
                }
                double time = (double)(finish - start) / CLOCKS_PER_SEC;
                printf("\nruntime:%lf\n", time * 1000);
                savedata(value, Filename, time);
                printf("This file is saved with the same name of CNF\n");
            }
            getchar();
            getchar();
            break;
        }
        case 0:
        {
            printf("welcome to this system next time!\n");
            break;
        }
        } // end of switch
    }     // end of while
}
int readCNF(cnf *&CNF, char Filename[80]) //将文件中的内容导入到十字链表中，文件打开失败返回0
{
    FILE *fp;
    fp = fopen(Filename, "r");
    if (fp == NULL)
    {
        return 0;
    }
    char c;
    fscanf(fp, "%c", &c);
    while (c == 'c')
    {
        while (c != '\n' && c != '\r')
            fscanf(fp, "%c", &c);
        fscanf(fp, "%c", &c);
        if (c == '\n')
            fscanf(fp, "%c", &c);
    }
    fscanf(fp, " cnf ");
    fscanf(fp, "%d", &boolnum);
    fscanf(fp, "%d", &clausnum);
    CNF = (cnf *)malloc(sizeof(cnf));
    CNF->next = NULL;
    CNF->head = (charanode *)malloc(sizeof(charanode));
    CNF->head->next = NULL;
    cnf *tailcnf = CNF;
    charanode *tailbool = CNF->head;
    int key;
    for (int i = 0; i < clausnum; i++)
    {
        fscanf(fp, "%d", &key);
        while (key != 0)
        {
            tailbool->data = key;
            tailbool->next = (charanode *)malloc(sizeof(charanode));
            fscanf(fp, "%d", &key);
            if (key == 0)
                tailbool->next = NULL;
            tailbool = tailbool->next;
        }
        tailcnf->next = (cnf *)malloc(sizeof(cnf));
        tailcnf->next->head = (charanode *)malloc(sizeof(charanode));
        if (i == clausnum - 1)
        {
            tailcnf->next = NULL;
            break;
        }
        tailcnf = tailcnf->next;
        tailbool = tailcnf->head;
    }
    fclose(fp);
    return 1;
}
void showCNF(cnf *CNF) //将十字链表中的内容打印出来
{
    cnf *p = CNF;
    for (int i = 1; i <= clausnum; i++)
    {
        charanode *q = p->head;
        while (q)
        {
            printf("%d ", q->data);
            q = q->next;
        }
        printf("\n");
        p = p->next;
    }
}
int isOneClause(charanode *chara) //判断该子句是否为单子句，是则返回1，否则返回0
{
    if (chara != NULL && chara->next == NULL)
        return 1;
    return 0;
}
int deleteClause(cnf *&CNF, cnf *&deleted) //删除十字链表中的deleted子句，并返回1，删除失败则返回0
{
    cnf *p = CNF;
    if (deleted == p) //如果是第一个
    {
        CNF = CNF->next; //直接指向下一个
        free(deleted);   //删除
        deleted = NULL;
        return 1;
    }
    else //否则找到该节点并进行删除
    {
        while (p && p->next != deleted)
            p = p->next;
        p->next = p->next->next;
        free(deleted);
        deleted = NULL;
        return 1;
    }
    return 0;
}
int deletechara(charanode *&head, charanode *&deleted) //删除当前子句中的某个文字
{
    charanode *p = head;
    if (p == deleted)
    {
        head = head->next;
        free(deleted);
        deleted = NULL;
        return 1;
    }
    else
    {
        while (p != NULL && p->next != deleted)
            p = p->next;
        p->next = p->next->next;
        free(deleted);
        deleted = NULL;
        return 1;
    }
    return 0;
}
int iswithEmptyClause(cnf *CNF) //判断其是否含有空子句
{
    cnf *p = CNF;
    while (p != NULL)
    {
        if (p->head == NULL)
            return 1;
        p = p->next;
    }
    return 0;
}
void copyclause(cnf *&CNF, cnf *CNF2) //该函数将CNF2的值赋到CNF
{
    cnf *cocnf, *cocnf2;
    charanode *boolnode1, *boolnode2;
    CNF = (cnf *)malloc(sizeof(cnf));
    CNF->head = (charanode *)malloc(sizeof(charanode));
    CNF->next = NULL;
    CNF->head->next = NULL; //将CNF进行初始化
    for (cocnf = CNF, cocnf2 = CNF2; cocnf2; cocnf2 = cocnf2->next, cocnf = cocnf->next)
    { //两重循环遍历整个十字链表
        for (boolnode1 = cocnf->head, boolnode2 = cocnf2->head; boolnode2; boolnode1 = boolnode1->next, boolnode2 = boolnode2->next)
        {
            boolnode1->data = boolnode2->data;
            boolnode1->next = (charanode *)malloc(sizeof(charanode));
            boolnode1->next->next = NULL;
            if (boolnode2->next == NULL) //特判一下，如果被拷贝的为最后一个字节，则将当前的置为空
            {
                free(boolnode1->next);
                boolnode1->next = NULL;
            }
        }
        cocnf->next = (cnf *)malloc(sizeof(cnf)); //然后继续拷贝下一个子句，首先对下一个子句的结点进行声明
        cocnf->next->head = (charanode *)malloc(sizeof(charanode));
        cocnf->next->head->next = NULL;
        cocnf->next->next = NULL;
        if (cocnf2->next == NULL) //同样道理的特判
        {
            free(cocnf->next->head);
            free(cocnf->next);
            cocnf->next = NULL;
        }
    }
}
int DPLL(cnf *&CNF, int value[]) //利用DPLL算法来解析cnf文件
{
    cnf *p, *q, *r;
    p = CNF, q = CNF;
    charanode *boolnode;
    int *num, max, maxpos; //num数组用来记录每个文字出现的次数，从而在其中找到应该被处理的那个文字
    flag = (int *)malloc(sizeof(int) * (boolnum + 2));
    while (p != NULL)
    {
        while (p && isOneClause(p->head) == 0)
            p = p->next;
        if (p)
        {
            int singlekey = p->head->data;
            if (singlekey > 0)
                value[singlekey] = 1;
            else
                value[-singlekey] = 0;
            for (q = CNF; q; q = r)
            {
                r = q->next;
                for (int i = 0; i <= boolnum; i++)
                {
                    flag[i] = 0;
                }
                for (boolnode = q->head; boolnode; boolnode = boolnode->next)
                {
                    if (flag[abs(boolnode->data)] != 2)
                    {
                        flag[abs(boolnode->data)]++;
                    }
                    else
                    {
                        deleteClause(CNF, q);
                        break;
                    }
                    if (boolnode->data == singlekey)
                    {
                        deleteClause(CNF, q);
                        break;
                    }
                    if (boolnode->data == -singlekey)
                    {
                        deletechara(q->head, boolnode);
                        break;
                    }
                }
            }
            if (CNF == NULL)
            {
                return 1;
            }
            else if (iswithEmptyClause(CNF))
            {
                deleteCNF(CNF);
                return 0;
            }
            p = CNF;
        }
    }
    num = (int *)malloc(sizeof(int) * (2 * boolnum + 2));
    for (int i = 0; i <= 2 * boolnum; i++)
        num[i] = 0;
    for (p = CNF; p; p = p->next)
    {
        for (boolnode = p->head; boolnode; boolnode = boolnode->next)
            if (boolnode->data > 0)
                num[boolnode->data]++;
            else
                num[boolnum - boolnode->data]++;
    }
    max = 0;
    maxpos = 0;
    for (int i = 1; i <= boolnum; i++)
    {
        if (max < num[i])
        {
            max = num[i];
            maxpos = i;
        }
    }
    if (max == 0)
        for (int i = boolnum + 1; i <= 2 * boolnum; i++)
        {
            if (max < num[i])
            {
                max = num[i];
                maxpos = -i;
            }
        }
    free(num);
    p = (cnf *)malloc(sizeof(cnf));
    p->head = (charanode *)malloc(sizeof(charanode));
    p->head->data = maxpos;
    p->head->next = NULL;
    p->next = NULL;
    q = NULL;
    copyclause(q, CNF);
    if (p != NULL)
    {
        p->next = q;
        q = p;
    }
    if (DPLL(q, value) == 1)
        return 1;
    deleteCNF(q);
    p = (cnf *)malloc(sizeof(cnf));
    p->head = (charanode *)malloc(sizeof(charanode));
    p->head->data = -maxpos;
    p->head->next = NULL;
    p->next = NULL;
    if (p != NULL)
    {
        p->next = CNF;
        CNF = p;
    }
    int i = DPLL(CNF, value);
    deleteCNF(CNF);
    return i;
}
void deleteCNF(cnf *&CNF)
{
    cnf *p1, *p2;
    charanode *q1, *q2;
    for (p1 = CNF; p1 != NULL; p1 = p2)
    {
        p2 = p1->next;
        for (q1 = p1->head; q1 != NULL; q1 = q2)
        {
            q2 = q1->next;
            free(q1);
        }
        free(p1);
    }
    CNF = NULL;
}
int savedata(int value[], char Filename[], double time)
{
    FILE *fp;
    for (int i = 0; Filename[i] != '\0'; i++)
    {
        if (Filename[i] == '.' && Filename[i + 4] == '\0')
        {
            Filename[i + 1] = 'a';
            Filename[i + 2] = 'n';
            Filename[i + 3] = 's';
            break;
        }
    }
    fp = fopen(Filename, "w");
    if (fp == NULL)
    {
        printf("can't open this file!\n");
        return 0;
    }
    for (int i = 1; i <= boolnum; i++)
    {
        if (value[i])
            fprintf(fp, "%d ", i);
        else
            fprintf(fp, "-%d ", i);
    }
    fprintf(fp, "\nruntime: \n%lfs", time * 1000);
    fclose(fp);
    return 1;
}
