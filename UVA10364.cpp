#include<stdio.h>
#include<limits.h>
int los,flag[21],sum,m,max;
int dfs(int arr[], int depth,int left,int now);
int main()
{
    int q;
    scanf("%d", &q);
    while(q){
        int a[21],max=INT_MIN;
        scanf("%d",&m);
        los = 0;
        for (int i = 0; i < m;i++)
        {
            scanf("%d", &a[i]);
            max = max > a[i] ? max : a[i];
            los += a[i];
        }
        if(los%4!=0||max>los/4)
        {
            printf("no");
            continue;
        }
        for (int i = 0; i <= 20;i++){
            flag[i] = 0;
        }
            if (dfs(a, 1, los / 4, 0))
            {
                printf("yes");
            }
            else
                printf("no");
        q--;
    }
}
int dfs(int arr[],int depth,int left,int now)
{
    if(depth==4){
        return 1;
    }
    for (int i = now; i < m;i++)
    {
        if(!flag[i]){
            flag[i] = 1;
            if(arr[i]==left)
            {
                if(dfs(arr,depth+1,los/4,i+1)){
                    return 1;
                }
            }
            else if(arr[i]<left){
                if(dfs(arr,depth,left-arr[i],i+1)){
                    return 1;
                }
            }
            flag[i] = 0;
        }
    }
    return 0;
}