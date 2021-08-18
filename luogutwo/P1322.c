#include<stdio.h>
#include<math.h>
int ans()
{
    char ch, x,chh[100];
    int num,anss=0;
    while(scanf("%c", &ch)==1&&ch!='\n')
    {
        if(ch==']')
            break;
        scanf("%s", chh);
        scanf("%d", &num);
        if(ch=='R')
        {
            scanf("%c", &x);
            anss += num * ans();
            scanf("%c", &x);
        }
        if(ch=='F')
        {
            anss += num;
            scanf("%c", &x);
        }
        if(ch=='B')
        {
            anss -= num;
            scanf("%c", &x);
        }
        if(x==']'||x=='\n')
            break;
    }
    return anss;
}
int main()
{
    printf("%d", abs(ans()));
    return 0;
}