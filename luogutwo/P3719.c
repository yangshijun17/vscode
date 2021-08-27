#include<stdio.h>
int answer();
int main()
{
    printf("%d", answer());
}
int answer()
{
    char c;
    int ans=0;
    while(scanf("%c",&c)!=EOF&&c!='\0'&&c!='\n')
    {
        if(c=='a')
            ans++;
        if(c=='(')
        {
            ans += answer();
        }
        if(c=='|')
        {
            int ans1 = answer();
            ans = ans > ans1 ? ans : ans1;
            return ans;
        }
        if(c==')')
            break;
    }
    return ans;
}