#include<stdio.h>
int main()
{
    int n,a[100];
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
        scanf("%d", &a[i]);
    int key;
    for (int j = 0; j < n;j++)
    {
        key = a[j];//标记
        int i = j - 1;
        while(i>=0&&a[i]<key)//向前查找知道找到a[i]<=key
        {
            a[i + 1] = a[i];//向后移，为key留位子
            i--;
        }
        a[i + 1] = key;
    }
    for (int i = 0; i < n;i++)
    {
        printf("%d ", a[i]);
    }
}