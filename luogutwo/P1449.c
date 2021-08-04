#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse(char a[],int length);
char Stack[100000];
int main()
{
    char c;
    int top = 0;
    scanf("%c", &c);
    while(c!='@')
    {
        if((c>47&&c<58)||c=='.')
            Stack[top++] = c;
        else
        {
            char count1[1000], count2[1000];
            memset(count1, 0, sizeof(count1));
            memset(count2, 0, sizeof(count2));
            top--;
            int cnt1=0, cnt2 = 0;
            while(Stack[top-1]!='.'&&top>0)
            {
                count1[cnt1] = Stack[top - 1];
                top--;
                cnt1++;
            }
            top--;
            while(Stack[top-1]!='.'&&top>0)
            {
                count2[cnt2] = Stack[top - 1];
                top--;
                cnt2++;
            }
            reverse(count1, cnt1);
            reverse(count2, cnt2);
            int num1 = atoi(count1);
            int num2 = atoi(count2);
            if(c=='+')
            {
                num2 += num1;
            }
            else if(c=='-')
            {
                num2 -=num1;
            }
            else if(c=='*')
            {
                num2 *= num1;
            }
            else
            {
                num2 /= num1;
            }
            
            char num[10000];
            sprintf(num, "%d", num2);
            for (int k = 0; k < strlen(num);k++)
            {
                Stack[top] = num[k];
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