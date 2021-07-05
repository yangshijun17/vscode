#include"def.h"
void InsertSort(SqList &L,int n)
{
    //原数据递增有序的时候达到最优情况，比较次数为n-1次，移动次数为2(n-1)次
    //原数据递减有序的时候达到最坏情况，比较次数为(n-1)(n+2)/2次，移动次数为(n-1)(n+4)/2次
    //平均比较次数为(n-1)(n+4)/4次，平均移动次数为(n-1)(n+8)/4次
    //插入排序是稳定的
    int j;
    for (int i = 2; i < n;i++)
    {
        if(L.elem[i]<L.elem[i-1])//如果当前的元素应该被插入到有序子表中
        {
            L.elem[0] = L.elem[i];//放到监视哨的位置
            L.elem[i] = L.elem[i - 1];//后移开始
            for (j = i - 2;L.elem[j]>L.elem[0];j--)
                L.elem[j + 1] = L.elem[j];//后移
            L.elem[j+1] = L.elem[0];//此处应该是插入到j后
        }
    }
}