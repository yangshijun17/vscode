#include <stdio.h>
#include <string.h>
int a[1000005],que[1001];
#define length 1000000
int main()
{
    int t, front = 0, rear = 0, count = 1;
    scanf("%d", &t);
    while (t)
    {
        printf("Scenario #%d\n", count);
        count++;
        for (int i = 1; i <= t; i++)
        {
            int n;
            scanf("%d", &n);
            for (int j = 1; j <= n; j++)
            {
                int num;
                scanf("%d", &num);
                a[num] = i;
            }
        }
        while(1)
        {
            char cmd[20];
            scanf("%s", cmd);
            if(cmd[0]=='S')
            {
                break;
            }
            else if(cmd[0]=='E')
            {
                int now;
                scanf("%d", &now);

            }
        }//end of while(cmd)
    }//end of big while(t)
}