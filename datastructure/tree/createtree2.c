#include "def.h"
#include <string.h>
int dep = 0;
// 该树的深度，如果只有根节点则深度为1
int depthMax = 0;
// 打印缓冲区的宽度，当前应打印的列数，上次打印位置的列数
int width = 0, column = 0, lastColumn = 0;
char **printBuffer = NULL;
BiTree CreateTree(TElemType X[], TElemType Y[],int n)
{
    if(n==0)
    {
        return NULL;
    }
    BiTree T = (BiTree)malloc(sizeof(BiTNode));
    T->data = X[0];
    T->lchild = NULL;
    T->rchild = NULL;
    int i = 0;
    for (; i < n;i++)
    {
        if(Y[i].key==X[0].key)
        {
            break;
        }
    }
    T->lchild = CreateTree(X + 1, Y, i);
    T->rchild = CreateTree(X+i+1,Y+i+1,n-i-1);
    return T;
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
void bt_print(BiTree bt)
{
    column = 0;
    lastColumn = 0;
    depthMax = 0;
    // 根据树的大小申请内存
    depthMax = BitreeDepth(bt);
    width = 3 * ((1 << (depthMax - 1)) * 2 - 1);
    int height = 1 + (depthMax - 1) * 3;
    printBuffer = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++)
    {
        printBuffer[i] = (char *)malloc(width * sizeof(char));
        memset(printBuffer[i], ' ', width);
        printBuffer[i][width - 1] = '\0';
    }

    dep = 0;
    column = width / 2;
    lastColumn = column;
    setPrintBuffer(bt);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%c", printBuffer[i][j]);
        }
        printf("\n");
    }
}
void setPrintBuffer(BiTree t)
{
    if (t)
    {
        dep++;

        TElemType data = t->data;
        printBuffer[(dep - 1) * 3][column - 1] = data.key % 10 + 0x30;
        printBuffer[(dep - 1) * 3][column] = ',';
        strcpy(*(printBuffer + (dep - 1) * 3) + column + 1, data.others);
        if (dep > 1)
        {
            int linkLineInterval = (column - lastColumn) / 3;
            char linkChar = linkLineInterval > 0 ? '\\' : '/';
            printBuffer[(dep - 1) * 3 - 1][column - linkLineInterval] = linkChar;
            printBuffer[(dep - 1) * 3 - 2][column - 2 * linkLineInterval] = linkChar;
        }
        int step = (1 << (depthMax - dep - 1)) * 3;
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
    printf(" %d,%s", T->data.key, T->data.others);
}
int main()
{
    int n;
    TElemType x[100], y[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d,%s", &x[i].key, x[i].others);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d,%s", &y[i].key, y[i].others);
    }
    BiTree T;
    T=CreateTree(x, y, n);
    bt_print(T);
}