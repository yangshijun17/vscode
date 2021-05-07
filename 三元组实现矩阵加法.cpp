#include "stdio.h"
#define MAXSIZE 10000
typedef int ElemType;
typedef struct
{
    int m, n; //非零元行、列下标
    ElemType e;
} Triple; //三元组定义
typedef struct
{
    Triple data[MAXSIZE + 1]; //三元组从下标1开始存放
    int mu, nu, tu;           //对于矩阵的行数、列数和非零元素值
} TSMatrix;                   //三元组顺序表的定义
TSMatrix ADD(TSMatrix A, TSMatrix B);
int main()
{
    TSMatrix A[3], B, C;
    int i, j;
    for (i = 0; i < 2; i++)
    {
        scanf("%d%d%d", &A[i].mu, &A[i].nu, &A[i].tu);
        for (j = 1; j <= A[i].tu; j++)
            scanf("%d%d%d", &A[i].data[j].m, &A[i].data[j].n, &A[i].data[j].e);
    }
    A[2] = ADD(A[0], A[1]);
    printf("%d %d %d\n", A[2].mu, A[2].nu, A[2].tu);
    for (i = 1; i <= A[2].tu; i++)
        printf("%d %d %d     ", A[2].data[i].m, A[2].data[i].n, A[2].data[i].e);
    return 1;
}
TSMatrix ADD(TSMatrix A, TSMatrix B)
//返回矩阵A、B相加的结果
{
    /************** begin *****************/
    TSMatrix ans;
    int k=1,i=1,j=1;
    while(i<=A.tu&&j<=B.tu)
    {
        if(A.data[i].m<B.data[j].m)
        {
            while(i<=A.tu&&j<=B.tu&&A.data[i].m<B.data[j].m)
            {ans.data[k] = A.data[i];
            k++;
            i++;
            }
        }
        else if(A.data[i].m>B.data[j].m)
        {
            while(i<=A.tu&&j<=B.tu&&A.data[i].m<B.data[j].m)
            {
                ans.data[k] = B.data[j];
                k++;
                j++;
            }
        }
        else
        {
            if(A.data[i].n<B.data[j].n)
            {
                ans.data[k] = A.data[i];
                k++;
                i++;
            }
            else if(A.data[i].n>B.data[j].n)
            {
                ans.data[k] = B.data[j];
                k++;
                j++;
            }
            else
            {
                if(A.data[i].e+B.data[j].e!=0)
                {
                    ans.data[k] = A.data[i];
                    ans.data[k].e = A.data[i].e + B.data[j].e;
                    k++;
                }
                i++;
                j++;
            }
        }
    }
    if(i<=A.tu)
    {
        while(i<=A.tu)
        {
            ans.data[k] = A.data[i];
            k++;
            i++;
        }
        return;
    }
    else
    {
        while(j<=B.tu)
        {
            ans.data[k] = B.data[j];
            k++;
            j++;
        }
        return;
    }
    ans.mu = A.mu;
    ans.nu = A.nu;
    ans.tu = k - 1;
    /**************  end  *****************/
}