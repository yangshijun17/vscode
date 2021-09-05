#include<stdio.h>
#define f(x) (a*(x)*(x)*(x)+b*(x)*(x)+c*(x)+d)
#define abs(x) (x>0?x:-x)
double a, b, c, d;
void ans(double left,double right);
int main()
{
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    for (int i = -100; i < 100;i++)
    {
        ans(i, i + 1);
    }
}
void ans(double left,double right)
{
    if(f(left)*f(right)<=0)
    {
        double mid = (left + right) / 2;
        if(abs(f(mid))<0.0000001)
        {
            printf("%.2lf ", mid);
            return;
        }
        if(f(left)*f(mid)<0)
        {
            ans(left, mid);
        }
        else
            ans(mid, right);
    }
}