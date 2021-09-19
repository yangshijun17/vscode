/*
 * @Author: ysj 
 * @Date: 2021-09-16 21:11:33 
 * @Last Modified by: ysj
 * @Last Modified time: 2021-09-16 21:15:22
 */
#include<stdio.h>
int main()
{
	int i;
	for (i = 1; i <= 5;i++)
	{
		int a[5];
		if(i==1)
		{
			a[1] = 0;
			a[2] = 1;
			a[3] = 2;
			a[4] = 3;
			a[0] = -1;
		}
		for (int j = 0; j < 5;j++)
			printf("%d ", a[j]);
		printf("\n");
	}
}