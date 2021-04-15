#include<stdio.h>
int main()
{
    int max1, max2,x;
    scanf("%d", &x);
    max1 = max2 = x;
    while(x)
    {
        scanf("%d", &x);
        if(max1<x)
        {
            max2 = max1;
            max1 = x;
        }
        if(max2<x&&x<max1)
        {
            max2 = x;
        }
    }
    printf("%d", max2);
}