//单调栈和单调队列的不同点在于单调队列的队头有可能会更新
#include <stdio.h>
int a[1000001], que[1000001];
int main()
{
    int n, k, front = 0, rear = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        while (front != rear && a[que[rear - 1]] >= a[i])//维护单调递增队列，队尾出列
            rear--;
        que[rear++] = i;//将当前位置入列
        if (que[front] <= i - k)//判断队头是否过期，将队头出列
            front++;
        if (i < k - 1)//如果没到达k个，则continue
            continue;
        printf("%d ", a[que[front]]);
    }
    printf("\n");
    front = 0;
    rear = 0;
    for (int i = 0; i < n; i++)
    {
        while (front != rear && a[que[rear - 1]] <= a[i])
            rear--;
        que[rear++] = i;
        if (que[front] <= i - k)
            front++;
        if (i < k - 1)
            continue;
        printf("%d ", a[que[front]]);
    }
}