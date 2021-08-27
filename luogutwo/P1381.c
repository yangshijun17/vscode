#include <limits.h>
#include <stdio.h>
#include <string.h>
char words[1005][11], s[11];
void sort(int left, int right);
int bsearch(int left, int right);
int partition(int left, int right);
int main()
{
int pos[10001], que[10001], flag[1005];
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", words[i]);
    }
    sort(1, n);
    int front = 0, rear = 0;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", s);
        int ps = bsearch(1, n);
        if (strcmp(words[ps], s) == 0)
            pos[i] = ps;
    }
    int minl = 0, maxnum = 0;
    flag[0] = 10000000;
    for (int i = 1; i <= m; i++)
    {
        int flag1 = 0;
        if (!flag[pos[i]])
            maxnum++, flag1 = 1;
        flag[pos[i]]++;
        que[rear++] = i;
        while (flag[pos[que[front]]] > 1 && front != rear)
        {
            flag[pos[que[front]]]--;
            front++;
        }
        if (flag1)
            minl = rear - front;
        else
            minl = minl > rear - front ? rear - front : minl;
    }
    printf("%d\n%d", maxnum, minl);
}
int bsearch(int left, int right)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (strcmp(words[mid], s) >= 0)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return strcmp(s,words[left])<=0?left:left+1;
}
void sort(int left, int right)
{
    if (left > right)
        return;
    int q = partition(left, right);
    sort(left, q - 1);
    sort(q + 1, right);
}
int partition(int left, int right)
{
    strcpy(words[0], words[left]);
    while (left < right)
    {
        while (left < right && strcmp(words[right], words[0]) >= 0)
            right--;
        strcpy(words[left], words[right]);
        while (left < right && strcmp(words[left], words[0]) <= 0)
            left++;
        strcpy(words[right], words[left]);
    }
    strcpy(words[left], words[0]);
    return left;
}