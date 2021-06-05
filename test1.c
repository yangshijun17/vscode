#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int p=1;
    while(n)
    {
        p *= n;
        n--;
    }
    printf("%d", p);
}