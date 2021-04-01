#include<stdio.h>
#include<limits.h>
void insert(int a[], int key);//将key插入到队列中
int maxinum(int a[]);//返回最大优先队列中的最大值
int extract_max(int a[]);//删除队列中的最大值并返回它
void increase_key(int a[], int x, int k);//将元素x的关键字增大到k
void care(int a[], int i);
int length;
int main();
int maxinum(int a[])
{
    return a[1];//已经是最大优先队列，返回首项即可
}
int extract_max(int a[])
{
    if(length<1)
    {
        printf("error!");
        return 0;
    }
    int max = a[1];//第一个最大
    a[1] = a[length];//要将队列整体前移，在此覆盖a[1]
    length -= 1;//长度减一
    care(a, 1);//刚刚的最大值已经删除，队列末元素到达a[1]，所以对堆进行维护
    return max;
}
void increase_key(int a[],int x,int k)
{
    if(k<a[x])
    {
        printf("error!");
        return;
    }
    a[x] = k;//直接进行赋值操作
    while(x>1&&a[x/2]<a[x])//直接与对应的母结点进行比较即可
    {
        int t;
        t = a[x / 2], a[x / 2] = a[x], a[x] = t;//交换位置
        x /= 2;
    }
    /*事实上，上面的循环也可以用care来实现，但是没有这个快*/
}
void insert(int a[],int key)
{
    length += 1;//长度加一
    a[length] = INT_MIN;//赋初值，防止调用函数时报错
    increase_key(a, length, key);//调用函数，将队列末元素值增加到key
}
