#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct
{
    char *ch;
    int length;
} HString;
int main()
{
    HString S[3];
    char buf[100], i, j;
    for (i = 0; i < 3; i++)
    {
        fgets(buf, 100, stdin);
        S[i].length = strlen(buf) - 1; //-1是去掉回车符号
        S[i].ch = (char *)malloc(S[i].length);
        for (j = 0; j < S[i].length; j++)
            S[i].ch[j] = *(buf + j);
    }
    Replace(S[0], S[1], S[2]);
    printf("S的长度：%d\n", S[0].length);
    for (i = 0; i < S[0].length; i++)
        putchar(S[0].ch[i]);
    return 1;
}
void Replace(HString &S, HString T, HString V)
//
{
    /************** begin *****************/
    char *ch;
   // ch = strstr(S.ch, T.ch);
    S.ch = (char *)realloc(S.ch, 1000);
    while(1)
    {
        ch = strstr(S.ch, T.ch);
        if(ch==NULL)
        {
            return;
        }
        if(T.length>V.length)
        {
            for (int j = 0; j < T.length - V.length;j++)
            {
                for (int i = ch - S.ch + T.length; i < S.length; i++)
                {
                    S.ch[i] = S.ch[i + 1];
                }
            S.length -= 1;
            }
            for (int i = ch - S.ch; i < ch - S.ch + V.length;i++)
            {
                S.ch[i] = V.ch[i];
            }
        }
        else if(T.length<=V.length)
        {
            for (int j = 0; j < V.length - T.length;j++)
            {
                for (int i = S.length - 1; i > ch - S.ch + T.length;i--)
                {
                    S.ch[i + 1] = S.ch[i];
                }
                S.length++;
            }
            S.ch[S.length] = '\0';
            for (int i = ch - S.ch; i < ch - S.ch + V.length;i++)
            {
                S.ch[i] = V.ch[i];
            }
        }
    }
    /**************  end  *****************/
}