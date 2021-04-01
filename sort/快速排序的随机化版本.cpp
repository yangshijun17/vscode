#include<stdio.h>
#include<time.h>
#include<limits.h>
#include<stdlib.h>
void quicksort(int a[], int p, int r);
int partition(int a[], int p, int r);
int main()
{
    int n, a[20];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 1, n);
    for (int i = 1; i <= n;i++)
    {
        printf("%d ", a[i]);
    }
}
void quicksort(int a[],int p,int r)
{
    if(p<r)
    {
        int q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q + 1, r);
    }
}
int partition(int a[],int p,int r)
{
    int t = rand() % (r- p+1) + p;
    int x;
    x = a[t], a[t] = a[r], a[r] = x;
    int i = p - 1;
    for (int j = p; j < r;j++)
    {
        if(a[j]>=x)
        {
            i++;
            int t;
            t = a[i], a[i] = a[j], a[j] = t;
        }
    }
    //int t;
    t = a[i + 1], a[i + 1] = a[r],a[r]=t;
    return i+1;
}