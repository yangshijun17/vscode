/*#include <stdio.h>
void patition(int *a, int n);                     //递推算法
void patition2(int n, int low, int high); //递归算法
int a[30];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    patition2(n, 0, n - 1);
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
}*/
/*void patition(int *a, int n)
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
}*/
/*void patition2(int n, int low, int high)
{
    if(low>high)
    {
        return;
    }
    int low0 = low;
    int high0 = high;
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
        return;
    }
    patition2(n, low0, low - 1);
    patition2(n, low + 1, high0);
}*/
#include<stdio.h> 
void partition(int a[],int low,int high,int n){
	int pivot=a[low];
	int temp_low=low;
	int temp_high=high;
	while(low<high){
		while(low<high&&pivot<=a[high])--high;
		a[low]=a[high];
		while(low<high&&pivot>a[low])++low;
		a[high]=a[low];
	}
	a[low]=pivot;
	
	if(low==n/2)//找到n/2号元素 
	return;
	partition(a,temp_low,low-1,n);
	partition(a,low+1,temp_high,n);
	
}
int main(){
	int a[]={25,42,1,42,42,68,79,59,63,65};
	partition(a,0,9,10);
	int i,s1=0,s2=0;
	for(i=0;i<5;i++)
		s1+=a[i];
	for(i=5;i<10;i++)
		s2+=a[i];
	printf("%d\n",s2-s1);
	printf("%d\n",s2);
}