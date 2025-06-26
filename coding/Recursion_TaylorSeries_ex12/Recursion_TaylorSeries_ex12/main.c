#include <stdio.h>
#include <stdlib.h>

//analogy 1
double e(int x,int n)
{
    static double p=1,f=1;
    double r;       //to store result
    
    if(n==0)
    {
        return 1;
    }
    else
    {
        r = e(x,n-1);
        p=p*x;
        f=f*n;
        return r+p/f;
    }
}

//analogy 2
double e1(int x,int n)
{
    static double s=1;
    if(n==0)
        return s;
    else
        s= 1+ x*s/n;
    return e1(x,n-1);
}


//using loop
double e2(int x,int n)
{
    double s1=1;
    for(;n>0;n--)
    {
        s1=1+s1*x/n;
    }
    return s1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("%lf \n",e(1,10));
    printf("%lf \n",e1(1,10));
    printf("%lf \n",e2(1,10));
    return 0;
}
