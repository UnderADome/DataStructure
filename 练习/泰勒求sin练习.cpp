#include<stdio.h>
#include<windows.h>

double dt(double x,int n)
{
    double i;
    double s=1;
    for(i=1;i<=n;i++)
    {
        s*=x/i;
}

    return s;
}
int main()
{
    double t,x,sum=0;
    int sign=1,i=1;
    scanf("%lf",&x);
    t=dt(x,1);
    while(t>0.000000001)
    {
        sum+=sign*t;
        sign*=-1;
        t=dt(x,2*i+1);
        i++;
    }
    printf("%.100lf\n%d",sum,i);

    system("pause");
    return 0;
}