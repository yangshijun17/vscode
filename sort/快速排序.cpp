#include<stdio.h>
void quicksort(int a[], int p, int r);
int partition(int a[], int p, int r);
int n;
int main()
{
    int a[20];
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
    int x = a[r];
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
    int t;
    t = a[i + 1], a[i + 1] = a[r],a[r]=t;
    for (int i = 1; i <= n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return i + 1;
}