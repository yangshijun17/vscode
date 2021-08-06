//KMP算法
//这次超时的原因主要就在于，调用了太多次strlen()函数求串长，其实仅仅调用一次就可以了
#include<stdio.h>
#include<string.h>
char s1[1000002], s2[1000002];
int next[1000002];
int main()
{
    scanf("%s", s1);
    scanf("%s", s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    next[0] = -1;
    int j = 0, k = -1;
    while(j<len2)
    {
        if(k==-1||s2[j]==s2[k])//相等的这段代码是非常好理解的
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];//如果不相等只能从k前面的那一段去找,因为当前出现不相等的当前位置前的一段满足最长相等的前缀和后缀
            //同时他也具有最长的前缀和后缀，所以需要从前面的最长去找
    }
    j = 0;
    int i = 0;//i,j作为两个指针
    while(i<len1)
    {
        if(j==-1||s1[i]==s2[j])//如果相等就自增
        {
            i++, j++;
        }
        else
        {
            j = next[j];//否则j指针移到前缀和后缀相同的位置
        }
        if(j==len2)
            {
                printf("%d\n",i-len2+1);
                j = next[j];
            }
    }
    for (int i = 1; i <= len2;i++)
    {
        printf("%d ", next[i]);
    }
}