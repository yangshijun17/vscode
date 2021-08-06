//单调栈
#include<stdio.h>
int a[3000000], ans[3000000];
int stack[3000000];
int main()
{
    int n,top=0;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
        scanf("%d", &a[i]);
    for (int i = n; i >= 1;i--)
    {
        while(top!=0)
        {
            if(a[stack[top-1]]>a[i])
                break;
            top--;
        }//弹出所有比当前元素小的，维护栈的单调性
        if(top==0)//当栈中没有元素时
            ans[i] = 0;//说明没有比它大的
        else
            ans[i] = stack[top - 1];//否则有比它大的，即为栈顶元素，同时栈顶元素一定是第一个比它大的，这样维护了栈的单调性
        stack[top++] = i;
    }
    for (int i = 1; i <= n;i++)
    {
        printf("%d ", ans[i]);
    }
}