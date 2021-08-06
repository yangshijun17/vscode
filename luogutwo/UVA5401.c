//这道题很关键的一个思路突破口就是它给出了成员编号的范围，否则时间复杂度过高，要考虑的东西太多
//该代码有bug
#include <stdio.h>
#include <string.h>
int a[1000000];
#define length 1000000
int main()
{
    int t, front = 0, rear = 0, count = 1,que[10000];
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
        while (1)
        {
            char command[20];
            scanf("%s", command);
            if (command[0]=='S')
                break;
            else if (command[0]=='E')
            {
                int now;
                scanf("%d", &now);
                int flag = 0;
                if (rear == front)
                {
                    que[front] = now;
                    rear = (rear + 1) % length;
                }
                else if (rear < front)
                {
                    int i;
                    for (i = rear - 1; i >= 0; i--)
                    {
                        if (a[que[i]] == a[now])
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag)
                    {
                        for (int j = rear; j > i + 1; j--)
                        {
                            que[j] = que[j - 1];
                        }
                        que[i + 1] = now;
                        rear = (rear + 1) % length;
                    }
                    else
                    {
                        for (i = length; i >= front; i--)
                        {
                            if (a[que[i]] == a[now])
                            {
                                flag = 2;
                                break;
                            }
                        }
                    }
                    if (flag == 1)
                    {
                        que[rear] = now;
                        rear = (rear + 1) % length;
                    }
                    else
                    {
                        for (int j = rear; j > 0; j--)
                        {
                            que[j] = que[j - 1];
                        }
                        que[0] = que[length];
                        for (int j = length; j > i + 1; j--)
                        {
                            que[j] = que[j - 1];
                        }
                        que[i + 1] = now;
                        rear = (rear + 1) % length;
                    }
                }
                else
                {
                    int i, flag = 0;
                    for (i = rear-1; i >= front; i--)
                    {
                        if (a[que[i]] == a[now])
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag)
                    {
                        for (int j = rear; j > i + 1; j--)
                        {
                            que[j] = que[j - 1];
                        }
                        que[i + 1] = now;
                        rear = (rear + 1) % length;
                    }
                    else
                    {
                        que[rear] = now;
                        rear = (rear + 1) % length;
                    }
                }
            }
            else
            {
                printf("%d\n", que[front]);
                front = (front + 1) % length;
            }
        }
        printf("\n\n");
        scanf("%d", &t);
    }
}