#include<stdio.h>
#include<math.h>
int n, k, a[21],ans,sum,b[21];
void combine(int now,int now1);
int prime(int m);
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n;i++){
        scanf("%d", &a[i]);
    }
    combine(0,0);
    printf("%d", ans);
}
void combine(int now,int now1)
{
    if(now==k){
        sum = 0;
        for (int i = 1; i <= k;i++){
            sum += b[i];
        }
        if(prime(sum)){
            ans++;
        }
        return;
    }
    for (int i = now1+1 ; i <= n;i++){
        b[now + 1] = a[i];
        combine(now + 1,i);
    }
}
int prime(int m){
    if(m==2){
        return 1;
    }
    if(!(m%2))
        return 0;
    int flag = 1;
    for (int i = 3; i <=sqrt(m);i++){
        if(!(m%i)){
            flag = 0;
            break;
        }
    }
    return flag;
}