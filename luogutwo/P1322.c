#include<stdio.h>
#include<math.h>
int ans()
{
    char ch, x,chh[10];
    int num,anss=0;
    while(1)
    {
        scanf("%c", &ch);
        if(ch==']'||ch=='\n')
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