#include"def.h"
//选择排序是不稳定的排序算法
//比较次数恒定，交换次数不一定
//时间复杂度为O(n^2)
void SelectSort(SqList &L)
{
    int minnum=0;
    for (int i = 0; i < L.length;i++)
    {
        int min = L.elem[i];
        minnum = i;
        for (int j = i+1; j < L.length;j++)
        {
            if(min>L.elem[j])
            {
                min = L.elem[j];
                minnum = j;
            }
        }
        if(minnum!=i)
        {
            int t = L.elem[i];
            L.elem[i] = L.elem[minnum];
            L.elem[minnum] = t;
        }
    }
}