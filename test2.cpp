#include<stdio.h>
void build(int a[]);
void care(int a[],int i);
void sort(int a[]);
int n;
int main()
{
	int a[20];
	scanf("%d", &n);
	for (int i = 1; i <= n;i++)
	{
		scanf("%d", &a[i]);
	}
	int nn = n;
	sort(a);
	for (int i = 1; i <= nn;i++)
	{
		printf("%d ", a[i]);
	}
}
void care(int a[],int i)
{
	int left = 2 * i;
	int right = 2 * i + 1;
	int max = -1;
	if(left<=n&&a[i]<a[left])
	{
		max = left;
	}
	else
		max = i;
	if(right<=n&&a[max]<a[right])
	{
		max = right;
	}
	if(max!=i)
	{
		int j;
		j = a[max], a[max] = a[i], a[i] = j;
		care(a, max);
	}
}
void build(int a[])
{
	for (int i = n / 2; i >= 1;i--)
	{
		care(a, i);
	}
}
void sort(int a[])
{
	build(a);
	for (int i = n; i >= 2;i--)
	{
		int t;
		t = a[1], a[1] = a[i], a[i] = t;
		n--;
		care(a, 1);
	}
}