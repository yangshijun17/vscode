#include<stdio.h>
int main()
{
    char ch;
    int num11=0, num12=0;
    int num21 = 0, num22 = 0,num=0;
    char score2[5000][10];
    while(1)
    {
        scanf("%c", &ch);
        if(ch=='\n')
            continue;
        else if(ch=='W')
            num11++,num21++;
        else if(ch=='L')
            num12++,num22++;
        else if(ch=='E')
            break;
        if(num11>=11&&num11-num12>=2)
        {
            printf("%d:%d\n",num11,num12);
            num11 = 0;
            num12 = 0;
        }
        if(num12>=11&&num12-num11>=2)
        {
            printf("%d:%d\n",num11,num12);
            num11 = 0;
            num12 = 0;
        }
        if(num21>=21&&num21-num22>=2)
        {
            score2[num][0] = num21/10+'0', score2[num][1] = num21%10+'0', score2[num][2] = ':';
            if(num22/10==0)
                score2[num][3] = num22+'0';
            else
                score2[num][3] = num22 / 10 + '0', score2[num][4] = num22 % 10 + '0';
            num21 = 0;
            num22 = 0;
            num++;
        }
        if(num22>=21&&num22-num21>=2)
        {
            if(num21/10==0)
                score2[num][0] = num21+'0',score2[num][1] = ':', score2[num][2] = num22 / 10 + '0', score2[num][3] = num22 % 10 + '0';
            else
                score2[num][0] = num21 / 10 + '0', score2[num][1] = num21 % 10 + '0',score2[num][2] = ':', score2[num][3] = num22 / 10 + '0', score2[num][4] = num22 % 10 + '0';
            num21 = 0;
            num22 = 0;
            num++;
        }

    }
    printf("%d:%d",num11,num12);
    printf("\n");
    for (int i = 0; i < num;i++)
    {
        printf("%s\n", score2[i]);
    }
    printf("%d:%d\n", num21, num22);
}