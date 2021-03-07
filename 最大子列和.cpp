#include<stdio.h>
#include<limits.h>
#define max(a,b,c) a>b?(a>c?a:c):(b>c?b:c)
#define min(a,b) a>b?b:a
void fun1(int arr[], int n);
void fun2(int arr[], int n);
int fun3(int arr[], int left,int right);
void fun4(int arr[], int n);
int main()
{
    int n, i, a[20];
    scanf("%d", &n);
    for (i = 0; i < n;i++)
        scanf("%d", &a[i]);
    fun1(a, n);
    fun2(a, n);
    printf("program3:%d\n", fun3(a,0,n-1));
    fun4(a, n);
}
void fun1(int arr[],int n)
{
    /*暴力算法，时间复杂度较高,为O（n^3）*/
    int i, j, k;
    int Thissum, maxsum=INT_MIN;
    for (i = 0; i < n;i++){
        for (j = i+1; j < n;j++){
            Thissum = 0;
            for (k = i; k < j;k++){//仅仅只是简单遍历而已，求从i到j这一子列的和
                Thissum += arr[k];
            }
            if(Thissum>maxsum){
                maxsum = Thissum;
            }
        }
    }
    printf("program1:%d\n", maxsum);
}
void fun2(int arr[],int n)
{
    //简单优化，时间复杂度为O（n^2)
    int i, j;
    int Thissum, maxsum=INT_MIN;
    for (i = 0; i < n;i++){
        Thissum = 0;
        for (j = i; j < n;j++){
            Thissum += arr[j];//在第二次便利的过程中判断并更新maxsum，减少一重循环
            if(Thissum>maxsum){//仍然是从i到j，只是中间加了一个更新的过程
                maxsum = Thissum;
            }
        }
    }
    printf("program2:%d\n",maxsum);
}
int fun3(int arr[],int left,int right)
{
    //分治算法，时间复杂度为O（nlogn）
    if(left==right){//递归终止
        if(arr[left]>0)
            return arr[left];
        else
            return 0;
    }
    int mid = (left + right) / 2;
    int maxleft, maxright,i;
    maxleft = fun3(arr, left, mid);//递归求左边的最大和
    maxright = fun3(arr, mid + 1, right);//递归求右边的最大和
    /*以下求跨过分界线的最大和*/
    int thismaxleft=0, thismaxright=0, maxnleft=INT_MIN, maxnright=INT_MIN;
    for (i = mid; i >= left;i--){
        thismaxleft +=arr[i];
        if(thismaxleft>maxnleft){
            maxnleft = thismaxleft;
        }
    }
    for (i = mid + 1; i <= right;i++)
    {
        thismaxright += arr[i];
        if(thismaxright>maxnright)
        {
            maxnright = thismaxright;
        }
    }
    return max(maxleft, maxright, (maxnright + maxnleft));
}
void fun4(int arr[],int n)
{
    //在线处理，时间复杂度最小，为O（n），但要想看懂就略显复杂
    int i;
    int Thissum=0, maxsum = INT_MIN;
    for (i = 0; i < n;i++)
    {
        Thissum += arr[i];//直接加当前元素
        if(Thissum>maxsum){//更新
            maxsum = Thissum;
        }
        else if(Thissum<0){
            Thissum = 0;//更新求和起点
        }
    }
    printf("program4:%d\n",maxsum);
}