#include<stdio.h>
#include<limits.h>
int main()
{
    int G[100][100], n,flag[100],length[100],v0,min,nowv;
    printf("Please input the count of the graph'vertices\n");
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            G[i][j] = INT_MAX;
            if(i==j)
            {
                G[i][j] = 0;
            }
        }
    }
    printf("Please input the vertice!\n");
    scanf("%d", &v0);
    printf("Please input the Graph!\n");
    int ii, jj;
    do{
        scanf("%d%d%d", &ii, &jj, &G[ii][jj]);
    } while (ii != -1);
    for (int i = 0; i < n;i++)
    {
        flag[i] = 0;
        length[i] = G[v0][i];
    }
    flag[v0] = 1;
    for (int i = 0; i < n;i++)
    {
        min = INT_MAX;
        for (int j = 0; j < n;j++)
        {
            if(!flag[i]&&length[i]<min)
            {
                min = length[i];
                nowv = i;
            }
        }
        flag[nowv] = 1;
        for (int j = 0; j < n;j++)
        {
            if(length[nowv]+G[nowv][j]<length[j])
            {
                length[j] = length[nowv] + G[nowv][j];
            }
        }
    }

}