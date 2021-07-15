#include <stdio.h>
void reverse(char a[], int length);
int main()
{
    char count1[100], count2[100], c,str[1000];
    int cnt1 = 0, cnt2 = 0, flag = 0,cnt=0;
    scanf("%s", str);
    while (str[cnt] != '\0')
    {
        if (flag == 0 && str[cnt] != '.' && str[cnt] != '/' && str[cnt] != '%')
            count1[cnt1++] = str[cnt];
        if (str[cnt] == '.')
        {
            flag = 1;
            cnt++;
            continue;
        }
        if (str[cnt] == '/')
        {
            flag = 2;
            cnt++;
            continue;
        }
        if (str[cnt] == '%')
        {
            flag = 3;
            cnt++;
            continue;
        }
        if (flag)
            count2[cnt2++] = str[cnt];
        cnt++;
    }
    switch (flag)
    {
    case 0:
    {
        int j;
        for (j = cnt1 - 1; j > -1 && count1[j] == '0'; j--, cnt1--)
            ;
        if(j==-1)
            count1[cnt1] = '0',count1[cnt1+1]='\0';
        else count1[cnt1] = '\0';
        reverse(count1, cnt1);
        printf("%s", count1);
        break;
    }
    case 1:
    {
        int j;
        for (j = cnt1 - 1; j > -1 && count1[j] == '0'; j--, cnt1--)
            ;
        if(j==-1)
            count1[cnt1] = '0',count1[cnt1+1]='\0';
        else count1[cnt1] = '\0';
        reverse(count1, cnt1);
        reverse(count2, cnt2);
        for (int j = cnt2 - 1; j > -1 && count2[j] == '0'; j--, cnt2--)
            ;
        count2[cnt2] = '\0';
        if (cnt2 == 0)
        {
            printf("%s", count1);
            printf(".0");
        }
        else
            printf("%s.%s", count1, count2);
        break;
    }
    case 2:
    {
        int j;
        for (j = cnt1 - 1; j > -1 && count1[j] == '0'; j--, cnt1--)
            ;
        if(j==-1)
            count1[cnt1] = '0',count1[cnt1+1]='\0';
        else count1[cnt1] = '\0';
        reverse(count1, cnt1);
        for (int j = cnt2 - 1; j > -1 && count2[j] == '0'; j--, cnt2--)
            ;
        count2[cnt2] = '\0';
        reverse(count2, cnt2);
        printf("%s/%s", count1, count2);
        break;
    }
    case 3:
    {
        int j;
        for (j = cnt1 - 1; j > -1 && count1[j] == '0'; j--, cnt1--)
            ;
        if(j==-1)
            count1[cnt1] = '0',count1[cnt1+1]='\0';
        else count1[cnt1] = '\0';
        reverse(count1, cnt1);
        printf("%s", count1);
        printf("%%");
        break;
    }
    }
    return 1;
}
void reverse(char a[], int length)
{
    char c;
    for (int i = 0; i < length / 2; i++)
    {
        c = a[i];
        a[i] = a[length - 1 - i];
        a[length - 1 - i] = c;
    }
}