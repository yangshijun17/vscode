#include "def.h"
//堆排序基于锦标赛排序，锦标赛排序是一种稳定的排序算法，但是耗费空间很大
//堆排序是不稳定的排序算法，时间复杂度为O(nlogn)
typedef SqList HeapType;
void HeapAdjust(HeapType &H, int s, int m)
{
    //参数的意义如下
    //H.elem[s..m]中除了H.elem[s]外满足堆的定义，则调整H.elem[s]使其变为大顶堆
    int x = H.elem[s];
    //2*s代表左孩子，2*s+1代表右孩子
    for (int j = 2 * s; j <= m; j *= 2)
    {
        if (j < m && H.elem[j] < H.elem[j + 1]) //找到两个孩子中较大的结点
            j++;
        if (x >= H.elem[j])//如果已经满足条件，跳出循环
            break;
        else
        {
            H.elem[s] = H.elem[j];//将较大的孩子上移，构成局部大顶堆
            s = j;//让s指向下面这个孩子，继续调整
        }
    }
    H.elem[s] = x;
}
void HeapSort(HeapType &H)
{
    for (int i = H.length / 2; i > 0;i--)
    {
        HeapAdjust(H, i, H.length);//建立大顶堆
    }
    for (int i = H.length; i > 1;i--)
    {
        int t = H.elem[i];
        H.elem[i] = H.elem[0];
        H.elem[0] = t;
        HeapAdjust(H, 1, i - 1);
    }
}