#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    float x[20], y[20],sumx=0,sumy=0,sumxy=0,sumx2=0;
    for (int i = 0; i < n;i++)
    {
        scanf("%f%f", &x[i], &y[i]);
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2 += x[i] * x[i];
    }
    float averx, avery,averxy,averx2;
    averx = sumx / n, avery = sumy / n, averxy = sumxy / n, averx2 = sumx2 / n;
    float a, b;
    b = (averxy - averx * avery) / (averx2 - averx * averx);
    a = avery - b * averx;
    printf("y=%f*x+%f", b, a);
}