#include<stdio.h>
#include"function.h"
void merge(int s[], int left, int mid, int right);
void mergesort(int s[], int left, int right);
int main()
{
    int n, x,s[100];
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", &s[i]);
    }
    mergesort(s, 1, n);
    scanf("%d", &x);
    int flag = 0;
    for (int i = 1; i <= n;i++)
    {
        int r = x - s[i], left = i,right=n;
        while(left<right)
        {
            int mid = (left + right) / 2;
            if(s[mid]==r){
                flag = 1;
                break;
            }
            else if(s[mid]>r)
            {
                right = mid-1;
            }
            else
                left = mid+1;
        }
    }
    if(flag)
        printf("yes");
    else
        printf("no");
}