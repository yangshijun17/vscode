#include "def.h"
//希尔排序是一种不稳定的插入排序
void ShellInsert(SqList &L, int dk);
void ShellSort(SqList &L, int dk[], int t)
{
    for (int k = 0; k < t; k++)
        ShellInsert(L, dk[k]);//根据增量序列，调用函数进行一趟希尔排序
}
void ShellInsert(SqList &L, int dk)
{
    for (int i = dk + 1; i < L.length; i++)//每一组之间进行插入排序
    {
        if (L.elem[i] < L.elem[i - dk])
        {
            L.elem[0] = L.elem[i];
            int j;
            for (j = i - dk; j > 0 && L.elem[0] < L.elem[j]; j -= dk)
                L.elem[j + dk] = L.elem[j];
            L.elem[j + dk] = L.elem[0];
        }
    }
}