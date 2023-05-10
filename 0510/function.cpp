#include<iostream>
using namespace std;

//内联函数的作用：内存空间换运行时间，编译时间换内存空间 宏函数
inline int add(int a,int b)
{
    return a+b;
}

//函数重载 ：可以用相同的函数名定义函数 但是必须保证函数的形参类型或者参数个数不同
//函数形参可以有默认值：默认值可能会影响重载条件；默认值右边的形参必须全部为默认值
int main(int argc,char **argv)
{
    //1.通过函数名找到函数入口地址
    //2.给形参分配空间；
    //3.将实参的值传递形参
    //4.执行函数体语句
    //5.
    
    add(5,6);
    return 0;
}