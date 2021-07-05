#include"def.h"
//快速排序是一种不稳定的排序算法
//平均时间复杂度为O(nlogn)，但是当序列基本有序时时间复杂度降为O(n^2)
//其前身冒泡排序是一种稳定的排序算法
//由于使用递归，需要一个栈来作辅助空间，最坏情况下栈空间的深度为O(n)
//平均空间复杂度为O(logn)
int Partition(SqList &L, int low, int high);
void QuickSort(SqList &L,int low,int high)
{
    if(high<low)
    {
        return;
    }
    int q = Partition(L, low, high);
    QuickSort(L, low, q - 1);
    QuickSort(L, q + 1, high);
}
int Partition(SqList &L,int low,int high)
{
    L.elem[0] = L.elem[low];
    int x = L.elem[low];
    while(low<high)//左右交替逐渐向中间扫描
    {
        while(low<high&&(L.elem[high]>x||L.elem[high]==x))
            high--;//先从右边开始，只要是大的就一直往前移
        L.elem[low] = L.elem[high];//把比x小的弄到前面
        while(low<high&&(L.elem[low]<x||L.elem[low]==x))
            low++;//再从左边开始，只要是小的就一直往后移
        L.elem[high] = L.elem[low];//把大的再移到后面
    }
    L.elem[low] = x;//此时已经划分好，然后把x放回原位即可
    return low;
}