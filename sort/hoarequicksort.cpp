#include<stdio.h>
void sort(int a[], int p, int r);
int hoarepatition(int a[], int p, int r);
int main()
{
    int n,a[20];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, 1, n);
    for (int i = 1; i <= n;i++)
    {
        printf("%d ", a[i]);
    }
}
void sort(int a[], int p, int r)
{
    if(p<r)
    {
        int q = hoarepatition(a, p, r);
        sort(a, p, q);
        sort(a, q + 1, r);
    }
}
int hoarepatition(int a[],int p,int r)
{
    int x = a[p];
    int i = p - 1, j = r + 1;
    while(1)
    {
        do{
            j--;
        } while (a[j] > x);
        do{
            i++;
        } while (a[i] < x);
            if (i < j)
            {
                int t;
                t = a[i], a[i] = a[j], a[j] = t;
            }
            else
                return j;
    }
}