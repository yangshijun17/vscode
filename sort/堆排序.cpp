#include<stdio.h>
#define left(i) (2*i)//求左孩子的编号
#define right(i) (2*i+1)//求右孩子的编号
void swap(int a, int b);//交换函数
void maxheapify(int a[], int i);//维护最大堆性质的函数
void buildmaxheap(int a[]);//给定数组，建立最大堆
void heapsort(int a[]);//堆排序算法
int n;
int main()
{
    int a[20];
    scanf("%d", &n);
    int nn = n;
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    heapsort(a);
    for (int i = 1; i <= nn;i++)
    {
        printf("%d ", a[i]);
    }
}
void swap(int *a, int *b)
{
    int t;
    t = *a, *a = *b, *b = t;
}
void maxheapify(int a[],int i)
{
    /*这段程序主要求parent与left和right位置上最大的数，根据最大堆的性质来进行
    交换*/
    int l = left(i), r = right(i),largest;
    //int largest = -1;
    if(l<=n&&a[l]>a[i])
    {
        largest = l;
    }
    else
        largest = i;
    if(r<=n&&a[r]>a[largest])
    {
        largest = r;
    }
    if(largest!=i)//递归是否进行的条件
    {
        swap(&a[i], &a[largest]);
        maxheapify(a, largest);//递归，判断下一个结点是否满足这一性质
    }
}
void buildmaxheap(int a[])
{
    int i;
    /*这里从n/2开始是因为从这里便不会有叶结点，一定会有堆的存在
    倒着向前推是因为从下往上建立堆可以保证建成最大堆，而且在最初就形成了堆*/
    for (i = n / 2; i >= 1;i--)
    {
        maxheapify(a, i);
    }
}
void heapsort(int a[])
{
    buildmaxheap(a);//建立堆
    //int length = n;
    for (int i = n; i >=2;i--)//从n开始是因为要把当前最大的交换到当前数组的最后
    {
        swap(&a[1], &a[i]);
        n--;//最大元素已经找到，向前推
        maxheapify(a, 1);/*在每一次交换后，堆中实际上拥有的元素减一，重新对
                         堆的性质进行维护，使其再次成为最大堆*/
    }
}