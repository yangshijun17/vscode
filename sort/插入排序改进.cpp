#include<stdio.h>
int n, a[20];
void sort(int a[], int r);//其实就是将二重循环改成递归
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, 0);
    for (int i = 1; i <= n;i++)
    {
        printf("%d ", a[i]);
    }
}
void sort(int a[],int r)
{
    if(r==n+1)
    {
        return;
    }
    int key = a[r];
    int i = r - 1;
    while(i>0&&a[i]>key)
    {
        a[i + 1] = a[i];
        i--;
    }
    a[i+1] = key;
    sort(a, r + 1);
}