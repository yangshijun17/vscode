#include <stdio.h>
void patition(int *a, int n);                     //µ›Õ∆À„∑®
int a[30];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    patition(a, n);
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n / 2; i++)
    {
        sum1 += a[i];
    }
    for (int i = n / 2; i < n; i++)
    {
        sum2 += a[i];
    }
    
    printf("%d %d", sum1, sum2);
}
void patition(int *a, int n)
{
    int low, high, flag = 1, low0, high0, par;
    low = low0 = 0;
    high = high0 = n - 1;
    while (flag)
    {
        int par = a[low];
        while (low < high)
        {
            while (low < high && a[high] >= par)
            {
                high--;
            }
            a[low] = a[high];
            while (low < high && a[low] < par)
            {
                low++;
            }
            a[high] = a[low];
        }
        a[low] = par;
        if (low == n / 2)
        {
            flag = 0;
        }
        else if (low < n / 2)
        {
            low0 = low++;
            high = high0;
        }
        else
        {
            high0 = high--;
            low = low0;
        }
    }
}
