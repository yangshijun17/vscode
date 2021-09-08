#include "def.h"
void readCNF(cnf &CNF,char filename[80])
{
    FILE *fp;
    char c;
    fp = fopen(filename,"r");
    if(fp==NULL)
    {
    //    \\ printf("文件打开失败，请检查输入的文件路径是否正确！\n");
        return;
    }
    fscanf(fp, "%c", &c);
    while(c=='c')
    {
        while(c!='\n'&&c!='\r')
            fscanf(fp, "%c", &c);
        fscanf(fp, "%c", &c);
        if(c=='\n')
            fscanf(fp, "%c", &c);
    }
    fscanf(fp, " cnf ");
    fscanf(fp, "%d",&CNF.charanum);
    fscanf(fp, " ");
    pCnode tailC;
    CNF.first = (pCnode)malloc(sizeof(Cnode));
    tailC = CNF.first;
    fscanf(fp, "%d", &CNF.clausenum);
    for (int i = 1; i <= CNF.clausenum;i++)
    {
        int nowcharnum = 0;
        pCnode p = (pCnode)malloc(sizeof(Cnode));
        pVnode tailV;
        while(1)
        {
            int nowkey;
            fscanf(fp, "%d", &nowkey);
            if(nowkey==0)
            {
                p->length = nowcharnum;
                tailV->next = NULL;
                break;
            }
            nowcharnum++;
            if(nowcharnum==1)
            {
                p->first->key = nowkey;
                tailV = p->first;
            }
            else
            {
                Vnode *q = (pVnode)malloc(sizeof(Vnode));
                q->key = nowkey;
                q->next = NULL;
                tailV->next = q;
                tailV = q;
            }
        }
        tailC->next = p;
        tailC = p;
    }
}
void showCNF(cnf CNF)
{
    Cnode *p = CNF.first;
    for (int i = 1; i <= CNF.clausenum;i++)
    {
        pVnode q = p->first;
        while(q)
        {
            printf("%d ", q->key);
            q = q->next;
        }
        p = p->next;
        printf("\n");
    }
}