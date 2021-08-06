#include<stdio.h>
int main()
{
    long long numstack[100000],num;
    char ch;
    int topnum = 0;
    scanf("%lld", &num);
    numstack[topnum++] = num;
    while(1)
    {
        scanf("%c", &ch);
        if(ch=='\n')
            break;
        if(ch=='+')
        {
            scanf("%lld", &num);
            numstack[topnum++] = num;
            continue;
        }
        if(ch=='*')
        {
            scanf("%lld", &num);
            long long numn;
            numn = numstack[topnum - 1];
            topnum--;
            numn = (numn * num) % 10000;
            numstack[topnum++] = numn;
        }
    }
    int ans = 0;
    for (int i = 0; i < topnum;i++)
    {
        ans = (ans + numstack[i] % 10000) % 10000;
    }
    printf("%d", ans);
}