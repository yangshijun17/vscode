#include <limits.h>
#include <stdio.h>
int main()
{
    printf("Please input the count of the graph's vertices\n");
    int n;
    scanf("%d", &n);
    int v1, v2;
    printf("Please input the shortest walk between v1 and v2 you want\n");
    scanf("%d%d", &v1, &v2);
    printf("Please input the graph and end by -1 -1 -1\n");
    int a[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = INT_MAX;
            if(i==j)
            {
                a[i][j] = 0;
            }
        }
    }
    int ii=0, jj=0;
    do{
        scanf("%d%d%d", &ii, &jj, &a[ii][jj]);
    } while (ii != -1);
    for (int k = 0; k < n;k++)
    {
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < n;j++)
            {
                if(a[i][k]+a[k][j]<a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    printf("The shortest walk between v1 and v2 is %d",a[v1][v2]);
}