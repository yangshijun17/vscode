#include<stdio.h>
void pailie(int now,int now1);
int a[20],n,flag[20],num;
int main()
{
	scanf("%d", &n);
	pailie(0,0);
}
void pailie(int now,int now1)
{
	if(now==n)
	{
		for (int i = 0; i < n;i++)
			printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (int i = now1+1; i <= n;i++)
	{
		//if(!flag[i]){
			//flag[i] = 1;
			a[now] = i;
			//num++;
			pailie(now + 1,i);
			//num--;
			//flag[i] = 0;
//}
	}
}