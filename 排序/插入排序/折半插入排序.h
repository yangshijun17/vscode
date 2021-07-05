#include"def.h"
void BInsertSort(SqList &L,int n)
{
    //相对于直接插入排序，仅仅减少了比较的次数，但是没有减少移动的次数
    //时间复杂度为O(n^2)
    for (int i = 2; i < n;i++)
    {
        if(L.elem[i]<L.elem[i-1])
        {
            L.elem[0] = L.elem[i];
            int right, left;
            right = i - 1, left = 0;
            while(left<=right)
            {
                int mid = (right + left) / 2;
                if(L.elem[mid]>L.elem[0])
                    right = mid - 1;
                else
                    left = mid + 1;
            }//只是将查找方式换成了折半查找
            for (int j = i - 1; j >= left;j--)
            {
                L.elem[j + 1] = L.elem[j];
            }
            L.elem[left] = L.elem[0];
        }
    }
}