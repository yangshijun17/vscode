#include<stdio.h>
#include<limits.h>
void countingsort(int a[], int b[], int k);
int n;
/*计数排序没有采用之前的比较的思路，因此变得非常快，但是缺点在于必须知道输入数的
值域*/
int main()
{
    int max=INT_MIN, a[20],b[20];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
        max = a[i] > max ? a[i] : max;//统计最大值
    }
    countingsort(a, b, max);
    for (int i = 1; i <= n;i++)
    {
        printf(" %d", b[i]);
    }
}
void countingsort(int a[],int b[],int k)
{
    /*其中数组c用来计数，数组b用来存储排序后的列*/
    int c[20];
    for (int i = 0; i <= k;i++)
    {
        c[i] = 0;
    }
    for (int j = 1; j <= n;j++)
    {
        c[a[j]] += 1;//遍历原数组，统计出现次数
    }
    for (int i = 1; i <= k;i++)
    {
        c[i] += c[i - 1];//统计在数组a中为某值前共有多少个
    }
    for (int j = 1; j <= n;j++)
    {
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
}