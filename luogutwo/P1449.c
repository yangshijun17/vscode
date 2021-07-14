#include<stdio.h>
#include<stdlib.h>
void reverse(char a[],int length);
int main()
{
    char c,Stack[1000];
    int top = 0;
    scanf("%c", &c);
    while(c!='@')
    {
        if((c>47&&c<58)||c=='.')
            Stack[top++] = c;
        else
        {
            char count1[1000], count2[1000];
            top--;
            int cnt1=0, cnt2 = 0;
            while(Stack[top-1]!='.')
            {
                count1[cnt1] = Stack[top - 1];
                top--;
                cnt1++;
            }
            top--;
            while(Stack[top-1]!='.')
            {
                count2[cnt2] = Stack[top - 1];
                top--;
                cnt2++;
            }
            reverse(count1, cnt1);
            reverse(count2, cnt2);
            for (int i = 0; i < cnt1 && i < cnt2;i++)
            {
                if(count1[i]+count2[i]-96>9)
                {
                    count1[i] = count1[i] + count2[i]-58;
                    count1[i + 1] += 1;
                    if(i==cnt1-1)
                        cnt1++;
                }
                else
                    count1[i] += count2[i] - 48;
            }
            if(cnt2>cnt1)
            {
                for (int i = cnt1; i < cnt2;i++)
                {
                    count1[i] = count2[i];
                }
                cnt1 = cnt2;
            }
            for (int i = 0; i < cnt1;i++)
            {
                Stack[top] = count1[i];
                top++;
            }
            Stack[top] = '.';
            top++;
        }
        scanf("%c", &c);
    }
    top--;
    Stack[top] = '\0';
    printf("%s", Stack);
}
void reverse(char a[],int length)
{
    char c;
    for (int i = 0; i < length/2;i++)
    {
        c = a[i];
        a[i] = a[length - 1 - i];
        a[length - 1 - i] = c;
    }
}