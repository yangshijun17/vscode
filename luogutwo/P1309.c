#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int power;
    int scores;
    int id;
}comp;
comp comps[200020],com,win[100010],lose[100010];
void merge(int n);
int cmp(comp a, comp b);
void mergesort(int left,int right)
{
    if(left==right)
        return;
    int mid = (left + right) / 2;
    mergesort(left, mid);
    mergesort(mid + 1, right);
    int i = left, j = mid + 1, p = left;
    while(i<=mid&&j<=right)
    {
        if(cmp(comps[i],comps[j]))
            lose[p++] = comps[i++];
        else
            lose[p++] = comps[j++];
    }
    while(i<=mid)
        lose[p++] = comps[i++];
    while(j<=right)
        lose[p++] = comps[j++];
    for (int k = left; k <= right;k++)
        comps[k] = lose[k];
}
int main()
{
    int n, r, q,k;
    scanf("%d%d%d", &n, &r, &q);
    for (int i = 1; i <= 2*n;i++)
        scanf("%d",&comps[i].scores);
    for (int i = 1; i <= 2*n;i++)
        scanf("%d", &comps[i].power),comps[i].id=i;
    mergesort(1, 2 * n);
    for (int i = 1; i <= r;i++)
    {
        k = 1;
        for (int j = 1; j <= 2 * n;j+=2)
        {
            if(comps[j].power>comps[j+1].power)
               { comps[j].scores ++;
                   win[k] = comps[j];
                   lose[k] = comps[j + 1];
               }
            else
            {
                comps[j + 1].scores ++;
                win[k] = comps[j + 1];
                lose[k] = comps[j];
            }
            k++;
        }
        merge(n);
    }
    printf("%d", comps[q].id);
}
void merge(int n)
{
    int i = 1, j = 1,k=1;
    while(i<=n&&j<=n)
    {
        if(cmp(win[i],lose[j]))
            comps[k++] = win[i++];
        else
            comps[k++] = lose[j++];
    }
    while(i<=n)
        comps[k++] = win[i++];
    while(j<=n)
        comps[k++] = lose[j++];
}
int cmp(comp a,comp b)
{
    if(a.scores!=b.scores)
        return a.scores > b.scores;
    else
        return a.id < b.id;
}