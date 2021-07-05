#include"def.h"
void TInsertSort(SqList &L,int n)
{
    //相对于直接插入排序，没有减少比较的次数，而减少的移动的次数
    //时间复杂度为O(n^2)，移动次数约为n^2/8
    int temp[n];
    int first=0, final=0;//分别指示最小值位置和最大值位置，类似于循环队列
    temp[0] = L.elem[0];//将第一个赋进去
    for (int i = 1; i < n;i++)
    {
        //比最小值小
        if(L.elem[i]<temp[first])
        {
            first = (first - 1 + n) % n;
            temp[first] = L.elem[i];
        }
        //比最大值大
        else if(L.elem[i]>temp[final])
        {
            final = (final + 1 + n) % n;
            temp[final] = L.elem[i];
        }
        //介于最大值和最小值之间
        else
        {
            int k = (final + 1 + n) % n;//移动temp数组中的元素
            while(temp[(k-1+n)%n]>L.elem[i])
            {
                temp[(k + n) % n] = temp[(k - 1 + n) % n];
                k = (k - 1 + n) % n;
            }
            temp[(k + n) % n] = L.elem[i];
            final = (final + 1 + n) % n;//更新最大值所在的位置
        }
    }
    for (int i = 0; i < n;i++)//复制回原数组
    {
        L.elem[i] = temp[i];
    }
}