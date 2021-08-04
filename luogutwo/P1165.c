#include<stdio.h>
#include<limits.h>
int stack[1000000],max[1000000];
int main()
{
    int n,top=0,weight;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        int opt;
        scanf("%d", &opt);
        if(opt==0)
        {
            scanf("%d", &weight);
            stack[top++] = weight;
            if(top==1)
            {
                max[top-1] = weight;
            }
            if(top>1)
            {
                if(max[top-2]<weight)
                {
                    max[top - 1] = weight;
                }
                else
                    max[top - 1] = max[top - 2];
            }
        }
        if(opt==1)
        {
            top--;
        }
        if(opt==2)
        {
            if(top==0)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", max[top - 1]);
            }
        }
    }
    return 0;
}