#include <stdio.h>
#include <string.h>
int a[1000010], b[1010][1010], q1[1010], q2[1010], q[1010];
//数组a用来存放最开始的数据，数组b是定义的t个队列，每次入队列时，判断进入哪个队列，数组q用来存储队列中的编号
//数组q1用来存储每个队列队尾的位置，数组q2用来存储每个队列队头的位置
int q1l = 0, q2l = 1;
void mem()
{
    q1l = 0;
    q2l = 1;
    memset(q1, 0, sizeof(q1));
    memset(q2, 0, sizeof(q2));
};
int main()
{
    int t, count = 1;
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
        mem();
        while (1)
        {
            char cmd[20];
            scanf("%s", cmd);
            if (cmd[0] == 'S')
            {
                break;
            }
            else if (cmd[0] == 'E')
            {
                int now, i;
                scanf("%d", &now);
                if (q2[a[now]] == q1[a[now]])//判断第a[now]的队列是否为空
                    q[++q1l] = a[now];//为空的话这里入队
                b[a[now]][++q1[a[now]]] = now;//此时的编号入队
            }
            else
            {
                q2[q[q2l]]++;//q2l记录当前的队头在q中的编号，则q[q2l]队的队头自增
                printf("%d\n", b[q[q2l]][q2[q[q2l]]]);
                if (q2[q[q2l]] == q1[q[q2l]])//如果这里为空的话就可以看q中的下一个了
                    q2l++;
            }
        } //end of while(cmd)
        scanf("%d", &t);
    } //end of big while(t)
}