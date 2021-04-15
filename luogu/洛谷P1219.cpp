#include<stdio.h>
int flagcon[20],ans,a[20],ans1,flagsl1[50],flagsl2[50];
//这几个flag开头的数组表示是否能上皇后，1为可以，0为不可以
void dfs(int row,int n);
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n;i++){
        flagcon[i] = 1;
    }
    for (i = 0; i < 2 * n;i++){
        flagsl2[i] = flagsl1[i] = 1;
    }//先将最开始的第一个皇后放在第一排，然后更新一下周围的数据，接下来开始递归求解
        dfs(0, n);
    printf("%d",ans);
}
void dfs(int row,int n)//n为棋盘规格，row为第row排放皇后
{
    if(row==n)//结束条件与输出
    {
        ans++;
        if(ans1==3)
        {
            return;
        }
        int i;
        for (i = 0; i < row;i++)
        {
            printf("%d ", a[i]+1);
        }
        printf("\n");
        ans1++;
        return;
    }
    for (int col = 0; col < n;col++){
        if(flagcon[col]&&flagsl1[col+row]&&flagsl2[row-col+n-1])//是否可以放
        {
            a[row] = col;//放进去
            flagcon[col] = flagsl1[col+row] = flagsl2[row-col+n-1] = 0;//标记为不可以，仅针对下一行
            dfs(row + 1,n);//递归求下一个
            flagcon[col] = flagsl1[col+row] = flagsl2[row-col+n-1] = 1;//回溯
        }
    }
}