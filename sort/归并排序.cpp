#include<stdio.h>
#include<limits.h>
void mergesort(int a[], int left, int right);
void merge(int a[], int left,int mid, int right);
int main()
{
    int n, a[100];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    mergesort(a, 1, n);
    for (int i = 1; i <= n;i++)
    {
        printf("%d ", a[i]);
    }
}
void mergesort(int a[],int left,int right)//分治算法
{
    if(left<right)//判断是否分到最优
    {
        int p = (left + right) / 2;//分
        mergesort(a, left, p);//递归对左边进行排序
        mergesort(a, p + 1, right);//递归对右边进行排序
        merge(a, left, p, right);//治，通过设计函数将两段排好序的序列合并到原数组中
    }
}
void merge(int a[],int left,int mid,int right)
{
    int p = mid - left + 1;
    int q = right - mid;
    int l[100], r[100],i,j;
    for (i = 1; i <= p;i++)
        l[i] = a[left + i-1];//将数组a中p的左边的部分赋给l数组
    for (j = 1; j <= q;j++)
        r[j] = a[mid + j];//将数组a中p的右边部分赋给r数组
    i = 1, j = 1;
    l[p + 1] = INT_MAX;//将最后一个元素赋成大值，减少判断次数
    r[q + 1] = INT_MAX;
    for (int k = left; k <= right;k++)
    {
        if(l[i]<=r[j])//用i，j分别记录左右两个数组扫描的位置，一个一个进入数组a
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
    }
}