#include<stdio.h>
int swap(int *x,int *y)
{   
    int t;
    t=*x;
    *x=*y;
    *y=t;
}

int main()
{
    int a=1,b=5;
    swap(&a,&b);
    printf("%d%d",a,b);
}