#include<iostream>

using namespace std;

void swap(int &a,int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

int main(int argc,char **argv)
{
    //引用：起别名
    //作用：传参（传值和传地址的问题）和返回值（函数调用作为左值）
    //常引用：const 能绑定常量
    //引用和指针的区别：效率/安全性/内存大小/注意事项
    //指针和数组的区别：空间分配方式/访问效率/安全性/传参/指针常量

    int num =5;
    int &l_num = num;
    int &l_num2 = num;
    l_num++;
    num++;
    cout<<l_num<<endl;
    cout<<num<<endl;

    int a = 5;
    int b = 6;
    swap(a,b);

    cout <<"a= "<< a <<"b= "<< b <<endl;
}