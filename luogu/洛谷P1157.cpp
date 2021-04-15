#include<stdio.h>
int n, r, a[100];
void combine(int m);
int main()
{
    scanf("%d%d", &n, &r);
    combine(0);
}
void combine(int m){
    if(m==r){
        for (int i = 1; i <=r;i++)
            printf("%d ", a[i]);
        printf("\n");
        return;
    }
    for (int i = a[m] + 1; i <= n;i++){
        a[m+1] = i;
        combine(m + 1);
    }
}