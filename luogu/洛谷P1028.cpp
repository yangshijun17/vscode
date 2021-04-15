#include<stdio.h>
int main()
{
    int n,a[2000];
    scanf("%d", &n);
    a[1] = 1, a[2] = 2;
    int i;
    for (i = 3; i <= n;i++)
    {
        if(!(i%2))
            a[i] = a[i / 2] + a[i - 1];
        else
            a[i] = a[i - 1];
    }
    printf("%d\n", a[n]);
}