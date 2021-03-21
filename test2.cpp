#include<stdio.h>
#define N 1000
int main()
{
int i,j,a[N][N],b[N][N],c[N][N],s=0,k,e[N][N],m,n;
//printf("请输入你的关系矩阵的阶n(n<=1000):\n");
scanf("%d",&n);
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
e[i][j]=a[i][j];
b[i][j]=a[i][j];
}
for(m=1;m<n;m++)
{
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
for(s=0,k=0;k<n;k++)
s+=b[i][k]*a[k][j];
c[i][j]=s;
if(e[i][j]==0&&c[i][j]!=0)
e[i][j]=c[i][j];
}
for(i=0;i<n;i++)
for(j=0;j<n;j++)
b[i][j]=c[i][j];
}
for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(e[i][j]!=0)
printf("<%d,%d>,",i+1,j+1);
printf("\n");
}