#include<stdio.h>
#include<limits.h>
typedef struct Binode
{
    int left, right;
}Binode;
int dfs(Binode tree[],  int now);
int main()
{
    int n;
    scanf("%d", &n);
    Binode tree[1000];
    for (int i = 1; i <= n;i++)
    {
        scanf("%d %d", &tree[i].left, &tree[i].right);
    }
    printf("%d",dfs(tree,1));
}
int dfs(Binode tree[],int now)
{
    if(now==0)
        return 0;
    int right = dfs(tree, tree[now].right);
    int left = dfs(tree, tree[now].left);
    return left > right ? left + 1 : right + 1;
}