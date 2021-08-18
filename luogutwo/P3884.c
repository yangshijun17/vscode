//这一题要注意的就是深度和宽度都可以在线处理，宽度可以用类似于bfs的队列处理，也可以开一个数组把所有同深度的储存起来
//要注意二叉树不仅仅只有左孩子和右孩子，结构体中可以加入任意方便做题的数据
//对于该题目中的求距离，实际上就是求最近公共祖先
#include<stdio.h>
typedef struct
{
    int left, right;
    int dept;
    int par;
} BiNode;
BiNode tree[101];
int depth(BiNode T);
int width();
int dis(int root, int u, int v);
int main()
{
    int n,parent,child,maxn=1;
     scanf("%d", &n);
     tree[1].dept = 1;
     tree[1].par = 0;
     for (int i = 1; i < n;i++)
    {
        scanf("%d%d", &parent, &child);
        if(tree[parent].left==0)
            tree[parent].left = child;
        else
            tree[parent].right = child;
        tree[child].par = parent;
        tree[child].dept = tree[parent].dept + 1;
        if(tree[child].dept>maxn)
            maxn=tree[child].dept;
    }
    int node1, node2;
    scanf("%d%d", &node1, &node2);
    int wid = width();
    int fa = dis(1, node1, node2);
    printf("%d\n%d\n", maxn,wid);
    printf("%d",-((tree[fa].dept-tree[node1].dept)*2+tree[fa].dept-tree[node2].dept));
}
int width()
{
    int ans = 0;
    int que[1000], front=0, rear=0,rear1=0;
    que[rear++] = 1;
    rear1++;
    while(front!=rear)
    {
        ans = rear - front > ans ? rear - front : ans;
        rear1 = rear;
        while(front!=rear1)
        {
            int now = que[front];
            front++;
            if(tree[now].left!=0)
                que[rear++] = tree[now].left;
            if(tree[now].right!=0)
                que[rear++] = tree[now].right;
        }
    }
    return ans;
}
int dis(int root,int u,int v)
{
    if(!root||u==root||v==root)
        return root;
    int left = dis(tree[root].left, u, v);
    int right = dis(tree[root].right, u, v);
    if(left==0)
        return right;
    if(right==0)
        return left;
    return root;
}