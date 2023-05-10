#include<iostream>
using namespace std;

int add(int a,int b)
{
    return a+b;
}

int main(int argc,char **argv)
{
    //int(*p_func)(int,int) =add;
    auto p_func = add;
    cout<< p_func <<endl;
    return 0;
}