#include<stdio.h>
int flag[11][1600],lon[12],n,m;
//lon[i]表示第i层到第i+1层树枝长度，也可以看作记录了根节点的位置
char pri[800][1600];
void Delete(int x, int y);//递归删除结点的函数
void print(int x, int y, int i, int j);
//在（x，y）点上画第i行第j个结点
int main()
{
    int x, y;
    scanf("%d%d", &m, &n);
    memset(pri, ' ', sizeof(pri));//先全部置为空格
    for (int i = 0; i < m;i++)
        for (int j = 1; j <= 1 << i;j++)
            flag[i + 1][j] = 1;//二叉树，这个位置应该有结点
    lon[m - 1] = 1;//m-1到m层距离必然为1
    for (int i = m - 2; i >= 0;i--)
    {
        lon[i] = m - i - 1;
        for (int j = m - 1; j > i;j--)
            lon[i] += lon[j];//根据递推式可以计算出距离
    }
    while(n)
    {
        scanf("%d%d", &x, &y);
        Delete(x, y);//删除n个点
        n--;
    }
    print(1, lon[0] + 1, 1, 1);
    for (int i = 1; i <= lon[0] + 1;i++)
    {
        for (int j = 1; j <= 2 * lon[0] + 1;j++)
            printf("%c", pri[i][j]);
        printf("\n");
    }
}
void Delete(int x,int y)//删除函数，很简单，不多说
{
    flag[x][y] = 0;
    if(x>=m)
        return;
    Delete(x + 1, y * 2 - 1);
    Delete(x + 1, y * 2);
}
void print(int x,int y,int i,int j)
{
    if(flag[i][j])
        pri[x][y] = 'o';//如果i，j没被删，正常赋值
    if(flag[i+1][(j<<1)-1])//左子树
    {
        int ii, jj;
        for (ii = x + 1, jj = y - 1; ii - x <= lon[i];ii++,jj--)
            pri[ii][jj] = '/';//树枝
        print(ii, jj, i + 1,(j << 1)-1);//递归绘制左子树
    }
    if(flag[i+1][j<<1])//同上
    {
        int ii, jj;
        for (ii = x + 1, jj = y + 1; ii - x <= lon[i];ii++,jj++)
            pri[ii][jj] = '\\';//需要双斜线
        print(ii, jj, i + 1, j << 1);
    }
}