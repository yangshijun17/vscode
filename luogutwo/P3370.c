//字符串哈希的关键就在于构建一个相应的数字使其和原本的字符串一一对应，这里选择了一个合适的定位
//即将'a'的ASCII值作为基底使得所有字母都与相应的数字对应对应，然后再选择一个合适的进位，将其
//转化成长整数即可，进制要大于所有对应的数字，然后用一个整型数组将其存储就行
//记得数组要开long long，否则有可能会出问题
#include <stdio.h>
#include <string.h>
const long long B = 29; 
long long hashf(char s[]) 
{
   int tmp = 0;
    for (int i = 0; i < strlen(s); i++) 
        tmp = tmp * B + (long long)(s[i]-'a'+1);
    return tmp;
}

int main()
{
    int ans = 1,n;
    long long a[10005];
    char s[10005];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        a[i] = hashf(s);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (a[j+1] > a[j])
            {
                int t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
            ans++;
    }
    printf("%d\n", ans);
}